# Install script for directory: /home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs_rviz_plugin

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/install/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/install" TYPE PROGRAM FILES "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/build/fub_trajectory_msgs_rviz_plugin/catkin_generated/installspace/_setup_util.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/install/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/install" TYPE PROGRAM FILES "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/build/fub_trajectory_msgs_rviz_plugin/catkin_generated/installspace/env.sh")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/install/setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/install" TYPE FILE FILES "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/build/fub_trajectory_msgs_rviz_plugin/catkin_generated/installspace/setup.bash")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/install/setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/install" TYPE FILE FILES "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/build/fub_trajectory_msgs_rviz_plugin/catkin_generated/installspace/setup.sh")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/install/setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/install" TYPE FILE FILES "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/build/fub_trajectory_msgs_rviz_plugin/catkin_generated/installspace/setup.zsh")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/install/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/install" TYPE FILE FILES "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/build/fub_trajectory_msgs_rviz_plugin/catkin_generated/installspace/.rosinstall")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/build/fub_trajectory_msgs_rviz_plugin/catkin_generated/installspace/fub_trajectory_msgs_rviz_plugin.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/fub_trajectory_msgs_rviz_plugin/cmake" TYPE FILE FILES
    "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/build/fub_trajectory_msgs_rviz_plugin/catkin_generated/installspace/fub_trajectory_msgs_rviz_pluginConfig.cmake"
    "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/build/fub_trajectory_msgs_rviz_plugin/catkin_generated/installspace/fub_trajectory_msgs_rviz_pluginConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/fub_trajectory_msgs_rviz_plugin" TYPE FILE FILES "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs_rviz_plugin/package.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfub_trajectory_msgs_rviz_plugin.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfub_trajectory_msgs_rviz_plugin.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfub_trajectory_msgs_rviz_plugin.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/devel/.private/fub_trajectory_msgs_rviz_plugin/lib/libfub_trajectory_msgs_rviz_plugin.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfub_trajectory_msgs_rviz_plugin.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfub_trajectory_msgs_rviz_plugin.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfub_trajectory_msgs_rviz_plugin.so"
         OLD_RPATH "/opt/ros/kinetic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libfub_trajectory_msgs_rviz_plugin.so")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/fub_trajectory_msgs_rviz_plugin" TYPE FILE FILES "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs_rviz_plugin/plugin_description.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/fub_trajectory_msgs_rviz_plugin/icons" TYPE DIRECTORY FILES "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs_rviz_plugin/icons/")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/fub_trajectory_msgs_rviz_plugin" TYPE PROGRAM FILES "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs_rviz_plugin/scripts/send_test_trajectory_msg.py")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/build/fub_trajectory_msgs_rviz_plugin/gtest/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/build/fub_trajectory_msgs_rviz_plugin/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
