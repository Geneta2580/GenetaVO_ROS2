// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from geneta_slam_ros2_pkg:msg/FandB.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "geneta_slam_ros2_pkg/msg/fand_b.h"


#ifndef GENETA_SLAM_ROS2_PKG__MSG__DETAIL__FAND_B__STRUCT_H_
#define GENETA_SLAM_ROS2_PKG__MSG__DETAIL__FAND_B__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'u'
// Member 'v'
// Member 'landmark_ids'
// Member 'x'
// Member 'y'
// Member 'z'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/FandB in the package geneta_slam_ros2_pkg.
/**
  * 基础信息头（时间戳+坐标系）
 */
typedef struct geneta_slam_ros2_pkg__msg__FandB
{
  std_msgs__msg__Header header;
  /// 特征点信息
  /// int32[] frame_ids         # 当前帧的ID
  /// int32[] feature_ids       # 特征点ID数组
  /// int32[] belong_landmark_ids      # 持有该特征点的路标点ID数组
  /// 特征点图像坐标X
  rosidl_runtime_c__float__Sequence u;
  /// 图像坐标Y
  rosidl_runtime_c__float__Sequence v;
  /// 对应路标点信息（世界坐标系）
  /// 路标点ID
  rosidl_runtime_c__int32__Sequence landmark_ids;
  /// 三维坐标X
  rosidl_runtime_c__double__Sequence x;
  /// Y
  rosidl_runtime_c__double__Sequence y;
  /// Z
  rosidl_runtime_c__double__Sequence z;
  /// 里程计数据（位置+方向）
  geometry_msgs__msg__Pose pose;
} geneta_slam_ros2_pkg__msg__FandB;

// Struct for a sequence of geneta_slam_ros2_pkg__msg__FandB.
typedef struct geneta_slam_ros2_pkg__msg__FandB__Sequence
{
  geneta_slam_ros2_pkg__msg__FandB * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} geneta_slam_ros2_pkg__msg__FandB__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GENETA_SLAM_ROS2_PKG__MSG__DETAIL__FAND_B__STRUCT_H_
