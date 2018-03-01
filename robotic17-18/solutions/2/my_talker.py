#!/usr/bin/env python
# Franziska Boenisch /Christoph Brockmann

## Solving the first task of sending some commands to the car

import rospy
from std_msgs.msg import String
from std_msgs.msg import Int16

# this is the original talker code
def talker():
    pub = rospy.Publisher('chatter', String, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        hello_str = "hello world %s" % rospy.get_time()
        rospy.loginfo(hello_str)
        pub.publish(hello_str)
        rate.sleep()



# we do somehing similar
def drive_a_circle():
    # setup the publishers
    speed = rospy.Publisher('/manual_control/speed', Int16, queue_size=10)
    steer = rospy.Publisher('/manual_control/steering', Int16, queue_size=10)
    rospy.init_node('my_talker', anonymous=True)
    # set some variables
    spd = 50    
    right = 0
    straight = 80
    time_r = 3.2
    time_s = 4
    # send a sequence of commands
    
    # define a corner
    def corner(angle, time, straight=80, steer=steer):
        # take a corner   
        steer.publish(angle)
        rospy.sleep(time)
        steer.publish(straight)
    
    # accelerate
    speed.publish(0)
    speed.publish(-spd)    

    # take a corner (1)    
    corner(right, time_r)
    # go straight
    rospy.sleep(5)
    # take a corner (2)    
    corner(right, time_r)
    # go straight
    rospy.sleep(5)
    # take a corner (3)    
    corner(right, time_r)
    # go straight
    rospy.sleep(5)
    # take a corner (4)    
    corner(right, time_r)
    # go straight
    rospy.sleep(5)

    # stop	
    speed.publish(0)
    exit()	

if __name__ == '__main__':
    try:
        drive_a_circle()
    except rospy.ROSInterruptException:
        pass
