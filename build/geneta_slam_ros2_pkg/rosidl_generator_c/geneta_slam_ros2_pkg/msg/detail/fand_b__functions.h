// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from geneta_slam_ros2_pkg:msg/FandB.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "geneta_slam_ros2_pkg/msg/fand_b.h"


#ifndef GENETA_SLAM_ROS2_PKG__MSG__DETAIL__FAND_B__FUNCTIONS_H_
#define GENETA_SLAM_ROS2_PKG__MSG__DETAIL__FAND_B__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "geneta_slam_ros2_pkg/msg/rosidl_generator_c__visibility_control.h"

#include "geneta_slam_ros2_pkg/msg/detail/fand_b__struct.h"

/// Initialize msg/FandB message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * geneta_slam_ros2_pkg__msg__FandB
 * )) before or use
 * geneta_slam_ros2_pkg__msg__FandB__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_geneta_slam_ros2_pkg
bool
geneta_slam_ros2_pkg__msg__FandB__init(geneta_slam_ros2_pkg__msg__FandB * msg);

/// Finalize msg/FandB message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_geneta_slam_ros2_pkg
void
geneta_slam_ros2_pkg__msg__FandB__fini(geneta_slam_ros2_pkg__msg__FandB * msg);

/// Create msg/FandB message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * geneta_slam_ros2_pkg__msg__FandB__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_geneta_slam_ros2_pkg
geneta_slam_ros2_pkg__msg__FandB *
geneta_slam_ros2_pkg__msg__FandB__create(void);

/// Destroy msg/FandB message.
/**
 * It calls
 * geneta_slam_ros2_pkg__msg__FandB__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_geneta_slam_ros2_pkg
void
geneta_slam_ros2_pkg__msg__FandB__destroy(geneta_slam_ros2_pkg__msg__FandB * msg);

/// Check for msg/FandB message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_geneta_slam_ros2_pkg
bool
geneta_slam_ros2_pkg__msg__FandB__are_equal(const geneta_slam_ros2_pkg__msg__FandB * lhs, const geneta_slam_ros2_pkg__msg__FandB * rhs);

/// Copy a msg/FandB message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_geneta_slam_ros2_pkg
bool
geneta_slam_ros2_pkg__msg__FandB__copy(
  const geneta_slam_ros2_pkg__msg__FandB * input,
  geneta_slam_ros2_pkg__msg__FandB * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_geneta_slam_ros2_pkg
const rosidl_type_hash_t *
geneta_slam_ros2_pkg__msg__FandB__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_geneta_slam_ros2_pkg
const rosidl_runtime_c__type_description__TypeDescription *
geneta_slam_ros2_pkg__msg__FandB__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_geneta_slam_ros2_pkg
const rosidl_runtime_c__type_description__TypeSource *
geneta_slam_ros2_pkg__msg__FandB__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_geneta_slam_ros2_pkg
const rosidl_runtime_c__type_description__TypeSource__Sequence *
geneta_slam_ros2_pkg__msg__FandB__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/FandB messages.
/**
 * It allocates the memory for the number of elements and calls
 * geneta_slam_ros2_pkg__msg__FandB__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_geneta_slam_ros2_pkg
bool
geneta_slam_ros2_pkg__msg__FandB__Sequence__init(geneta_slam_ros2_pkg__msg__FandB__Sequence * array, size_t size);

/// Finalize array of msg/FandB messages.
/**
 * It calls
 * geneta_slam_ros2_pkg__msg__FandB__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_geneta_slam_ros2_pkg
void
geneta_slam_ros2_pkg__msg__FandB__Sequence__fini(geneta_slam_ros2_pkg__msg__FandB__Sequence * array);

/// Create array of msg/FandB messages.
/**
 * It allocates the memory for the array and calls
 * geneta_slam_ros2_pkg__msg__FandB__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_geneta_slam_ros2_pkg
geneta_slam_ros2_pkg__msg__FandB__Sequence *
geneta_slam_ros2_pkg__msg__FandB__Sequence__create(size_t size);

/// Destroy array of msg/FandB messages.
/**
 * It calls
 * geneta_slam_ros2_pkg__msg__FandB__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_geneta_slam_ros2_pkg
void
geneta_slam_ros2_pkg__msg__FandB__Sequence__destroy(geneta_slam_ros2_pkg__msg__FandB__Sequence * array);

/// Check for msg/FandB message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_geneta_slam_ros2_pkg
bool
geneta_slam_ros2_pkg__msg__FandB__Sequence__are_equal(const geneta_slam_ros2_pkg__msg__FandB__Sequence * lhs, const geneta_slam_ros2_pkg__msg__FandB__Sequence * rhs);

/// Copy an array of msg/FandB messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_geneta_slam_ros2_pkg
bool
geneta_slam_ros2_pkg__msg__FandB__Sequence__copy(
  const geneta_slam_ros2_pkg__msg__FandB__Sequence * input,
  geneta_slam_ros2_pkg__msg__FandB__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // GENETA_SLAM_ROS2_PKG__MSG__DETAIL__FAND_B__FUNCTIONS_H_
