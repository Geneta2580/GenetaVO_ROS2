#ifndef FRONTEND_H
#define FRONTEND_H

#include "common.h"
#include "slam_core/frame.h"
#include "slam_core/feature.h"
#include "slam_core/camera.h"
#include "slam_core/dataset.h"
#include "slam_core/backend.h"
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

// 前端工作状态
enum class FrontendStatus {INIT, TRACK}; 

class Frontend : public rclcpp::Node {
    public:
        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        typedef std::shared_ptr<Frontend> Ptr;

        Frontend();

        // 获取前端状态
        FrontendStatus GetStatus() const { return status_; }

        // 设置地图
        void SetMap(Map::Ptr map) { map_ = map; }

        // 设置相机，可以用来初始化
        void SetCameras(Camera::Ptr left, Camera::Ptr right) {
            camera_left_ = left;
            camera_right_ = right;
        }

        // 添加一个帧并进行计算
        bool Calculate(Frame::Ptr frame);

    private:
        // 回调函数
        void frontend_callback(const sensor_msgs::msg::Image::ConstSharedPtr& left_msg,
            const sensor_msgs::msg::Image::ConstSharedPtr& right_msg);

        // 初始化函数
        bool NodeInit();

        // 发布者创建
        rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr pose_pub_;
        rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr path_pub_;
        rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr map_pub_;
        std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
        rclcpp::Publisher<geneta_slam_ros2_pkg::msg::FandB>::SharedPtr FandB_pub_;

        // 双目图像双话题同步用
        message_filters::Subscriber<sensor_msgs::msg::Image> left_sub_;
        message_filters::Subscriber<sensor_msgs::msg::Image> right_sub_;
        using SyncPolicy = message_filters::sync_policies::ApproximateTime<
            sensor_msgs::msg::Image, 
            sensor_msgs::msg::Image>;
        std::shared_ptr<message_filters::Synchronizer<SyncPolicy>> sync_;

        // 封装的位姿信息，需要public
        nav_msgs::msg::Odometry::SharedPtr odom_msg_ = std::make_shared<nav_msgs::msg::Odometry>();
        geometry_msgs::msg::TransformStamped transform;

        nav_msgs::msg::Path::SharedPtr path_msg_ = std::make_shared<nav_msgs::msg::Path>();
        geometry_msgs::msg::PoseStamped path_stamped;

        geneta_slam_ros2_pkg::msg::FandB FandB_msg_;

        // 初始化前端状态
        FrontendStatus status_ = FrontendStatus::INIT; 

        // 进行数据初始化
        bool Init(); 

        // 进行左目图像GFTT特征点提取，返回提取的特征点数量
        int DetectLeftFeatures(); 

        // 进行光流追踪，返回在右目图像中追踪到的特征点数量
        int FindRightFeatures(); 

        // 进行光流追踪，通过上一帧特征点来检测这一帧的特征点
        int LKDetectLastFeatures();

        // 三角化，通过左右目图像匹配点计算空间点，返回三角化成功的匹配点值
        int Triangulation();

        // 进行PnP问题的求解，得到这一帧图像和上一帧图像的相对位姿
        int BACurrentPose();
        
        // 初始化第一帧的地图
        bool MapInit();

        // 进行光流追踪、位姿估计
        int Track();   

        // 重新进行特征点检测以及三角化
        void ReTrack();

        // 插入关键帧
        void InsertKeyFrame();

        // 封装位姿信息为一个位姿信息
        void PosePublishPack();

        // 数据变量初始化
        Frame::Ptr current_frame_ = nullptr;  // 当前帧 std::make_shared<Frame>()这个可能导致线程的问题
        Frame::Ptr last_frame_ = nullptr;     // 上一帧
        Camera::Ptr camera_left_ = nullptr;   // 左侧相机
        Camera::Ptr camera_right_ = nullptr;  // 右侧相机
        Map::Ptr map_ = std::make_shared<Map>(); // 全局地图，注意初始化的问题

        // 上一帧到当前帧的相对运动，用于估计当前帧pose初值，默认初始化为单位阵
        SE3 relative_motion_;

        // 隔一帧插入关键帧的标志
        bool insert_key_flag = true;

        // 一些参数
        int num_features_ = 150;//Config::Get<int>("num_features");
        int num_features_tracking_ = 60; //Config::Get<double>("num_features_tracking"); 
        int num_track_good_ = 0;

        int num_features_init_ = 100;
        int num_features_needed_for_keyframe_ = 80;

        int frontend_cnt = 0; // 前端运行计数

        // 加载图像为Frame类
        Dataset::Ptr dataset_ = nullptr;
};

#endif