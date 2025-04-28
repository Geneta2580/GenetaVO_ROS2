// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from geneta_slam_ros2_pkg:msg/FandB.idl
// generated code does not contain a copyright notice

#ifndef GENETA_SLAM_ROS2_PKG__MSG__DETAIL__FAND_B__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define GENETA_SLAM_ROS2_PKG__MSG__DETAIL__FAND_B__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "geneta_slam_ros2_pkg/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "geneta_slam_ros2_pkg/msg/detail/fand_b__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace geneta_slam_ros2_pkg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_geneta_slam_ros2_pkg
cdr_serialize(
  const geneta_slam_ros2_pkg::msg::FandB & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_geneta_slam_ros2_pkg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  geneta_slam_ros2_pkg::msg::FandB & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_geneta_slam_ros2_pkg
get_serialized_size(
  const geneta_slam_ros2_pkg::msg::FandB & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_geneta_slam_ros2_pkg
max_serialized_size_FandB(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_geneta_slam_ros2_pkg
cdr_serialize_key(
  const geneta_slam_ros2_pkg::msg::FandB & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_geneta_slam_ros2_pkg
get_serialized_size_key(
  const geneta_slam_ros2_pkg::msg::FandB & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_geneta_slam_ros2_pkg
max_serialized_size_key_FandB(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace geneta_slam_ros2_pkg

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_geneta_slam_ros2_pkg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, geneta_slam_ros2_pkg, msg, FandB)();

#ifdef __cplusplus
}
#endif

#endif  // GENETA_SLAM_ROS2_PKG__MSG__DETAIL__FAND_B__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
