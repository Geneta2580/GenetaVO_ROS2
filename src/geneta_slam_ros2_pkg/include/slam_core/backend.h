#ifndef BACKEND_H
#define BACKEND_H

#include "common.h"
#include "slam_core/frame.h"
#include "slam_core/feature.h"
#include "slam_core/camera.h"
#include "slam_core/dataset.h"
#include "slam_core/algorithm.h"
#include "slam_core/g2o_param.h"
#include <message_filters/subscriber.h>
#include <message_filters/sync_policies/approximate_time.h>
#include "nav_msgs/msg/odometry.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <nav_msgs/msg/path.hpp>
#include "geneta_slam_ros2_pkg/msg/fand_b.hpp"
#include <g2o/solvers/cholmod/linear_solver_cholmod.h> 

class Backend : public rclcpp::Node {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        using Ptr = std::shared_ptr<Backend>;

        // 构造函数中启动优化线程并挂起
        Backend();

        // 设置左右目的相机，用于获得内外参，给空指针赋值
        void SetCameras(Camera::Ptr left, Camera::Ptr right) {
            cam_left_ = left;
            cam_right_ = right;
        }

        // 设置地图
        void SetMap(std::shared_ptr<Map> map) { map_ = map; }

        // 触发地图更新，启动优化
        void Wake();

        // 关闭后端线程
        void Stop();

        // 关联回环
        // void SetLoopclosing(LoopclosingPtr loop) { loop_ = loop; }

        // 后端地图插入一个新地图点
        void InsertNewMapPoint(MapPoint::Ptr new_map_point) { new_map_point_ = new_map_point; }

        // 后端地图插入一个新关键帧
        void InsertNewKeyFrame(Frame::Ptr new_key_frame) { new_key_frame_ = new_key_frame; }

    private:
        // 回调函数
        void frontend_callback(const sensor_msgs::msg::Image::ConstSharedPtr& left_msg,
            const sensor_msgs::msg::Image::ConstSharedPtr& right_msg);
        
        // 发布者创建
        rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr pose_pub_;
        rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr path_pub_;
        rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr map_pub_;
        std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;

        // 封装的位姿信息
        geneta_slam_ros2_pkg::msg::FandB FandB_msg_;

        // 后端线程
        void BackendLoop();

        // 对给定关键帧和路标点进行优化
        void Optimize(Map::KeyframesType& keyframes, Map::LandmarksType& landmarks);

        std::shared_ptr<Map> map_;
        std::thread backend_thread_;
        std::mutex data_mutex_;

        std::condition_variable map_update_; // 满足条件时唤醒线程
        std::atomic<bool> backend_running_;

        Camera::Ptr cam_left_ = nullptr, cam_right_ = nullptr;

        int last_loop_size_ = 0;

        //LoopclosingPtr loop_; // 新增后端实例引用

        int old_vertex_id = 0; // 需要边缘化的旧顶点

        // 插入的新帧地图点
        Frame::Ptr new_key_frame_;
        MapPoint::Ptr new_map_point_;
    };

#endif