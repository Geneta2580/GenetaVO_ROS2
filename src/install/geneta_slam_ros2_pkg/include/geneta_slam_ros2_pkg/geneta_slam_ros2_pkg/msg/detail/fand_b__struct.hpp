// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from geneta_slam_ros2_pkg:msg/FandB.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "geneta_slam_ros2_pkg/msg/fand_b.hpp"


#ifndef GENETA_SLAM_ROS2_PKG__MSG__DETAIL__FAND_B__STRUCT_HPP_
#define GENETA_SLAM_ROS2_PKG__MSG__DETAIL__FAND_B__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__geneta_slam_ros2_pkg__msg__FandB __attribute__((deprecated))
#else
# define DEPRECATED__geneta_slam_ros2_pkg__msg__FandB __declspec(deprecated)
#endif

namespace geneta_slam_ros2_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FandB_
{
  using Type = FandB_<ContainerAllocator>;

  explicit FandB_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    pose(_init)
  {
    (void)_init;
  }

  explicit FandB_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    pose(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _u_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _u_type u;
  using _v_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _v_type v;
  using _landmark_ids_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _landmark_ids_type landmark_ids;
  using _x_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _x_type x;
  using _y_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _y_type y;
  using _z_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _z_type z;
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__u(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->u = _arg;
    return *this;
  }
  Type & set__v(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->v = _arg;
    return *this;
  }
  Type & set__landmark_ids(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->landmark_ids = _arg;
    return *this;
  }
  Type & set__x(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    geneta_slam_ros2_pkg::msg::FandB_<ContainerAllocator> *;
  using ConstRawPtr =
    const geneta_slam_ros2_pkg::msg::FandB_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<geneta_slam_ros2_pkg::msg::FandB_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<geneta_slam_ros2_pkg::msg::FandB_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      geneta_slam_ros2_pkg::msg::FandB_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<geneta_slam_ros2_pkg::msg::FandB_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      geneta_slam_ros2_pkg::msg::FandB_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<geneta_slam_ros2_pkg::msg::FandB_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<geneta_slam_ros2_pkg::msg::FandB_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<geneta_slam_ros2_pkg::msg::FandB_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__geneta_slam_ros2_pkg__msg__FandB
    std::shared_ptr<geneta_slam_ros2_pkg::msg::FandB_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__geneta_slam_ros2_pkg__msg__FandB
    std::shared_ptr<geneta_slam_ros2_pkg::msg::FandB_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FandB_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->u != other.u) {
      return false;
    }
    if (this->v != other.v) {
      return false;
    }
    if (this->landmark_ids != other.landmark_ids) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const FandB_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FandB_

// alias to use template instance with default allocator
using FandB =
  geneta_slam_ros2_pkg::msg::FandB_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace geneta_slam_ros2_pkg

#endif  // GENETA_SLAM_ROS2_PKG__MSG__DETAIL__FAND_B__STRUCT_HPP_
