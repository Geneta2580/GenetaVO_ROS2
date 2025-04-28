#include "slam_core.h"

SLAM_Core::SLAM_Core() : Node("geneta_slam") { // 节点名需要cmake文件中add_executable保持一致 
    // 订阅图像话题（需与发布者一致，话题名称一致）
    left_sub_.subscribe(this, "Geneta_Image_left");
    right_sub_.subscribe(this, "Geneta_Image_right");

    // 同步器初始化（ROS2必须显式构造）
    sync_.reset(new message_filters::Synchronizer<SyncPolicy>(
        SyncPolicy(10),  // 队列长度参数
        left_sub_, 
        right_sub_
    ));

    // 注册回调（使用std::placeholders占位符）
    sync_->registerCallback(
        std::bind(&SLAM_Core::stereo_callback, this,
            std::placeholders::_1, 
            std::placeholders::_2
        )
    );

    // 初始化
    if (!Init()) {
        RCLCPP_ERROR(get_logger(), "SLAM_CORE节点初始化失败,关闭节点");
        rclcpp::shutdown();
    }

    // 发布位姿及地图点话题（需与发布者一致，话题名称一致），tf2广播
    pose_pub_ = this->create_publisher<nav_msgs::msg::Odometry>("geneta_odom", 10);
    map_pub_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("geneta_map", 10);
    tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);
}

bool SLAM_Core::Init() {
    // 设置配置文件路径
    const std::string config_file_path_ = "/home/geneta/Project/geneta_slam/config/config.yaml"; 
    if (Config::SetParameterFile(config_file_path_) == false) {
        return false;
    }

    // 设置数据集的config文件路径
    dataset_ = Dataset::Ptr(new Dataset(Config::Get<std::string>("dataset_dir")));
    if(!dataset_->Init()) {
        return false;
    }

    map_ = Map::Ptr(new Map); // 创建地图
    frontend_ = Frontend::Ptr(new Frontend); // 创建前端
    backend_ = Backend::Ptr(new Backend); // 创建后端
    // viewer_ = Viewer::Ptr(new Viewer); // 创建可视化界面

    frontend_->SetCameras(dataset_->GetCamera(0), dataset_->GetCamera(1)); // 读取初始化数据
    frontend_->SetMap(map_);
    frontend_->SetBackend(backend_); // 两线程互联
    // frontend_->SetViewer(viewer_);

    // viewer_->SetMap(map_);
    return true;
}

void SLAM_Core::stereo_callback(const sensor_msgs::msg::Image::ConstSharedPtr& left_msg,
    const sensor_msgs::msg::Image::ConstSharedPtr& right_msg) {
    try {
        // 时间戳一致性检查
        if (abs(left_msg->header.stamp.sec - right_msg->header.stamp.sec) > 0.001) {
            RCLCPP_WARN(get_logger(), "双目时间戳差异超过1ms");
            return;
        }

        // 双图像转换
        cv_bridge::CvImagePtr left_cv = cv_bridge::toCvCopy(left_msg, "bgr8");
        cv_bridge::CvImagePtr right_cv = cv_bridge::toCvCopy(right_msg, "bgr8");

        // 灰度化处理
        cv::Mat left_gray, right_gray;
        cv::cvtColor(left_cv->image, left_gray, cv::COLOR_BGR2GRAY);
        cv::cvtColor(right_cv->image, right_gray, cv::COLOR_BGR2GRAY);
        
        // 帧数据加载
        Frame::Ptr frame = dataset_->loadNextFrame(left_gray, right_gray);
        auto t1 = std::chrono::steady_clock::now(); // 算法计时 
        frontend_->Calculate(frame);
        auto t2 = std::chrono::steady_clock::now();
        auto time_used = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
        std::cout << "GenetaSLAM Frontend cost time: " << time_used.count() << " seconds." << std::endl;
        
        // 封装为rviz2消息并发布
        odom_msg_ = frontend_->odom_msg_; // 节点内前端线程赋值给节点，Odometry
        odom_msg_->header.stamp = this->get_clock()->now(); // 转换为Odometry消息
        odom_msg_->header.frame_id = "odom";
        odom_msg_->child_frame_id = "base_link";

        transform = frontend_->transform;
        transform.header.stamp = this->now();     // tf2
        transform.header.frame_id = "odom";       // 父坐标系
        transform.child_frame_id = "base_link";    // 子坐标系

        pose_pub_->publish(*odom_msg_); // 发布odom
        tf_broadcaster_->sendTransform(transform); // 发布tf2
        // backend_->Wake();

    } catch (const cv_bridge::Exception& e) {
        RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
    }
}

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SLAM_Core>());
    rclcpp::shutdown();
    return 0;
}