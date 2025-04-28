# generated from ament_cmake_export_include_directories/cmake/ament_cmake_export_include_directories-extras.cmake.in

set(_exported_include_dirs "${geneta_slam_ros2_pkg_DIR}/../../../include/geneta_slam_ros2_pkg")

# append include directories to geneta_slam_ros2_pkg_INCLUDE_DIRS
# warn about not existing paths
if(NOT _exported_include_dirs STREQUAL "")
  find_package(ament_cmake_core QUIET REQUIRED)
  foreach(_exported_include_dir ${_exported_include_dirs})
    if(NOT IS_DIRECTORY "${_exported_include_dir}")
      message(WARNING "Package 'geneta_slam_ros2_pkg' exports the include directory '${_exported_include_dir}' which doesn't exist")
    endif()
    normalize_path(_exported_include_dir "${_exported_include_dir}")
    list(APPEND geneta_slam_ros2_pkg_INCLUDE_DIRS "${_exported_include_dir}")
  endforeach()
endif()
