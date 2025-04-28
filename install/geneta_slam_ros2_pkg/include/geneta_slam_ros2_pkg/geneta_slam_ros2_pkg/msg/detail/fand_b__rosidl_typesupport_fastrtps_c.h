// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from geneta_slam_ros2_pkg:msg/FandB.idl
// generated code does not contain a copyright notice
#ifndef GENETA_SLAM_ROS2_PKG__MSG__DETAIL__FAND_B__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define GENETA_SLAM_ROS2_PKG__MSG__DETAIL__FAND_B__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "geneta_slam_ros2_pkg/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "geneta_slam_ros2_pkg/msg/detail/fand_b__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_geneta_slam_ros2_pkg
bool cdr_serialize_geneta_slam_ros2_pkg__msg__FandB(
  const geneta_slam_ros2_pkg__msg__FandB * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_geneta_slam_ros2_pkg
bool cdr_deserialize_geneta_slam_ros2_pkg__msg__FandB(
  eprosima::fastcdr::Cdr &,
  geneta_slam_ros2_pkg__msg__FandB * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_geneta_slam_ros2_pkg
size_t get_serialized_size_geneta_slam_ros2_pkg__msg__FandB(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_geneta_slam_ros2_pkg
size_t max_serialized_size_geneta_slam_ros2_pkg__msg__FandB(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_geneta_slam_ros2_pkg
bool cdr_serialize_key_geneta_slam_ros2_pkg__msg__FandB(
  const geneta_slam_ros2_pkg__msg__FandB * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_geneta_slam_ros2_pkg
size_t get_serialized_size_key_geneta_slam_ros2_pkg__msg__FandB(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_geneta_slam_ros2_pkg
size_t max_serialized_size_key_geneta_slam_ros2_pkg__msg__FandB(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_geneta_slam_ros2_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geneta_slam_ros2_pkg, msg, FandB)();

#ifdef __cplusplus
}
#endif

#endif  // GENETA_SLAM_ROS2_PKG__MSG__DETAIL__FAND_B__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
