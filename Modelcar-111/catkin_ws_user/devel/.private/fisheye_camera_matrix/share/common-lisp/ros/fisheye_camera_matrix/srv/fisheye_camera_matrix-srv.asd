
(cl:in-package :asdf)

(defsystem "fisheye_camera_matrix-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "perspective_projection" :depends-on ("_package_perspective_projection"))
    (:file "_package_perspective_projection" :depends-on ("_package"))
  ))