// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from geneta_slam_ros2_pkg:msg/FandB.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "geneta_slam_ros2_pkg/msg/detail/fand_b__struct.h"
#include "geneta_slam_ros2_pkg/msg/detail/fand_b__type_support.h"
#include "geneta_slam_ros2_pkg/msg/detail/fand_b__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace geneta_slam_ros2_pkg
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _FandB_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _FandB_type_support_ids_t;

static const _FandB_type_support_ids_t _FandB_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _FandB_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _FandB_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _FandB_type_support_symbol_names_t _FandB_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geneta_slam_ros2_pkg, msg, FandB)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geneta_slam_ros2_pkg, msg, FandB)),
  }
};

typedef struct _FandB_type_support_data_t
{
  void * data[2];
} _FandB_type_support_data_t;

static _FandB_type_support_data_t _FandB_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _FandB_message_typesupport_map = {
  2,
  "geneta_slam_ros2_pkg",
  &_FandB_message_typesupport_ids.typesupport_identifier[0],
  &_FandB_message_typesupport_symbol_names.symbol_name[0],
  &_FandB_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t FandB_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_FandB_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &geneta_slam_ros2_pkg__msg__FandB__get_type_hash,
  &geneta_slam_ros2_pkg__msg__FandB__get_type_description,
  &geneta_slam_ros2_pkg__msg__FandB__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace geneta_slam_ros2_pkg

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, geneta_slam_ros2_pkg, msg, FandB)() {
  return &::geneta_slam_ros2_pkg::msg::rosidl_typesupport_c::FandB_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
