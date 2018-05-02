// Auto-generated. Do not edit!

// (in-package fisheye_camera_matrix_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class CameraMatrix {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.width = null;
      this.height = null;
      this.cx = null;
      this.cy = null;
      this.fl = null;
      this.h = null;
      this.scale = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('width')) {
        this.width = initObj.width
      }
      else {
        this.width = 0;
      }
      if (initObj.hasOwnProperty('height')) {
        this.height = initObj.height
      }
      else {
        this.height = 0;
      }
      if (initObj.hasOwnProperty('cx')) {
        this.cx = initObj.cx
      }
      else {
        this.cx = 0;
      }
      if (initObj.hasOwnProperty('cy')) {
        this.cy = initObj.cy
      }
      else {
        this.cy = 0;
      }
      if (initObj.hasOwnProperty('fl')) {
        this.fl = initObj.fl
      }
      else {
        this.fl = 0.0;
      }
      if (initObj.hasOwnProperty('h')) {
        this.h = initObj.h
      }
      else {
        this.h = 0.0;
      }
      if (initObj.hasOwnProperty('scale')) {
        this.scale = initObj.scale
      }
      else {
        this.scale = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type CameraMatrix
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [width]
    bufferOffset = _serializer.uint32(obj.width, buffer, bufferOffset);
    // Serialize message field [height]
    bufferOffset = _serializer.uint32(obj.height, buffer, bufferOffset);
    // Serialize message field [cx]
    bufferOffset = _serializer.uint32(obj.cx, buffer, bufferOffset);
    // Serialize message field [cy]
    bufferOffset = _serializer.uint32(obj.cy, buffer, bufferOffset);
    // Serialize message field [fl]
    bufferOffset = _serializer.float32(obj.fl, buffer, bufferOffset);
    // Serialize message field [h]
    bufferOffset = _serializer.float32(obj.h, buffer, bufferOffset);
    // Serialize message field [scale]
    bufferOffset = _serializer.float32(obj.scale, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type CameraMatrix
    let len;
    let data = new CameraMatrix(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [width]
    data.width = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [height]
    data.height = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [cx]
    data.cx = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [cy]
    data.cy = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [fl]
    data.fl = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [h]
    data.h = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [scale]
    data.scale = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 28;
  }

  static datatype() {
    // Returns string type for a message object
    return 'fisheye_camera_matrix_msgs/CameraMatrix';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '9120b07de3b326589888599ebcf42e75';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new CameraMatrix(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.width !== undefined) {
      resolved.width = msg.width;
    }
    else {
      resolved.width = 0
    }

    if (msg.height !== undefined) {
      resolved.height = msg.height;
    }
    else {
      resolved.height = 0
    }

    if (msg.cx !== undefined) {
      resolved.cx = msg.cx;
    }
    else {
      resolved.cx = 0
    }

    if (msg.cy !== undefined) {
      resolved.cy = msg.cy;
    }
    else {
      resolved.cy = 0
    }

    if (msg.fl !== undefined) {
      resolved.fl = msg.fl;
    }
    else {
      resolved.fl = 0.0
    }

    if (msg.h !== undefined) {
      resolved.h = msg.h;
    }
    else {
      resolved.h = 0.0
    }

    if (msg.scale !== undefined) {
      resolved.scale = msg.scale;
    }
    else {
      resolved.scale = 0.0
    }

    return resolved;
    }
};

module.exports = CameraMatrix;
