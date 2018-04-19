;; Auto-generated. Do not edit!


(when (boundp 'fisheye_camera_matrix::perspective_projection)
  (if (not (find-package "FISHEYE_CAMERA_MATRIX"))
    (make-package "FISHEYE_CAMERA_MATRIX"))
  (shadow 'perspective_projection (find-package "FISHEYE_CAMERA_MATRIX")))
(unless (find-package "FISHEYE_CAMERA_MATRIX::PERSPECTIVE_PROJECTION")
  (make-package "FISHEYE_CAMERA_MATRIX::PERSPECTIVE_PROJECTION"))
(unless (find-package "FISHEYE_CAMERA_MATRIX::PERSPECTIVE_PROJECTIONREQUEST")
  (make-package "FISHEYE_CAMERA_MATRIX::PERSPECTIVE_PROJECTIONREQUEST"))
(unless (find-package "FISHEYE_CAMERA_MATRIX::PERSPECTIVE_PROJECTIONRESPONSE")
  (make-package "FISHEYE_CAMERA_MATRIX::PERSPECTIVE_PROJECTIONRESPONSE"))

(in-package "ROS")



(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass fisheye_camera_matrix::perspective_projectionRequest
  :super ros::object
  :slots (_x _y ))

(defmethod fisheye_camera_matrix::perspective_projectionRequest
  (:init
   (&key
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    )
   (send-super :init)
   (setq _x (float __x))
   (setq _y (float __y))
   self)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:serialization-length
   ()
   (+
    ;; float32 _x
    4
    ;; float32 _y
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _x
       (sys::poke _x (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _y
       (sys::poke _y (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _x
     (setq _x (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _y
     (setq _y (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass fisheye_camera_matrix::perspective_projectionResponse
  :super ros::object
  :slots (_p ))

(defmethod fisheye_camera_matrix::perspective_projectionResponse
  (:init
   (&key
    ((:p __p) (instance geometry_msgs::Point :init))
    )
   (send-super :init)
   (setq _p __p)
   self)
  (:p
   (&rest __p)
   (if (keywordp (car __p))
       (send* _p __p)
     (progn
       (if __p (setq _p (car __p)))
       _p)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Point _p
    (send _p :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Point _p
       (send _p :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Point _p
     (send _p :deserialize buf ptr-) (incf ptr- (send _p :serialization-length))
   ;;
   self)
  )

(defclass fisheye_camera_matrix::perspective_projection
  :super ros::object
  :slots ())

(setf (get fisheye_camera_matrix::perspective_projection :md5sum-) "fac65d0011a9cb3cb4a513954c0b38a5")
(setf (get fisheye_camera_matrix::perspective_projection :datatype-) "fisheye_camera_matrix/perspective_projection")
(setf (get fisheye_camera_matrix::perspective_projection :request) fisheye_camera_matrix::perspective_projectionRequest)
(setf (get fisheye_camera_matrix::perspective_projection :response) fisheye_camera_matrix::perspective_projectionResponse)

(defmethod fisheye_camera_matrix::perspective_projectionRequest
  (:response () (instance fisheye_camera_matrix::perspective_projectionResponse :init)))

(setf (get fisheye_camera_matrix::perspective_projectionRequest :md5sum-) "fac65d0011a9cb3cb4a513954c0b38a5")
(setf (get fisheye_camera_matrix::perspective_projectionRequest :datatype-) "fisheye_camera_matrix/perspective_projectionRequest")
(setf (get fisheye_camera_matrix::perspective_projectionRequest :definition-)
      "float32 x
float32 y
---
geometry_msgs/Point p


================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z
")

(setf (get fisheye_camera_matrix::perspective_projectionResponse :md5sum-) "fac65d0011a9cb3cb4a513954c0b38a5")
(setf (get fisheye_camera_matrix::perspective_projectionResponse :datatype-) "fisheye_camera_matrix/perspective_projectionResponse")
(setf (get fisheye_camera_matrix::perspective_projectionResponse :definition-)
      "float32 x
float32 y
---
geometry_msgs/Point p


================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z
")



(provide :fisheye_camera_matrix/perspective_projection "fac65d0011a9cb3cb4a513954c0b38a5")


