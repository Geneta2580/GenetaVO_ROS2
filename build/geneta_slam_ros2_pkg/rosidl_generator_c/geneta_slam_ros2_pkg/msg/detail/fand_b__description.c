// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from geneta_slam_ros2_pkg:msg/FandB.idl
// generated code does not contain a copyright notice

#include "geneta_slam_ros2_pkg/msg/detail/fand_b__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_geneta_slam_ros2_pkg
const rosidl_type_hash_t *
geneta_slam_ros2_pkg__msg__FandB__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd6, 0x26, 0x6f, 0xb4, 0xdd, 0x72, 0x11, 0xf8,
      0x74, 0x01, 0x61, 0xb4, 0x47, 0xbd, 0x0e, 0xb1,
      0xb9, 0x97, 0xdc, 0x44, 0x59, 0x35, 0x44, 0xdc,
      0xc6, 0xec, 0x01, 0x57, 0x20, 0x61, 0x91, 0xc2,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "geometry_msgs/msg/detail/point__functions.h"
#include "geometry_msgs/msg/detail/quaternion__functions.h"
#include "geometry_msgs/msg/detail/pose__functions.h"
#include "std_msgs/msg/detail/header__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Point__EXPECTED_HASH = {1, {
    0x69, 0x63, 0x08, 0x48, 0x42, 0xa9, 0xb0, 0x44,
    0x94, 0xd6, 0xb2, 0x94, 0x1d, 0x11, 0x44, 0x47,
    0x08, 0xd8, 0x92, 0xda, 0x2f, 0x4b, 0x09, 0x84,
    0x3b, 0x9c, 0x43, 0xf4, 0x2a, 0x7f, 0x68, 0x81,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Pose__EXPECTED_HASH = {1, {
    0xd5, 0x01, 0x95, 0x4e, 0x94, 0x76, 0xce, 0xa2,
    0x99, 0x69, 0x84, 0xe8, 0x12, 0x05, 0x4b, 0x68,
    0x02, 0x6a, 0xe0, 0xbf, 0xae, 0x78, 0x9d, 0x9a,
    0x10, 0xb2, 0x3d, 0xaf, 0x35, 0xcc, 0x90, 0xfa,
  }};
static const rosidl_type_hash_t geometry_msgs__msg__Quaternion__EXPECTED_HASH = {1, {
    0x8a, 0x76, 0x5f, 0x66, 0x77, 0x8c, 0x8f, 0xf7,
    0xc8, 0xab, 0x94, 0xaf, 0xcc, 0x59, 0x0a, 0x2e,
    0xd5, 0x32, 0x5a, 0x1d, 0x9a, 0x07, 0x6f, 0xff,
    0xf3, 0x8f, 0xbc, 0xe3, 0x6f, 0x45, 0x86, 0x84,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char geneta_slam_ros2_pkg__msg__FandB__TYPE_NAME[] = "geneta_slam_ros2_pkg/msg/FandB";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";
static char geometry_msgs__msg__Pose__TYPE_NAME[] = "geometry_msgs/msg/Pose";
static char geometry_msgs__msg__Quaternion__TYPE_NAME[] = "geometry_msgs/msg/Quaternion";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char geneta_slam_ros2_pkg__msg__FandB__FIELD_NAME__header[] = "header";
static char geneta_slam_ros2_pkg__msg__FandB__FIELD_NAME__u[] = "u";
static char geneta_slam_ros2_pkg__msg__FandB__FIELD_NAME__v[] = "v";
static char geneta_slam_ros2_pkg__msg__FandB__FIELD_NAME__landmark_ids[] = "landmark_ids";
static char geneta_slam_ros2_pkg__msg__FandB__FIELD_NAME__x[] = "x";
static char geneta_slam_ros2_pkg__msg__FandB__FIELD_NAME__y[] = "y";
static char geneta_slam_ros2_pkg__msg__FandB__FIELD_NAME__z[] = "z";
static char geneta_slam_ros2_pkg__msg__FandB__FIELD_NAME__pose[] = "pose";

static rosidl_runtime_c__type_description__Field geneta_slam_ros2_pkg__msg__FandB__FIELDS[] = {
  {
    {geneta_slam_ros2_pkg__msg__FandB__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {geneta_slam_ros2_pkg__msg__FandB__FIELD_NAME__u, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {geneta_slam_ros2_pkg__msg__FandB__FIELD_NAME__v, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {geneta_slam_ros2_pkg__msg__FandB__FIELD_NAME__landmark_ids, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {geneta_slam_ros2_pkg__msg__FandB__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {geneta_slam_ros2_pkg__msg__FandB__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {geneta_slam_ros2_pkg__msg__FandB__FIELD_NAME__z, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {geneta_slam_ros2_pkg__msg__FandB__FIELD_NAME__pose, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Pose__TYPE_NAME, 22, 22},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription geneta_slam_ros2_pkg__msg__FandB__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Pose__TYPE_NAME, 22, 22},
    {NULL, 0, 0},
  },
  {
    {geometry_msgs__msg__Quaternion__TYPE_NAME, 28, 28},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
geneta_slam_ros2_pkg__msg__FandB__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {geneta_slam_ros2_pkg__msg__FandB__TYPE_NAME, 30, 30},
      {geneta_slam_ros2_pkg__msg__FandB__FIELDS, 8, 8},
    },
    {geneta_slam_ros2_pkg__msg__FandB__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Pose__EXPECTED_HASH, geometry_msgs__msg__Pose__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = geometry_msgs__msg__Pose__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&geometry_msgs__msg__Quaternion__EXPECTED_HASH, geometry_msgs__msg__Quaternion__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = geometry_msgs__msg__Quaternion__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# \\xe5\\x9f\\xba\\xe7\\xa1\\x80\\xe4\\xbf\\xa1\\xe6\\x81\\xaf\\xe5\\xa4\\xb4\\xef\\xbc\\x88\\xe6\\x97\\xb6\\xe9\\x97\\xb4\\xe6\\x88\\xb3+\\xe5\\x9d\\x90\\xe6\\xa0\\x87\\xe7\\xb3\\xbb\\xef\\xbc\\x89\n"
  "std_msgs/Header header\n"
  "\n"
  "# \\xe7\\x89\\xb9\\xe5\\xbe\\x81\\xe7\\x82\\xb9\\xe4\\xbf\\xa1\\xe6\\x81\\xaf\n"
  "# int32[] frame_ids         # \\xe5\\xbd\\x93\\xe5\\x89\\x8d\\xe5\\xb8\\xa7\\xe7\\x9a\\x84ID\n"
  "# int32[] feature_ids       # \\xe7\\x89\\xb9\\xe5\\xbe\\x81\\xe7\\x82\\xb9ID\\xe6\\x95\\xb0\\xe7\\xbb\\x84\n"
  "# int32[] belong_landmark_ids      # \\xe6\\x8c\\x81\\xe6\\x9c\\x89\\xe8\\xaf\\xa5\\xe7\\x89\\xb9\\xe5\\xbe\\x81\\xe7\\x82\\xb9\\xe7\\x9a\\x84\\xe8\\xb7\\xaf\\xe6\\xa0\\x87\\xe7\\x82\\xb9ID\\xe6\\x95\\xb0\\xe7\\xbb\\x84\n"
  "float32[] u       # \\xe7\\x89\\xb9\\xe5\\xbe\\x81\\xe7\\x82\\xb9\\xe5\\x9b\\xbe\\xe5\\x83\\x8f\\xe5\\x9d\\x90\\xe6\\xa0\\x87X\n"
  "float32[] v       # \\xe5\\x9b\\xbe\\xe5\\x83\\x8f\\xe5\\x9d\\x90\\xe6\\xa0\\x87Y\n"
  "\n"
  "# \\xe5\\xaf\\xb9\\xe5\\xba\\x94\\xe8\\xb7\\xaf\\xe6\\xa0\\x87\\xe7\\x82\\xb9\\xe4\\xbf\\xa1\\xe6\\x81\\xaf\\xef\\xbc\\x88\\xe4\\xb8\\x96\\xe7\\x95\\x8c\\xe5\\x9d\\x90\\xe6\\xa0\\x87\\xe7\\xb3\\xbb\\xef\\xbc\\x89\n"
  "int32[] landmark_ids       # \\xe8\\xb7\\xaf\\xe6\\xa0\\x87\\xe7\\x82\\xb9ID\n"
  "float64[] x                # \\xe4\\xb8\\x89\\xe7\\xbb\\xb4\\xe5\\x9d\\x90\\xe6\\xa0\\x87X\n"
  "float64[] y                # Y\n"
  "float64[] z                # Z\n"
  "\n"
  "# \\xe9\\x87\\x8c\\xe7\\xa8\\x8b\\xe8\\xae\\xa1\\xe6\\x95\\xb0\\xe6\\x8d\\xae\\xef\\xbc\\x88\\xe4\\xbd\\x8d\\xe7\\xbd\\xae+\\xe6\\x96\\xb9\\xe5\\x90\\x91\\xef\\xbc\\x89\n"
  "geometry_msgs/Pose pose\n"
  "\n"
  "# uint32 seq_id";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
geneta_slam_ros2_pkg__msg__FandB__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {geneta_slam_ros2_pkg__msg__FandB__TYPE_NAME, 30, 30},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 437, 437},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
geneta_slam_ros2_pkg__msg__FandB__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *geneta_slam_ros2_pkg__msg__FandB__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    sources[3] = *geometry_msgs__msg__Pose__get_individual_type_description_source(NULL);
    sources[4] = *geometry_msgs__msg__Quaternion__get_individual_type_description_source(NULL);
    sources[5] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
