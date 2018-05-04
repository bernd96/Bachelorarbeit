/*
 * Subandpub.cpp
 *
 *  Created on: 23.04.2018
 *      Author: name-not-found
 */

#include "ros/ros.h"
#include <std_msgs/String.h>
#include <nav_msgs/Odometry.h>
#include <eigen3/Eigen/Dense>
#include <tf/tf.h>

#include <list>
#include <fub_trajectory_msgs/Trajectory.h>

nav_msgs::Odometry start_position;
void odomCallback (const nav_msgs::OdometryConstPtr &msg){
	start_position=*msg;
	Eigen::Vector2f pos;
	pos[0]=start_position.pose.pose.position.x;
	pos[1]=start_position.pose.pose.position.y;
	double yaw;

	yaw=tf::getYaw(start_position.pose.pose.orientation);
	std::cout<<start_position.pose.pose.orientation<<std::endl;
	std::cout<<yaw<<std::endl;

}

int main(int argc, char **argv) {

	ros::init(argc, argv, "sub");
	ros::NodeHandle n;
	//ros::Subscriber sub =n.subscribe("/odom",1000, odomCallback);
	//rate 100hz, evtl eigene callbackfkt mit eigener Rate schreiben, ros::Rate, ros::Timer
	//ros::spin();
	ros::Publisher traj = n.advertise<fub_trajectory_msgs::Trajectory>("planned_path",1000);

	int count = 0;
	while (ros::ok()){
		fub_trajectory_msgs::Trajectory trajectory;
		//Baue Trajectorie auf die eine gerade linie ist.
		for(int i=1; i<8; i++){
			fub_trajectory_msgs::TrajectoryPoint traj_point;
			traj_point.pose.orientation.w=1;
			traj_point.pose.orientation.x=0;
			traj_point.pose.orientation.y=0;
			traj_point.pose.orientation.z=0;
			traj_point.pose.position.x=i;
			traj_point.pose.position.y=1;
			ros::Duration dur((0.0001*i));
			traj_point.time_from_start=dur;
			trajectory.trajectory.push_back(traj_point);

		}
		ros::Rate loop_rate(1);
		ros::Time now = ros::Time::now();
		trajectory.header.stamp=now;
		trajectory.header.frame_id="odom";
		trajectory.child_frame_id="base_link";
		traj.publish(trajectory);
		ros::spinOnce();
		loop_rate.sleep();
		++count;
	}
}

