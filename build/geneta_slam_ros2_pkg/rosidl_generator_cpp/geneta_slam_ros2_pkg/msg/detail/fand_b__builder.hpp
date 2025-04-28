// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from geneta_slam_ros2_pkg:msg/FandB.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "geneta_slam_ros2_pkg/msg/fand_b.hpp"


#ifndef GENETA_SLAM_ROS2_PKG__MSG__DETAIL__FAND_B__BUILDER_HPP_
#define GENETA_SLAM_ROS2_PKG__MSG__DETAIL__FAND_B__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "geneta_slam_ros2_pkg/msg/detail/fand_b__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace geneta_slam_ros2_pkg
{

namespace msg
{

namespace builder
{

class Init_FandB_pose
{
public:
  explicit Init_FandB_pose(::geneta_slam_ros2_pkg::msg::FandB & msg)
  : msg_(msg)
  {}
  ::geneta_slam_ros2_pkg::msg::FandB pose(::geneta_slam_ros2_pkg::msg::FandB::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::geneta_slam_ros2_pkg::msg::FandB msg_;
};

class Init_FandB_z
{
public:
  explicit Init_FandB_z(::geneta_slam_ros2_pkg::msg::FandB & msg)
  : msg_(msg)
  {}
  Init_FandB_pose z(::geneta_slam_ros2_pkg::msg::FandB::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_FandB_pose(msg_);
  }

private:
  ::geneta_slam_ros2_pkg::msg::FandB msg_;
};

class Init_FandB_y
{
public:
  explicit Init_FandB_y(::geneta_slam_ros2_pkg::msg::FandB & msg)
  : msg_(msg)
  {}
  Init_FandB_z y(::geneta_slam_ros2_pkg::msg::FandB::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_FandB_z(msg_);
  }

private:
  ::geneta_slam_ros2_pkg::msg::FandB msg_;
};

class Init_FandB_x
{
public:
  explicit Init_FandB_x(::geneta_slam_ros2_pkg::msg::FandB & msg)
  : msg_(msg)
  {}
  Init_FandB_y x(::geneta_slam_ros2_pkg::msg::FandB::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_FandB_y(msg_);
  }

private:
  ::geneta_slam_ros2_pkg::msg::FandB msg_;
};

class Init_FandB_landmark_ids
{
public:
  explicit Init_FandB_landmark_ids(::geneta_slam_ros2_pkg::msg::FandB & msg)
  : msg_(msg)
  {}
  Init_FandB_x landmark_ids(::geneta_slam_ros2_pkg::msg::FandB::_landmark_ids_type arg)
  {
    msg_.landmark_ids = std::move(arg);
    return Init_FandB_x(msg_);
  }

private:
  ::geneta_slam_ros2_pkg::msg::FandB msg_;
};

class Init_FandB_v
{
public:
  explicit Init_FandB_v(::geneta_slam_ros2_pkg::msg::FandB & msg)
  : msg_(msg)
  {}
  Init_FandB_landmark_ids v(::geneta_slam_ros2_pkg::msg::FandB::_v_type arg)
  {
    msg_.v = std::move(arg);
    return Init_FandB_landmark_ids(msg_);
  }

private:
  ::geneta_slam_ros2_pkg::msg::FandB msg_;
};

class Init_FandB_u
{
public:
  explicit Init_FandB_u(::geneta_slam_ros2_pkg::msg::FandB & msg)
  : msg_(msg)
  {}
  Init_FandB_v u(::geneta_slam_ros2_pkg::msg::FandB::_u_type arg)
  {
    msg_.u = std::move(arg);
    return Init_FandB_v(msg_);
  }

private:
  ::geneta_slam_ros2_pkg::msg::FandB msg_;
};

class Init_FandB_header
{
public:
  Init_FandB_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FandB_u header(::geneta_slam_ros2_pkg::msg::FandB::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_FandB_u(msg_);
  }

private:
  ::geneta_slam_ros2_pkg::msg::FandB msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::geneta_slam_ros2_pkg::msg::FandB>()
{
  return geneta_slam_ros2_pkg::msg::builder::Init_FandB_header();
}

}  // namespace geneta_slam_ros2_pkg

#endif  // GENETA_SLAM_ROS2_PKG__MSG__DETAIL__FAND_B__BUILDER_HPP_
