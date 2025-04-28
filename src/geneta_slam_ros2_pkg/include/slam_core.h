#ifndef SLAM_CORE_H
#define SLAM_CORE_H

#include "common.h"
#include "slam_core/frontend.h"
#include "slam_core/backend.h"
#include "slam_core/config.h"
#include "slam_core/dataset.h"
#include "slam_core/viewer.h"
#include <message_filters/subscriber.h>
#include <message_filters/sync_policies/approximate_time.h>
#include "nav_msgs/msg/odometry.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include <tf2_ros/transform_broadcaster.h>

class SLAM_Core : public rclcpp::Node {
    public:
        SLAM_Core();
        
    private:
        // 回调函数
        void stereo_callback(const sensor_msgs::msg::Image::ConstSharedPtr& left_msg,
            const sensor_msgs::msg::Image::ConstSharedPtr& right_msg);

        // 初始化函数
        bool Init();

        // 发布者创建
        rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr pose_pub_;
        rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr map_pub_;
        std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;

        // 双目图像双话题同步用
        message_filters::Subscriber<sensor_msgs::msg::Image> left_sub_;
        message_filters::Subscriber<sensor_msgs::msg::Image> right_sub_;
        using SyncPolicy = message_filters::sync_policies::ApproximateTime<
            sensor_msgs::msg::Image, 
            sensor_msgs::msg::Image>;
        std::shared_ptr<message_filters::Synchronizer<SyncPolicy>> sync_;

        // 封装位姿数据
        nav_msgs::msg::Odometry::SharedPtr odom_msg_; 
        geometry_msgs::msg::TransformStamped transform;

        // 前端
        Frontend::Ptr frontend_ = nullptr;

        // 后端
        Backend::Ptr backend_ = nullptr;

        // 显示界面
        // Viewer::Ptr viewer_ = nullptr;

        // 加载图像为Frame类
        Dataset::Ptr dataset_ = nullptr;

        // 加载地图
        Map::Ptr map_ = nullptr;

};

#endif