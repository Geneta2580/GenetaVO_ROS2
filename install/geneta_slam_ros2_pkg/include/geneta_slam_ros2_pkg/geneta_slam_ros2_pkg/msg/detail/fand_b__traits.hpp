// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from geneta_slam_ros2_pkg:msg/FandB.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "geneta_slam_ros2_pkg/msg/fand_b.hpp"


#ifndef GENETA_SLAM_ROS2_PKG__MSG__DETAIL__FAND_B__TRAITS_HPP_
#define GENETA_SLAM_ROS2_PKG__MSG__DETAIL__FAND_B__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "geneta_slam_ros2_pkg/msg/detail/fand_b__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace geneta_slam_ros2_pkg
{

namespace msg
{

inline void to_flow_style_yaml(
  const FandB & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: u
  {
    if (msg.u.size() == 0) {
      out << "u: []";
    } else {
      out << "u: [";
      size_t pending_items = msg.u.size();
      for (auto item : msg.u) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: v
  {
    if (msg.v.size() == 0) {
      out << "v: []";
    } else {
      out << "v: [";
      size_t pending_items = msg.v.size();
      for (auto item : msg.v) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: landmark_ids
  {
    if (msg.landmark_ids.size() == 0) {
      out << "landmark_ids: []";
    } else {
      out << "landmark_ids: [";
      size_t pending_items = msg.landmark_ids.size();
      for (auto item : msg.landmark_ids) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: x
  {
    if (msg.x.size() == 0) {
      out << "x: []";
    } else {
      out << "x: [";
      size_t pending_items = msg.x.size();
      for (auto item : msg.x) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: y
  {
    if (msg.y.size() == 0) {
      out << "y: []";
    } else {
      out << "y: [";
      size_t pending_items = msg.y.size();
      for (auto item : msg.y) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: z
  {
    if (msg.z.size() == 0) {
      out << "z: []";
    } else {
      out << "z: [";
      size_t pending_items = msg.z.size();
      for (auto item : msg.z) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FandB & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: u
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.u.size() == 0) {
      out << "u: []\n";
    } else {
      out << "u:\n";
      for (auto item : msg.u) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: v
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.v.size() == 0) {
      out << "v: []\n";
    } else {
      out << "v:\n";
      for (auto item : msg.v) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: landmark_ids
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.landmark_ids.size() == 0) {
      out << "landmark_ids: []\n";
    } else {
      out << "landmark_ids:\n";
      for (auto item : msg.landmark_ids) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.x.size() == 0) {
      out << "x: []\n";
    } else {
      out << "x:\n";
      for (auto item : msg.x) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.y.size() == 0) {
      out << "y: []\n";
    } else {
      out << "y:\n";
      for (auto item : msg.y) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.z.size() == 0) {
      out << "z: []\n";
    } else {
      out << "z:\n";
      for (auto item : msg.z) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FandB & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace geneta_slam_ros2_pkg

namespace rosidl_generator_traits
{

[[deprecated("use geneta_slam_ros2_pkg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const geneta_slam_ros2_pkg::msg::FandB & msg,
  std::ostream & out, size_t indentation = 0)
{
  geneta_slam_ros2_pkg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use geneta_slam_ros2_pkg::msg::to_yaml() instead")]]
inline std::string to_yaml(const geneta_slam_ros2_pkg::msg::FandB & msg)
{
  return geneta_slam_ros2_pkg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<geneta_slam_ros2_pkg::msg::FandB>()
{
  return "geneta_slam_ros2_pkg::msg::FandB";
}

template<>
inline const char * name<geneta_slam_ros2_pkg::msg::FandB>()
{
  return "geneta_slam_ros2_pkg/msg/FandB";
}

template<>
struct has_fixed_size<geneta_slam_ros2_pkg::msg::FandB>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<geneta_slam_ros2_pkg::msg::FandB>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<geneta_slam_ros2_pkg::msg::FandB>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GENETA_SLAM_ROS2_PKG__MSG__DETAIL__FAND_B__TRAITS_HPP_
