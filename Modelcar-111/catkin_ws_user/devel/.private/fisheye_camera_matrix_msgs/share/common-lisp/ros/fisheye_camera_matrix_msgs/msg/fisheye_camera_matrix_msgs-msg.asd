
(cl:in-package :asdf)

(defsystem "fisheye_camera_matrix_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "CameraMatrix" :depends-on ("_package_CameraMatrix"))
    (:file "_package_CameraMatrix" :depends-on ("_package"))
  ))