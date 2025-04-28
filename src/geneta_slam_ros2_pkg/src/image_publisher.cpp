#include "image_publisher.h"
namespace fs = std::filesystem;

/*
创建一个读取图像节点，初始化时输出"Start collect images"日志
​​*/
ImagePublisher::ImagePublisher() : Node("image_publisher") {
    // 初始化时输出Start collect images
    RCLCPP_INFO(this->get_logger(), "Start collect images");
    
    // 声明并获取参数
    declare_parameter("publish_rate", 10.0); // 默认值 n fps
    declare_parameter("loop_mode", false);
    double rate = get_parameter("publish_rate").as_double();
    loop_mode_ = get_parameter("loop_mode").as_bool();

    // 初始化图像路径
    folder_path_left_ = "/home/geneta/Project/00/image_0";
    folder_path_right_ = "/home/geneta/Project/00/image_1";

    loadImagePaths();

    // 初始化发布者，注意话题名称与订阅者一致
    left_pub_ = create_publisher<sensor_msgs::msg::Image>("Geneta_Image_left", 10);
    right_pub_ = create_publisher<sensor_msgs::msg::Image>("Geneta_Image_right", 10);

    // 定时器设置
    timer_ = create_wall_timer(
        std::chrono::milliseconds(static_cast<int>(1000 / rate)),
        std::bind(&ImagePublisher::timerCallback, this)
    );
}

// 添加完整的图像发布逻辑,0.1s进入一次回调函数
void ImagePublisher::timerCallback() {
    if (current_index_ >= left_image_paths_.size()) {
        if (loop_mode_) {
            current_index_ = 0;
            RCLCPP_INFO(get_logger(), "Restarting image sequence");
        } 
        else {
            RCLCPP_INFO(get_logger(), "Image sequence completed");
            rclcpp::shutdown();
        }
        return;
    }

    try {
        // std::cout << "running" << std::endl;
        // 并行加载左右图像
        cv::Mat left_img = cv::imread(left_image_paths_[current_index_]);
        cv::Mat right_img = cv::imread(right_image_paths_[current_index_]);

        // 可视化检测
        // cv::imshow("Left Camera", left_img);
        // cv::imshow("Right Camera", right_img);
        // cv::waitKey(1);

        // 双话题发布
        auto left_msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", left_img).toImageMsg();
        auto right_msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", right_img).toImageMsg();

        left_msg->header.stamp = now();  // 保证时间戳一致
        right_msg->header.stamp = left_msg->header.stamp; 
        left_msg->header.frame_id = "base_link"; 
        right_msg->header.frame_id = "base_link";
        left_pub_->publish(*left_msg);
        right_pub_->publish(*right_msg);

        std::cout << "已发布第" << current_index_ << "帧立体图像" << std::endl;
        
        current_index_++;

        // RCLCPP_DEBUG(get_logger(), "已发布第%zu帧立体图像", current_index_++);

    } catch (const cv_bridge::Exception& e) {
        RCLCPP_ERROR(get_logger(), "图像转换失败: %s", e.what());
    }
}

// 路径加载
void ImagePublisher::loadImagePaths() {
    auto load_single_dir = [](const std::string& path) {
        std::vector<std::string> paths;
        for (const auto& entry : fs::directory_iterator(path)) {
            if (entry.path().extension() == ".png") {
                paths.emplace_back(entry.path().string());
            }
        }
        // 按文件名数字排序
        std::sort(paths.begin(), paths.end(), [](const auto& a, const auto& b) {
            return std::stoi(a.substr(a.find_last_of("/")+1, 6)) < 
                   std::stoi(b.substr(b.find_last_of("/")+1, 6));
        });
        return paths;
    };

    left_image_paths_ = load_single_dir(folder_path_left_);
    right_image_paths_ = load_single_dir(folder_path_right_);

    // 验证数量一致性
    if (left_image_paths_.size() != right_image_paths_.size()) {
        RCLCPP_FATAL(get_logger(), "左右目图像数量不一致！左:%zu 右:%zu", 
                    left_image_paths_.size(), right_image_paths_.size());
        rclcpp::shutdown();
    }
}

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ImagePublisher>());
    rclcpp::shutdown();
    return 0;
}