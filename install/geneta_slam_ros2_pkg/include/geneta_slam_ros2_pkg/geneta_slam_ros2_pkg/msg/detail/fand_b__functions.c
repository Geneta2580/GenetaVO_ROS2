// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from geneta_slam_ros2_pkg:msg/FandB.idl
// generated code does not contain a copyright notice
#include "geneta_slam_ros2_pkg/msg/detail/fand_b__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `u`
// Member `v`
// Member `landmark_ids`
// Member `x`
// Member `y`
// Member `z`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
geneta_slam_ros2_pkg__msg__FandB__init(geneta_slam_ros2_pkg__msg__FandB * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    geneta_slam_ros2_pkg__msg__FandB__fini(msg);
    return false;
  }
  // u
  if (!rosidl_runtime_c__float__Sequence__init(&msg->u, 0)) {
    geneta_slam_ros2_pkg__msg__FandB__fini(msg);
    return false;
  }
  // v
  if (!rosidl_runtime_c__float__Sequence__init(&msg->v, 0)) {
    geneta_slam_ros2_pkg__msg__FandB__fini(msg);
    return false;
  }
  // landmark_ids
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->landmark_ids, 0)) {
    geneta_slam_ros2_pkg__msg__FandB__fini(msg);
    return false;
  }
  // x
  if (!rosidl_runtime_c__double__Sequence__init(&msg->x, 0)) {
    geneta_slam_ros2_pkg__msg__FandB__fini(msg);
    return false;
  }
  // y
  if (!rosidl_runtime_c__double__Sequence__init(&msg->y, 0)) {
    geneta_slam_ros2_pkg__msg__FandB__fini(msg);
    return false;
  }
  // z
  if (!rosidl_runtime_c__double__Sequence__init(&msg->z, 0)) {
    geneta_slam_ros2_pkg__msg__FandB__fini(msg);
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__init(&msg->pose)) {
    geneta_slam_ros2_pkg__msg__FandB__fini(msg);
    return false;
  }
  return true;
}

void
geneta_slam_ros2_pkg__msg__FandB__fini(geneta_slam_ros2_pkg__msg__FandB * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // u
  rosidl_runtime_c__float__Sequence__fini(&msg->u);
  // v
  rosidl_runtime_c__float__Sequence__fini(&msg->v);
  // landmark_ids
  rosidl_runtime_c__int32__Sequence__fini(&msg->landmark_ids);
  // x
  rosidl_runtime_c__double__Sequence__fini(&msg->x);
  // y
  rosidl_runtime_c__double__Sequence__fini(&msg->y);
  // z
  rosidl_runtime_c__double__Sequence__fini(&msg->z);
  // pose
  geometry_msgs__msg__Pose__fini(&msg->pose);
}

bool
geneta_slam_ros2_pkg__msg__FandB__are_equal(const geneta_slam_ros2_pkg__msg__FandB * lhs, const geneta_slam_ros2_pkg__msg__FandB * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // u
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->u), &(rhs->u)))
  {
    return false;
  }
  // v
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->v), &(rhs->v)))
  {
    return false;
  }
  // landmark_ids
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->landmark_ids), &(rhs->landmark_ids)))
  {
    return false;
  }
  // x
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->x), &(rhs->x)))
  {
    return false;
  }
  // y
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->y), &(rhs->y)))
  {
    return false;
  }
  // z
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->z), &(rhs->z)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  return true;
}

bool
geneta_slam_ros2_pkg__msg__FandB__copy(
  const geneta_slam_ros2_pkg__msg__FandB * input,
  geneta_slam_ros2_pkg__msg__FandB * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // u
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->u), &(output->u)))
  {
    return false;
  }
  // v
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->v), &(output->v)))
  {
    return false;
  }
  // landmark_ids
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->landmark_ids), &(output->landmark_ids)))
  {
    return false;
  }
  // x
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->x), &(output->x)))
  {
    return false;
  }
  // y
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->y), &(output->y)))
  {
    return false;
  }
  // z
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->z), &(output->z)))
  {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  return true;
}

geneta_slam_ros2_pkg__msg__FandB *
geneta_slam_ros2_pkg__msg__FandB__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  geneta_slam_ros2_pkg__msg__FandB * msg = (geneta_slam_ros2_pkg__msg__FandB *)allocator.allocate(sizeof(geneta_slam_ros2_pkg__msg__FandB), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(geneta_slam_ros2_pkg__msg__FandB));
  bool success = geneta_slam_ros2_pkg__msg__FandB__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
geneta_slam_ros2_pkg__msg__FandB__destroy(geneta_slam_ros2_pkg__msg__FandB * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    geneta_slam_ros2_pkg__msg__FandB__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
geneta_slam_ros2_pkg__msg__FandB__Sequence__init(geneta_slam_ros2_pkg__msg__FandB__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  geneta_slam_ros2_pkg__msg__FandB * data = NULL;

  if (size) {
    data = (geneta_slam_ros2_pkg__msg__FandB *)allocator.zero_allocate(size, sizeof(geneta_slam_ros2_pkg__msg__FandB), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = geneta_slam_ros2_pkg__msg__FandB__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        geneta_slam_ros2_pkg__msg__FandB__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
geneta_slam_ros2_pkg__msg__FandB__Sequence__fini(geneta_slam_ros2_pkg__msg__FandB__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      geneta_slam_ros2_pkg__msg__FandB__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

geneta_slam_ros2_pkg__msg__FandB__Sequence *
geneta_slam_ros2_pkg__msg__FandB__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  geneta_slam_ros2_pkg__msg__FandB__Sequence * array = (geneta_slam_ros2_pkg__msg__FandB__Sequence *)allocator.allocate(sizeof(geneta_slam_ros2_pkg__msg__FandB__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = geneta_slam_ros2_pkg__msg__FandB__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
geneta_slam_ros2_pkg__msg__FandB__Sequence__destroy(geneta_slam_ros2_pkg__msg__FandB__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    geneta_slam_ros2_pkg__msg__FandB__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
geneta_slam_ros2_pkg__msg__FandB__Sequence__are_equal(const geneta_slam_ros2_pkg__msg__FandB__Sequence * lhs, const geneta_slam_ros2_pkg__msg__FandB__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!geneta_slam_ros2_pkg__msg__FandB__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
geneta_slam_ros2_pkg__msg__FandB__Sequence__copy(
  const geneta_slam_ros2_pkg__msg__FandB__Sequence * input,
  geneta_slam_ros2_pkg__msg__FandB__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(geneta_slam_ros2_pkg__msg__FandB);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    geneta_slam_ros2_pkg__msg__FandB * data =
      (geneta_slam_ros2_pkg__msg__FandB *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!geneta_slam_ros2_pkg__msg__FandB__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          geneta_slam_ros2_pkg__msg__FandB__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!geneta_slam_ros2_pkg__msg__FandB__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
