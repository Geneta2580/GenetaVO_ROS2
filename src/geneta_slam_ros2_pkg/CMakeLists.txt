cmake_minimum_required(VERSION 3.8)
project(geneta_slam_ros2_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


# 所有外部依赖
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(message_filters REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED) 
find_package(Sophus REQUIRED)
find_package(g2o REQUIRED COMPONENTS 
    core 
    solver_cholmod
    solver_csparse 
    types_sba
    csparse_extension
    cholmod_extension
)

find_package(nav_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)  # 如需处理几何消息转换
find_package(geometry_msgs REQUIRED)
find_package(backward_ros REQUIRED)

find_package(rosidl_default_generators REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rosidl_typesupport_fastrtps_cpp REQUIRED)  # 新增
find_package(rosidl_typesupport_cpp REQUIRED)

find_package(image_transport REQUIRED)
find_package(camera_info_manager REQUIRED)

# 几个节点的共有库
set(COMMON_DEPS 
  rclcpp 
  sensor_msgs
  cv_bridge
)

# ==================== 节点0: 相机发布节点 ====================
add_executable(stereo_cam_node  
  src/stereo_cam_node.cpp)

# 依赖配置
ament_target_dependencies(stereo_cam_node
  ${COMMON_DEPS}
)

# 链接到库
target_link_libraries(stereo_cam_node 
  ${OpenCV_LIBS}
  ${cv_bridge_LIBRARIES}
)

# 库头文件路径
target_include_directories(stereo_cam_node PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  "/usr/include/eigen3/"
)

ament_target_dependencies(stereo_cam_node
  rclcpp sensor_msgs cv_bridge image_transport camera_info_manager
)

# ==================== 节点1: 图像发布节点 ====================
add_executable(image_publisher  
  src/image_publisher.cpp)

# 依赖配置
ament_target_dependencies(image_publisher
  ${COMMON_DEPS}
)

# 链接到库
target_link_libraries(image_publisher 
  ${OpenCV_LIBS}
  ${cv_bridge_LIBRARIES}
)

# 库头文件路径
target_include_directories(image_publisher PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  "/usr/include/eigen3/"
)

# ==================== 节点2: 前端节点 ====================
add_executable(geneta_frontend
  src/slam_core/frontend.cpp  # 前端处理模块
  src/slam_core/camera.cpp    # 相机类
  src/slam_core/frame.cpp     # 帧类
  src/slam_core/mappoint.cpp  # 地图点类
  src/slam_core/dataset.cpp   # 数据集类
  src/slam_core/map.cpp       # 地图类
  src/slam_core/config.cpp    # 配置文件导入
)

# 生成消息的.hpp文件
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/FandB.msg"
  DEPENDENCIES 
    std_msgs 
    sensor_msgs 
    geometry_msgs 
    builtin_interfaces # 若使用Header需添加依赖 geometry_msgs
)

# 依赖配置
ament_target_dependencies(geneta_frontend
  ${COMMON_DEPS}
  message_filters
  nav_msgs
  tf2
  tf2_ros
  geometry_msgs  # 若涉及坐标变换消息

)

# 链接到库
target_link_libraries(geneta_frontend
  ${message_filters_LIBRARIES}
  ${cv_bridge_LIBRARIES}
  ${OpenCV_LIBS}
  ${g2o_LIBRARIES}  # 链接g2o组件库
  ${CSPARSE_LIBRARY}
  g2o_core g2o_stuff 
  g2o_types_sba 
  g2o_solver_csparse 
  g2o_csparse_extension
  g2o_solver_cholmod
  ${Sophus_LIBRARIES}
  Sophus::Sophus
  Eigen3::Eigen
  pthread

  ${tf2_LIBRARIES}
  ${tf2_ros_LIBRARIES}
  ${Pangolin_LIBRARIES}
  ${PROJECT_NAME}__rosidl_typesupport_cpp
  geneta_slam_ros2_pkg__rosidl_typesupport_fastrtps_cpp
)

# 库头文件路径
target_include_directories(geneta_frontend PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}/rosidl_generator_cpp   
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${OpenCV_INCLUDE_DIRS}
  ${Sophus_INCLUDE_DIRS}
  "/usr/include/eigen3/"
  ${g2o_INCLUDE_DIRS}

  ${tf2_INCLUDE_DIRS}
  ${tf2_ros_INCLUDE_DIRS}
  ${Pangolin_INCLUDE_DIRS}
  ${builtin_interfaces_INCLUDE_DIRS}
)

# # ==================== 节点3: 后端节点 ====================
# add_executable(geneta_backend
#   src/slam_core/backend.cpp   # 后端优化模块
#   src/slam_core/camera.cpp    # 相机类
#   src/slam_core/frame.cpp     # 帧类
#   src/slam_core/mappoint.cpp  # 地图点类
#   src/slam_core/dataset.cpp   # 数据集类
#   src/slam_core/map.cpp       # 地图类
#   src/slam_core/config.cpp    # 配置文件导入
# )

# # 依赖配置
# ament_target_dependencies(geneta_slam
#   ${COMMON_DEPS}
#   message_filters
#   nav_msgs
#   tf2
#   tf2_ros
#   geometry_msgs  # 若涉及坐标变换消息
# )

# # 链接到库
# target_link_libraries(geneta_slam
#   ${message_filters_LIBRARIES}
#   ${cv_bridge_LIBRARIES}
#   ${OpenCV_LIBS}
#   ${g2o_LIBRARIES}  # 链接g2o组件库
#   ${CSPARSE_LIBRARY}
#   g2o_core g2o_stuff 
#   g2o_types_sba 
#   g2o_solver_csparse 
#   g2o_csparse_extension
#   ${Sophus_LIBRARIES}
#   Sophus::Sophus
#   Eigen3::Eigen
#   pthread

#   ${tf2_LIBRARIES}
#   ${tf2_ros_LIBRARIES}
#   ${Pangolin_LIBRARIES}
# )

# # 库头文件路径
# target_include_directories(geneta_slam PRIVATE
#   ${CMAKE_CURRENT_SOURCE_DIR}/include
#   ${OpenCV_INCLUDE_DIRS}
#   ${Sophus_INCLUDE_DIRS}
#   "/usr/include/eigen3/"
#   ${g2o_INCLUDE_DIRS}

#   ${tf2_INCLUDE_DIRS}
#   ${tf2_ros_INCLUDE_DIRS}
#   ${Pangolin_INCLUDE_DIRS}
# )

# ==================== 节点3: 测试节点 ====================
# add_executable(test_node
#   src/slam_core/test_node.cpp  # 前端处理模块
# )

# 生成消息的.hpp文件
# rosidl_generate_interfaces(${PROJECT_NAME}
#   "msg/FandB.msg"
#   DEPENDENCIES 
#     std_msgs 
#     sensor_msgs 
#     geometry_msgs 
#     builtin_interfaces # 若使用Header需添加依赖 geometry_msgs
#   # TYPESUPPORT 
#   # rosidl_typesupport_fastrtps_cpp  # 显式指定类型支持
# )

# 依赖配置
# ament_target_dependencies(test_node
#   ${COMMON_DEPS}
#   message_filters
#   nav_msgs
#   tf2
#   tf2_ros
#   geometry_msgs  # 若涉及坐标变换消息

# )

# 链接到库
# target_link_libraries(test_node
#   ${message_filters_LIBRARIES}
#   ${cv_bridge_LIBRARIES}
#   ${OpenCV_LIBS}
#   ${g2o_LIBRARIES}  # 链接g2o组件库
#   ${CSPARSE_LIBRARY}
#   g2o_core g2o_stuff 
#   g2o_types_sba 
#   g2o_solver_csparse 
#   g2o_csparse_extension
#   ${Sophus_LIBRARIES}
#   Sophus::Sophus
#   Eigen3::Eigen
#   pthread

#   ${tf2_LIBRARIES}
#   ${tf2_ros_LIBRARIES}
#   ${Pangolin_LIBRARIES}
#   ${PROJECT_NAME}__rosidl_typesupport_cpp
#   geneta_slam_ros2_pkg__rosidl_typesupport_fastrtps_cpp
# )

# 库头文件路径
# target_include_directories(test_node PRIVATE
#   ${CMAKE_CURRENT_BINARY_DIR}/rosidl_generator_cpp   
#   # ${CMAKE_CURRENT_BINARY_DIR}/rosidl_typesupport_cpp 
#   ${CMAKE_CURRENT_SOURCE_DIR}/include
#   ${OpenCV_INCLUDE_DIRS}
#   ${Sophus_INCLUDE_DIRS}
#   "/usr/include/eigen3/"
#   ${g2o_INCLUDE_DIRS}

#   ${tf2_INCLUDE_DIRS}
#   ${tf2_ros_INCLUDE_DIRS}
#   ${Pangolin_INCLUDE_DIRS}
#   ${builtin_interfaces_INCLUDE_DIRS}
# )

install(TARGETS
  image_publisher
  geneta_frontend
  stereo_cam_node
  # geneta_backend
  # test_node
  DESTINATION lib/${PROJECT_NAME}
)


# ==================== 测试配置 ====================
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# set(RMW_IMPLEMENTATION rmw_fastrtps_cpp CACHE STRING "Middleware implementation")
ament_export_dependencies(rosidl_default_runtime)
ament_package()
