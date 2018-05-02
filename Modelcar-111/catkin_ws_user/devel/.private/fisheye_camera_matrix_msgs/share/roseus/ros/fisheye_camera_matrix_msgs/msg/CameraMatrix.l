;; Auto-generated. Do not edit!


(when (boundp 'fisheye_camera_matrix_msgs::CameraMatrix)
  (if (not (find-package "FISHEYE_CAMERA_MATRIX_MSGS"))
    (make-package "FISHEYE_CAMERA_MATRIX_MSGS"))
  (shadow 'CameraMatrix (find-package "FISHEYE_CAMERA_MATRIX_MSGS")))
(unless (find-package "FISHEYE_CAMERA_MATRIX_MSGS::CAMERAMATRIX")
  (make-package "FISHEYE_CAMERA_MATRIX_MSGS::CAMERAMATRIX"))

(in-package "ROS")
;;//! \htmlinclude CameraMatrix.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass fisheye_camera_matrix_msgs::CameraMatrix
  :super ros::object
  :slots (_header _width _height _cx _cy _fl _h _scale ))

(defmethod fisheye_camera_matrix_msgs::CameraMatrix
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:width __width) 0)
    ((:height __height) 0)
    ((:cx __cx) 0)
    ((:cy __cy) 0)
    ((:fl __fl) 0.0)
    ((:h __h) 0.0)
    ((:scale __scale) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _width (round __width))
   (setq _height (round __height))
   (setq _cx (round __cx))
   (setq _cy (round __cy))
   (setq _fl (float __fl))
   (setq _h (float __h))
   (setq _scale (float __scale))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:width
   (&optional __width)
   (if __width (setq _width __width)) _width)
  (:height
   (&optional __height)
   (if __height (setq _height __height)) _height)
  (:cx
   (&optional __cx)
   (if __cx (setq _cx __cx)) _cx)
  (:cy
   (&optional __cy)
   (if __cy (setq _cy __cy)) _cy)
  (:fl
   (&optional __fl)
   (if __fl (setq _fl __fl)) _fl)
  (:h
   (&optional __h)
   (if __h (setq _h __h)) _h)
  (:scale
   (&optional __scale)
   (if __scale (setq _scale __scale)) _scale)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint32 _width
    4
    ;; uint32 _height
    4
    ;; uint32 _cx
    4
    ;; uint32 _cy
    4
    ;; float32 _fl
    4
    ;; float32 _h
    4
    ;; float32 _scale
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint32 _width
       (write-long _width s)
     ;; uint32 _height
       (write-long _height s)
     ;; uint32 _cx
       (write-long _cx s)
     ;; uint32 _cy
       (write-long _cy s)
     ;; float32 _fl
       (sys::poke _fl (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _h
       (sys::poke _h (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _scale
       (sys::poke _scale (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint32 _width
     (setq _width (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _height
     (setq _height (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _cx
     (setq _cx (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _cy
     (setq _cy (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float32 _fl
     (setq _fl (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _h
     (setq _h (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _scale
     (setq _scale (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get fisheye_camera_matrix_msgs::CameraMatrix :md5sum-) "9120b07de3b326589888599ebcf42e75")
(setf (get fisheye_camera_matrix_msgs::CameraMatrix :datatype-) "fisheye_camera_matrix_msgs/CameraMatrix")
(setf (get fisheye_camera_matrix_msgs::CameraMatrix :definition-)
      "Header header
uint32 width
uint32 height
uint32 cx
uint32 cy
float32 fl
float32 h
float32 scale
================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

")



(provide :fisheye_camera_matrix_msgs/CameraMatrix "9120b07de3b326589888599ebcf42e75")


