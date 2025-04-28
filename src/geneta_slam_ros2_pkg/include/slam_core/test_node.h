#ifndef TEST_NODE_H
#define TEST_NODE_H

#include "rclcpp/rclcpp.hpp"
#include "geneta_slam_ros2_pkg/msg/fand_b.hpp"  // 自定义消息头文件[9](@ref)
#include "geometry_msgs/msg/point.hpp"

class TestNode : public rclcpp::Node {
public:
    TestNode();
    
private:
    void timer_callback();
    
    rclcpp::Publisher<geneta_slam_ros2_pkg::msg::FandB>::SharedPtr FandB_pub_;
    rclcpp::TimerBase::SharedPtr timer_;

    geneta_slam_ros2_pkg::msg::FandB FandB_msg_;

    size_t count_ = 0;
};

#endif