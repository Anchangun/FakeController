cmake_minimum_required(VERSION 3.5)
project(fake_controller)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories(
  include
  include/${PROJECT_NAME}
)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(tf2_ros REQUIRED)

add_executable(fake_controller_node 
  src/main.cpp
  src/FakeController.cpp
  src/constants.cpp
)

ament_target_dependencies(fake_controller_node 
rclcpp 
std_msgs 
geometry_msgs 
sensor_msgs
nav_msgs
tf2_ros
)

install(TARGETS
  fake_controller_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
