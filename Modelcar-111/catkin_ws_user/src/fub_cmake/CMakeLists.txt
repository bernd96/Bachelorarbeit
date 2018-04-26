cmake_minimum_required(VERSION 2.8.3)
project(fub_cmake)

find_package(catkin REQUIRED)

catkin_package(CFG_EXTRAS fub_cmake-extras.cmake)

# install cmake files
install(
	DIRECTORY cmake/Modules
	DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/cmake
)
