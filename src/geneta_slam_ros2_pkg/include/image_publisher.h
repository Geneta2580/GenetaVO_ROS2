#ifndef IMAGE_PUBLISHER_H
#define IMAGE_PUBLISHER_H

#include <common.h>

class ImagePublisher : public rclcpp::Node {
    public:
        ImagePublisher();
    
    private:
        // 回调函数
        void timerCallback();

        // 加载图片函数
        void loadImagePaths(); 

        // 添加成员变量
        rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr left_pub_; // 发布者节点
        rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr right_pub_;


        std::string folder_path_left_; // 左右目图像文件夹
        std::string folder_path_right_;
        std::vector<std::string> left_image_paths_;  // 左目路径
        std::vector<std::string> right_image_paths_; // 右目路径

        rclcpp::TimerBase::SharedPtr timer_; // 计数器用来定时发布图像
        size_t current_index_ = 0;
        bool loop_mode_;
};

#endif