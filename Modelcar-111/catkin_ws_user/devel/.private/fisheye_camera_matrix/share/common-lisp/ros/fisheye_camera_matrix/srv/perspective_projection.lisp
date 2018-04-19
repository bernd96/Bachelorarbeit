; Auto-generated. Do not edit!


(cl:in-package fisheye_camera_matrix-srv)


;//! \htmlinclude perspective_projection-request.msg.html

(cl:defclass <perspective_projection-request> (roslisp-msg-protocol:ros-message)
  ((x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (y
    :reader y
    :initarg :y
    :type cl:float
    :initform 0.0))
)

(cl:defclass perspective_projection-request (<perspective_projection-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <perspective_projection-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'perspective_projection-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name fisheye_camera_matrix-srv:<perspective_projection-request> is deprecated: use fisheye_camera_matrix-srv:perspective_projection-request instead.")))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <perspective_projection-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fisheye_camera_matrix-srv:x-val is deprecated.  Use fisheye_camera_matrix-srv:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <perspective_projection-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fisheye_camera_matrix-srv:y-val is deprecated.  Use fisheye_camera_matrix-srv:y instead.")
  (y m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <perspective_projection-request>) ostream)
  "Serializes a message object of type '<perspective_projection-request>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <perspective_projection-request>) istream)
  "Deserializes a message object of type '<perspective_projection-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<perspective_projection-request>)))
  "Returns string type for a service object of type '<perspective_projection-request>"
  "fisheye_camera_matrix/perspective_projectionRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'perspective_projection-request)))
  "Returns string type for a service object of type 'perspective_projection-request"
  "fisheye_camera_matrix/perspective_projectionRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<perspective_projection-request>)))
  "Returns md5sum for a message object of type '<perspective_projection-request>"
  "fac65d0011a9cb3cb4a513954c0b38a5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'perspective_projection-request)))
  "Returns md5sum for a message object of type 'perspective_projection-request"
  "fac65d0011a9cb3cb4a513954c0b38a5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<perspective_projection-request>)))
  "Returns full string definition for message of type '<perspective_projection-request>"
  (cl:format cl:nil "float32 x~%float32 y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'perspective_projection-request)))
  "Returns full string definition for message of type 'perspective_projection-request"
  (cl:format cl:nil "float32 x~%float32 y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <perspective_projection-request>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <perspective_projection-request>))
  "Converts a ROS message object to a list"
  (cl:list 'perspective_projection-request
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
))
;//! \htmlinclude perspective_projection-response.msg.html

(cl:defclass <perspective_projection-response> (roslisp-msg-protocol:ros-message)
  ((p
    :reader p
    :initarg :p
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point)))
)

(cl:defclass perspective_projection-response (<perspective_projection-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <perspective_projection-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'perspective_projection-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name fisheye_camera_matrix-srv:<perspective_projection-response> is deprecated: use fisheye_camera_matrix-srv:perspective_projection-response instead.")))

(cl:ensure-generic-function 'p-val :lambda-list '(m))
(cl:defmethod p-val ((m <perspective_projection-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fisheye_camera_matrix-srv:p-val is deprecated.  Use fisheye_camera_matrix-srv:p instead.")
  (p m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <perspective_projection-response>) ostream)
  "Serializes a message object of type '<perspective_projection-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'p) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <perspective_projection-response>) istream)
  "Deserializes a message object of type '<perspective_projection-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'p) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<perspective_projection-response>)))
  "Returns string type for a service object of type '<perspective_projection-response>"
  "fisheye_camera_matrix/perspective_projectionResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'perspective_projection-response)))
  "Returns string type for a service object of type 'perspective_projection-response"
  "fisheye_camera_matrix/perspective_projectionResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<perspective_projection-response>)))
  "Returns md5sum for a message object of type '<perspective_projection-response>"
  "fac65d0011a9cb3cb4a513954c0b38a5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'perspective_projection-response)))
  "Returns md5sum for a message object of type 'perspective_projection-response"
  "fac65d0011a9cb3cb4a513954c0b38a5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<perspective_projection-response>)))
  "Returns full string definition for message of type '<perspective_projection-response>"
  (cl:format cl:nil "geometry_msgs/Point p~%~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'perspective_projection-response)))
  "Returns full string definition for message of type 'perspective_projection-response"
  (cl:format cl:nil "geometry_msgs/Point p~%~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <perspective_projection-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'p))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <perspective_projection-response>))
  "Converts a ROS message object to a list"
  (cl:list 'perspective_projection-response
    (cl:cons ':p (p msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'perspective_projection)))
  'perspective_projection-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'perspective_projection)))
  'perspective_projection-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'perspective_projection)))
  "Returns string type for a service object of type '<perspective_projection>"
  "fisheye_camera_matrix/perspective_projection")