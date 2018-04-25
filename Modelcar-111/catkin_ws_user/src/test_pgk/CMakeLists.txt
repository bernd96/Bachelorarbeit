cmake_minimum_required(VERSION 2.8.3)
project(test_pgk)

add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  std_msgs
  fub_trajectory_msgs
  nav_msgs
  roscpp
)
catkin_package()
##to find header files
include_directories(
        "src/"
)
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker test_pgk_generate_messages_cpp)

add_executable(sub src/sub.cpp)
target_link_libraries(sub ${catkin_LIBRARIES})
add_dependencies(sub test_pgk_generate_messages_cpp)