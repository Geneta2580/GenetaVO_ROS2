// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from geneta_slam_ros2_pkg:msg/FandB.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "geneta_slam_ros2_pkg/msg/detail/fand_b__rosidl_typesupport_introspection_c.h"
#include "geneta_slam_ros2_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "geneta_slam_ros2_pkg/msg/detail/fand_b__functions.h"
#include "geneta_slam_ros2_pkg/msg/detail/fand_b__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `u`
// Member `v`
// Member `landmark_ids`
// Member `x`
// Member `y`
// Member `z`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `pose`
#include "geometry_msgs/msg/pose.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__FandB_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  geneta_slam_ros2_pkg__msg__FandB__init(message_memory);
}

void geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__FandB_fini_function(void * message_memory)
{
  geneta_slam_ros2_pkg__msg__FandB__fini(message_memory);
}

size_t geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__size_function__FandB__u(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_const_function__FandB__u(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_function__FandB__u(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__fetch_function__FandB__u(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_const_function__FandB__u(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__assign_function__FandB__u(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_function__FandB__u(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__resize_function__FandB__u(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__size_function__FandB__v(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_const_function__FandB__v(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_function__FandB__v(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__fetch_function__FandB__v(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_const_function__FandB__v(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__assign_function__FandB__v(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_function__FandB__v(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__resize_function__FandB__v(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__size_function__FandB__landmark_ids(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_const_function__FandB__landmark_ids(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_function__FandB__landmark_ids(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__fetch_function__FandB__landmark_ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_const_function__FandB__landmark_ids(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__assign_function__FandB__landmark_ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_function__FandB__landmark_ids(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__resize_function__FandB__landmark_ids(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__size_function__FandB__x(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_const_function__FandB__x(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_function__FandB__x(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__fetch_function__FandB__x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_const_function__FandB__x(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__assign_function__FandB__x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_function__FandB__x(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__resize_function__FandB__x(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__size_function__FandB__y(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_const_function__FandB__y(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_function__FandB__y(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__fetch_function__FandB__y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_const_function__FandB__y(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__assign_function__FandB__y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_function__FandB__y(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__resize_function__FandB__y(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__size_function__FandB__z(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_const_function__FandB__z(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_function__FandB__z(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__fetch_function__FandB__z(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_const_function__FandB__z(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__assign_function__FandB__z(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_function__FandB__z(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__resize_function__FandB__z(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__FandB_message_member_array[8] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(geneta_slam_ros2_pkg__msg__FandB, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "u",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(geneta_slam_ros2_pkg__msg__FandB, u),  // bytes offset in struct
    NULL,  // default value
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__size_function__FandB__u,  // size() function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_const_function__FandB__u,  // get_const(index) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_function__FandB__u,  // get(index) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__fetch_function__FandB__u,  // fetch(index, &value) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__assign_function__FandB__u,  // assign(index, value) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__resize_function__FandB__u  // resize(index) function pointer
  },
  {
    "v",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(geneta_slam_ros2_pkg__msg__FandB, v),  // bytes offset in struct
    NULL,  // default value
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__size_function__FandB__v,  // size() function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_const_function__FandB__v,  // get_const(index) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_function__FandB__v,  // get(index) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__fetch_function__FandB__v,  // fetch(index, &value) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__assign_function__FandB__v,  // assign(index, value) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__resize_function__FandB__v  // resize(index) function pointer
  },
  {
    "landmark_ids",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(geneta_slam_ros2_pkg__msg__FandB, landmark_ids),  // bytes offset in struct
    NULL,  // default value
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__size_function__FandB__landmark_ids,  // size() function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_const_function__FandB__landmark_ids,  // get_const(index) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_function__FandB__landmark_ids,  // get(index) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__fetch_function__FandB__landmark_ids,  // fetch(index, &value) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__assign_function__FandB__landmark_ids,  // assign(index, value) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__resize_function__FandB__landmark_ids  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(geneta_slam_ros2_pkg__msg__FandB, x),  // bytes offset in struct
    NULL,  // default value
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__size_function__FandB__x,  // size() function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_const_function__FandB__x,  // get_const(index) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_function__FandB__x,  // get(index) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__fetch_function__FandB__x,  // fetch(index, &value) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__assign_function__FandB__x,  // assign(index, value) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__resize_function__FandB__x  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(geneta_slam_ros2_pkg__msg__FandB, y),  // bytes offset in struct
    NULL,  // default value
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__size_function__FandB__y,  // size() function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_const_function__FandB__y,  // get_const(index) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_function__FandB__y,  // get(index) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__fetch_function__FandB__y,  // fetch(index, &value) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__assign_function__FandB__y,  // assign(index, value) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__resize_function__FandB__y  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(geneta_slam_ros2_pkg__msg__FandB, z),  // bytes offset in struct
    NULL,  // default value
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__size_function__FandB__z,  // size() function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_const_function__FandB__z,  // get_const(index) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__get_function__FandB__z,  // get(index) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__fetch_function__FandB__z,  // fetch(index, &value) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__assign_function__FandB__z,  // assign(index, value) function pointer
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__resize_function__FandB__z  // resize(index) function pointer
  },
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(geneta_slam_ros2_pkg__msg__FandB, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__FandB_message_members = {
  "geneta_slam_ros2_pkg__msg",  // message namespace
  "FandB",  // message name
  8,  // number of fields
  sizeof(geneta_slam_ros2_pkg__msg__FandB),
  false,  // has_any_key_member_
  geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__FandB_message_member_array,  // message members
  geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__FandB_init_function,  // function to initialize message memory (memory has to be allocated)
  geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__FandB_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__FandB_message_type_support_handle = {
  0,
  &geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__FandB_message_members,
  get_message_typesupport_handle_function,
  &geneta_slam_ros2_pkg__msg__FandB__get_type_hash,
  &geneta_slam_ros2_pkg__msg__FandB__get_type_description,
  &geneta_slam_ros2_pkg__msg__FandB__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_geneta_slam_ros2_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geneta_slam_ros2_pkg, msg, FandB)() {
  geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__FandB_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__FandB_message_member_array[7].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__FandB_message_type_support_handle.typesupport_identifier) {
    geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__FandB_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &geneta_slam_ros2_pkg__msg__FandB__rosidl_typesupport_introspection_c__FandB_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
