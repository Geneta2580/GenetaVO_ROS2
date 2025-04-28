#ifndef STEREO_CAM_NODE_H
#define STEREO_CAM_NODE_H

#include <common.h>
#include <image_transport/image_transport.hpp>

class StereoCam : public rclcpp::Node {
    public:
        StereoCam();
    
    private:
        void initCamera();
        void captureAndPublish();
        void publishImage(cv::Mat& img, const std::string& frame_id, 
            const rclcpp::Time& stamp, const image_transport::CameraPublisher& pub);

        // 添加成员变量
        cv::VideoCapture cap_;
        image_transport::CameraPublisher left_pub_, right_pub_;
        rclcpp::TimerBase::SharedPtr timer_;
};

#endif