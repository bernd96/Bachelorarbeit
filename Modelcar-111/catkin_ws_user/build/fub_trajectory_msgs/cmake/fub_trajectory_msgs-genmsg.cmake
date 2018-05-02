# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "fub_trajectory_msgs: 2 messages, 0 services")

set(MSG_I_FLAGS "-Ifub_trajectory_msgs:/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(fub_trajectory_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/Trajectory.msg" NAME_WE)
add_custom_target(_fub_trajectory_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fub_trajectory_msgs" "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/Trajectory.msg" "geometry_msgs/Twist:std_msgs/Header:geometry_msgs/Quaternion:geometry_msgs/Point:geometry_msgs/Vector3:fub_trajectory_msgs/TrajectoryPoint:geometry_msgs/Pose"
)

get_filename_component(_filename "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/TrajectoryPoint.msg" NAME_WE)
add_custom_target(_fub_trajectory_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fub_trajectory_msgs" "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/TrajectoryPoint.msg" "geometry_msgs/Quaternion:geometry_msgs/Pose:geometry_msgs/Twist:geometry_msgs/Point:geometry_msgs/Vector3"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(fub_trajectory_msgs
  "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/Trajectory.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/TrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fub_trajectory_msgs
)
_generate_msg_cpp(fub_trajectory_msgs
  "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/TrajectoryPoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fub_trajectory_msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(fub_trajectory_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fub_trajectory_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(fub_trajectory_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(fub_trajectory_msgs_generate_messages fub_trajectory_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/Trajectory.msg" NAME_WE)
add_dependencies(fub_trajectory_msgs_generate_messages_cpp _fub_trajectory_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/TrajectoryPoint.msg" NAME_WE)
add_dependencies(fub_trajectory_msgs_generate_messages_cpp _fub_trajectory_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(fub_trajectory_msgs_gencpp)
add_dependencies(fub_trajectory_msgs_gencpp fub_trajectory_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS fub_trajectory_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(fub_trajectory_msgs
  "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/Trajectory.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/TrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fub_trajectory_msgs
)
_generate_msg_eus(fub_trajectory_msgs
  "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/TrajectoryPoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fub_trajectory_msgs
)

### Generating Services

### Generating Module File
_generate_module_eus(fub_trajectory_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fub_trajectory_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(fub_trajectory_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(fub_trajectory_msgs_generate_messages fub_trajectory_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/Trajectory.msg" NAME_WE)
add_dependencies(fub_trajectory_msgs_generate_messages_eus _fub_trajectory_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/TrajectoryPoint.msg" NAME_WE)
add_dependencies(fub_trajectory_msgs_generate_messages_eus _fub_trajectory_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(fub_trajectory_msgs_geneus)
add_dependencies(fub_trajectory_msgs_geneus fub_trajectory_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS fub_trajectory_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(fub_trajectory_msgs
  "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/Trajectory.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/TrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fub_trajectory_msgs
)
_generate_msg_lisp(fub_trajectory_msgs
  "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/TrajectoryPoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fub_trajectory_msgs
)

### Generating Services

### Generating Module File
_generate_module_lisp(fub_trajectory_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fub_trajectory_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(fub_trajectory_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(fub_trajectory_msgs_generate_messages fub_trajectory_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/Trajectory.msg" NAME_WE)
add_dependencies(fub_trajectory_msgs_generate_messages_lisp _fub_trajectory_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/TrajectoryPoint.msg" NAME_WE)
add_dependencies(fub_trajectory_msgs_generate_messages_lisp _fub_trajectory_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(fub_trajectory_msgs_genlisp)
add_dependencies(fub_trajectory_msgs_genlisp fub_trajectory_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS fub_trajectory_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(fub_trajectory_msgs
  "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/Trajectory.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/TrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fub_trajectory_msgs
)
_generate_msg_nodejs(fub_trajectory_msgs
  "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/TrajectoryPoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fub_trajectory_msgs
)

### Generating Services

### Generating Module File
_generate_module_nodejs(fub_trajectory_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fub_trajectory_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(fub_trajectory_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(fub_trajectory_msgs_generate_messages fub_trajectory_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/Trajectory.msg" NAME_WE)
add_dependencies(fub_trajectory_msgs_generate_messages_nodejs _fub_trajectory_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/TrajectoryPoint.msg" NAME_WE)
add_dependencies(fub_trajectory_msgs_generate_messages_nodejs _fub_trajectory_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(fub_trajectory_msgs_gennodejs)
add_dependencies(fub_trajectory_msgs_gennodejs fub_trajectory_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS fub_trajectory_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(fub_trajectory_msgs
  "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/Trajectory.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/TrajectoryPoint.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fub_trajectory_msgs
)
_generate_msg_py(fub_trajectory_msgs
  "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/TrajectoryPoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fub_trajectory_msgs
)

### Generating Services

### Generating Module File
_generate_module_py(fub_trajectory_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fub_trajectory_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(fub_trajectory_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(fub_trajectory_msgs_generate_messages fub_trajectory_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/Trajectory.msg" NAME_WE)
add_dependencies(fub_trajectory_msgs_generate_messages_py _fub_trajectory_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mi/besahre/Documents/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fub_trajectory_msgs/msg/TrajectoryPoint.msg" NAME_WE)
add_dependencies(fub_trajectory_msgs_generate_messages_py _fub_trajectory_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(fub_trajectory_msgs_genpy)
add_dependencies(fub_trajectory_msgs_genpy fub_trajectory_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS fub_trajectory_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fub_trajectory_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fub_trajectory_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(fub_trajectory_msgs_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fub_trajectory_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fub_trajectory_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(fub_trajectory_msgs_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fub_trajectory_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fub_trajectory_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(fub_trajectory_msgs_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fub_trajectory_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fub_trajectory_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(fub_trajectory_msgs_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fub_trajectory_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fub_trajectory_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fub_trajectory_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(fub_trajectory_msgs_generate_messages_py geometry_msgs_generate_messages_py)
endif()
