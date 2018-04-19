// Generated by gencpp from file fisheye_camera_matrix_msgs/CameraMatrix.msg
// DO NOT EDIT!


#ifndef FISHEYE_CAMERA_MATRIX_MSGS_MESSAGE_CAMERAMATRIX_H
#define FISHEYE_CAMERA_MATRIX_MSGS_MESSAGE_CAMERAMATRIX_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace fisheye_camera_matrix_msgs
{
template <class ContainerAllocator>
struct CameraMatrix_
{
  typedef CameraMatrix_<ContainerAllocator> Type;

  CameraMatrix_()
    : header()
    , width(0)
    , height(0)
    , cx(0)
    , cy(0)
    , fl(0.0)
    , h(0.0)
    , scale(0.0)  {
    }
  CameraMatrix_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , width(0)
    , height(0)
    , cx(0)
    , cy(0)
    , fl(0.0)
    , h(0.0)
    , scale(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint32_t _width_type;
  _width_type width;

   typedef uint32_t _height_type;
  _height_type height;

   typedef uint32_t _cx_type;
  _cx_type cx;

   typedef uint32_t _cy_type;
  _cy_type cy;

   typedef float _fl_type;
  _fl_type fl;

   typedef float _h_type;
  _h_type h;

   typedef float _scale_type;
  _scale_type scale;




  typedef boost::shared_ptr< ::fisheye_camera_matrix_msgs::CameraMatrix_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::fisheye_camera_matrix_msgs::CameraMatrix_<ContainerAllocator> const> ConstPtr;

}; // struct CameraMatrix_

typedef ::fisheye_camera_matrix_msgs::CameraMatrix_<std::allocator<void> > CameraMatrix;

typedef boost::shared_ptr< ::fisheye_camera_matrix_msgs::CameraMatrix > CameraMatrixPtr;
typedef boost::shared_ptr< ::fisheye_camera_matrix_msgs::CameraMatrix const> CameraMatrixConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::fisheye_camera_matrix_msgs::CameraMatrix_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::fisheye_camera_matrix_msgs::CameraMatrix_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace fisheye_camera_matrix_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'fisheye_camera_matrix_msgs': ['/home/name-not-found/Dokumente/Bachelorarbeit/Modelcar-111/catkin_ws_user/src/fisheye_camera_matrix_msgs/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::fisheye_camera_matrix_msgs::CameraMatrix_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::fisheye_camera_matrix_msgs::CameraMatrix_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fisheye_camera_matrix_msgs::CameraMatrix_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fisheye_camera_matrix_msgs::CameraMatrix_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fisheye_camera_matrix_msgs::CameraMatrix_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fisheye_camera_matrix_msgs::CameraMatrix_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::fisheye_camera_matrix_msgs::CameraMatrix_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9120b07de3b326589888599ebcf42e75";
  }

  static const char* value(const ::fisheye_camera_matrix_msgs::CameraMatrix_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9120b07de3b32658ULL;
  static const uint64_t static_value2 = 0x9888599ebcf42e75ULL;
};

template<class ContainerAllocator>
struct DataType< ::fisheye_camera_matrix_msgs::CameraMatrix_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fisheye_camera_matrix_msgs/CameraMatrix";
  }

  static const char* value(const ::fisheye_camera_matrix_msgs::CameraMatrix_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::fisheye_camera_matrix_msgs::CameraMatrix_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
uint32 width\n\
uint32 height\n\
uint32 cx\n\
uint32 cy\n\
float32 fl\n\
float32 h\n\
float32 scale\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::fisheye_camera_matrix_msgs::CameraMatrix_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::fisheye_camera_matrix_msgs::CameraMatrix_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.width);
      stream.next(m.height);
      stream.next(m.cx);
      stream.next(m.cy);
      stream.next(m.fl);
      stream.next(m.h);
      stream.next(m.scale);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CameraMatrix_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::fisheye_camera_matrix_msgs::CameraMatrix_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::fisheye_camera_matrix_msgs::CameraMatrix_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "width: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.width);
    s << indent << "height: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.height);
    s << indent << "cx: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.cx);
    s << indent << "cy: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.cy);
    s << indent << "fl: ";
    Printer<float>::stream(s, indent + "  ", v.fl);
    s << indent << "h: ";
    Printer<float>::stream(s, indent + "  ", v.h);
    s << indent << "scale: ";
    Printer<float>::stream(s, indent + "  ", v.scale);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FISHEYE_CAMERA_MATRIX_MSGS_MESSAGE_CAMERAMATRIX_H