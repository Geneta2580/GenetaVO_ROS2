#include "slam_core/test_node.h"

TestNode::TestNode() : Node("test_node") {

    // 创建发布者，QoS深度设为10
    FandB_pub_ = this->create_publisher<geneta_slam_ros2_pkg::msg::FandB>("FandB", 10);
    
    // 创建500ms周期定时器
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(500),
        std::bind(&TestNode::timer_callback, this));
}

void TestNode::timer_callback() {

    //填充消息内容
    FandB_msg_.u = {1.0f, 2.5f, 3.14f}; // 浮点数组示例
    FandB_msg_.v = {1.0f, 2.5f, 3.14f}; // 浮点数组示例

    FandB_msg_.landmark_ids = {1, 2, 3};
    FandB_msg_.x = {1.0f, 2.5f, 3.14f};
    FandB_msg_.y = {1.0f, 2.5f, 3.14f};
    FandB_msg_.z = {1.0f, 2.5f, 3.14f};

    FandB_msg_.pose.position.x = 0;
    FandB_msg_.pose.position.y = 0;
    FandB_msg_.pose.position.z = 0;
    FandB_msg_.pose.orientation.x = 0;
    FandB_msg_.pose.orientation.y = 0;
    FandB_msg_.pose.orientation.z = 0;
    FandB_msg_.pose.orientation.w = 1;

    FandB_msg_.header.stamp = this->get_clock()->now();
    FandB_msg_.header.frame_id = "odom";

    // RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.name.c_str());
    FandB_pub_->publish(FandB_msg_); // 发布自定义消息
}

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TestNode>());
    rclcpp::shutdown();
    return 0;
}