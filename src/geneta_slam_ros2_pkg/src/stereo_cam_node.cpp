#include "stereo_cam_node.h"
namespace fs = std::filesystem;

/*
创建一个读取图像节点，初始化时输出"Start collect images"日志
​​*/
StereoCam::StereoCam() : Node("stereo_cam_node") {
    declare_parameter("device_id", 0);
    declare_parameter("frame_width", 1280);  // 双目合并宽度
    declare_parameter("frame_height", 480);

    // 创建发布者
    left_pub_ = image_transport::create_camera_publisher(this, "left/image_raw");
    right_pub_ = image_transport::create_camera_publisher(this, "right/image_raw");
    
    // 打开摄像头
    initCamera();
}

void StereoCam::initCamera() {
    int device_id = get_parameter("device_id").as_int();

    
    cap_.open(device_id, cv::CAP_V4L2);
    
    if(!cap_.isOpened()) {
        RCLCPP_ERROR(get_logger(), "Failed to open camera device %d", device_id);
        rclcpp::shutdown();
        return;
    }

    // 设置相机参数（关键配置点）[7,8](@ref)
    cap_.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M','J','P','G'));  // 强制MJPG格式
    cap_.set(cv::CAP_PROP_FRAME_WIDTH, get_parameter("frame_width").as_int());
    cap_.set(cv::CAP_PROP_FRAME_HEIGHT, get_parameter("frame_height").as_int());
    cap_.set(cv::CAP_PROP_FPS, 30); 

    // 启动图像采集定时器
    timer_ = create_wall_timer(
        std::chrono::milliseconds(33),  // 30Hz
        std::bind(&StereoCam::captureAndPublish, this));
}

// 添加完整的图像发布逻辑,0.1s进入一次回调函数
void StereoCam::captureAndPublish() {
    cv::Mat frame;
    cap_ >> frame;
    if(frame.empty()) return;

    // 双目图像分割（以1280x480为例）
    cv::Mat left_frame = frame(cv::Rect(0, 0, frame.cols/2, frame.rows));
    cv::Mat right_frame = frame(cv::Rect(frame.cols/2, 0, frame.cols/2, frame.rows));

    // 转换为ROS消息
    auto stamp = now();
    publishImage(left_frame, "left_cam", stamp, left_pub_);
    publishImage(right_frame, "right_cam", stamp, right_pub_);

}

void StereoCam::publishImage(cv::Mat& img, const std::string& frame_id, 
    const rclcpp::Time& stamp, const image_transport::CameraPublisher& pub) {

    auto msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", img).toImageMsg();
    msg->header.stamp = stamp;
    msg->header.frame_id = frame_id;

    auto info = std::make_unique<sensor_msgs::msg::CameraInfo>();
    info->header = msg->header;
    // 此处应添加相机标定参数[3](@ref)

    pub.publish(*msg, *info);
}

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<StereoCam>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
