# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "fisheye_camera_matrix_msgs: 1 messages, 0 services")

set(MSG_I_FLAGS "-Ifisheye_camera_matrix_msgs:/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fisheye_camera_matrix_msgs/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(fisheye_camera_matrix_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fisheye_camera_matrix_msgs/msg/CameraMatrix.msg" NAME_WE)
add_custom_target(_fisheye_camera_matrix_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fisheye_camera_matrix_msgs" "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fisheye_camera_matrix_msgs/msg/CameraMatrix.msg" "std_msgs/Header"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(fisheye_camera_matrix_msgs
  "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fisheye_camera_matrix_msgs/msg/CameraMatrix.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fisheye_camera_matrix_msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(fisheye_camera_matrix_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fisheye_camera_matrix_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(fisheye_camera_matrix_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(fisheye_camera_matrix_msgs_generate_messages fisheye_camera_matrix_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fisheye_camera_matrix_msgs/msg/CameraMatrix.msg" NAME_WE)
add_dependencies(fisheye_camera_matrix_msgs_generate_messages_cpp _fisheye_camera_matrix_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(fisheye_camera_matrix_msgs_gencpp)
add_dependencies(fisheye_camera_matrix_msgs_gencpp fisheye_camera_matrix_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS fisheye_camera_matrix_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(fisheye_camera_matrix_msgs
  "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fisheye_camera_matrix_msgs/msg/CameraMatrix.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fisheye_camera_matrix_msgs
)

### Generating Services

### Generating Module File
_generate_module_eus(fisheye_camera_matrix_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fisheye_camera_matrix_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(fisheye_camera_matrix_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(fisheye_camera_matrix_msgs_generate_messages fisheye_camera_matrix_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fisheye_camera_matrix_msgs/msg/CameraMatrix.msg" NAME_WE)
add_dependencies(fisheye_camera_matrix_msgs_generate_messages_eus _fisheye_camera_matrix_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(fisheye_camera_matrix_msgs_geneus)
add_dependencies(fisheye_camera_matrix_msgs_geneus fisheye_camera_matrix_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS fisheye_camera_matrix_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(fisheye_camera_matrix_msgs
  "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fisheye_camera_matrix_msgs/msg/CameraMatrix.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fisheye_camera_matrix_msgs
)

### Generating Services

### Generating Module File
_generate_module_lisp(fisheye_camera_matrix_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fisheye_camera_matrix_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(fisheye_camera_matrix_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(fisheye_camera_matrix_msgs_generate_messages fisheye_camera_matrix_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fisheye_camera_matrix_msgs/msg/CameraMatrix.msg" NAME_WE)
add_dependencies(fisheye_camera_matrix_msgs_generate_messages_lisp _fisheye_camera_matrix_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(fisheye_camera_matrix_msgs_genlisp)
add_dependencies(fisheye_camera_matrix_msgs_genlisp fisheye_camera_matrix_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS fisheye_camera_matrix_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(fisheye_camera_matrix_msgs
  "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fisheye_camera_matrix_msgs/msg/CameraMatrix.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fisheye_camera_matrix_msgs
)

### Generating Services

### Generating Module File
_generate_module_nodejs(fisheye_camera_matrix_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fisheye_camera_matrix_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(fisheye_camera_matrix_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(fisheye_camera_matrix_msgs_generate_messages fisheye_camera_matrix_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fisheye_camera_matrix_msgs/msg/CameraMatrix.msg" NAME_WE)
add_dependencies(fisheye_camera_matrix_msgs_generate_messages_nodejs _fisheye_camera_matrix_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(fisheye_camera_matrix_msgs_gennodejs)
add_dependencies(fisheye_camera_matrix_msgs_gennodejs fisheye_camera_matrix_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS fisheye_camera_matrix_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(fisheye_camera_matrix_msgs
  "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fisheye_camera_matrix_msgs/msg/CameraMatrix.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fisheye_camera_matrix_msgs
)

### Generating Services

### Generating Module File
_generate_module_py(fisheye_camera_matrix_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fisheye_camera_matrix_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(fisheye_camera_matrix_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(fisheye_camera_matrix_msgs_generate_messages fisheye_camera_matrix_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fisheye_camera_matrix_msgs/msg/CameraMatrix.msg" NAME_WE)
add_dependencies(fisheye_camera_matrix_msgs_generate_messages_py _fisheye_camera_matrix_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(fisheye_camera_matrix_msgs_genpy)
add_dependencies(fisheye_camera_matrix_msgs_genpy fisheye_camera_matrix_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS fisheye_camera_matrix_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fisheye_camera_matrix_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fisheye_camera_matrix_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(fisheye_camera_matrix_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fisheye_camera_matrix_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fisheye_camera_matrix_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(fisheye_camera_matrix_msgs_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fisheye_camera_matrix_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fisheye_camera_matrix_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(fisheye_camera_matrix_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fisheye_camera_matrix_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fisheye_camera_matrix_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(fisheye_camera_matrix_msgs_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fisheye_camera_matrix_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fisheye_camera_matrix_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fisheye_camera_matrix_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(fisheye_camera_matrix_msgs_generate_messages_py std_msgs_generate_messages_py)
endif()
