/*
 * Subandpub.cpp
 *
 *  Created on: 23.04.2018
 *      Author: name-not-found
 */

#include "Subandpub.h"
#include "ros/ros.h"
#include <nodelet/nodelet.h>
#include <std_msgs/String.h>
#include <eigen3/Eigen/Dense>
#include <fub_trajectory_msgs/Trajectory.h>
#include <fub_trajectory_msgs/TrajectoryPoint.h>
#include <iostream>
#include <nav_msgs/Odometry.h>


void callback (const nav_msgs::Odometry::ConstPtr& msg ){
	 std::cout<<"I heard: "<<*msg<<std::endl;
	 start_position=*msg;
	 return;
}

int main(int argc, char **argv) {

	ros::init(argc, argv, "Tester");
	ros::NodeHandle n;
	//ros::Publisher cry= n.advertise<std_msgs>("test_channel", 10);
	ros::Subscriber sub =n.subscribe("visual_gps/odom",100, callback);
		Eigen::Vector2d pos;
		pos[0]=start_position.pose.pose.position.x;
		pos[1]=start_position.pose.pose.position.y;
		Eigen::Vector2d ori;
		Eigen::Quaternionf q(start_position.pose.pose.orientation.w,
				start_position.pose.pose.orientation.x,
				start_position.pose.pose.orientation.y,
				start_position.pose.pose.orientation.z);
		/*
		q[0]=start_position.pose.pose.orientation.x;
		q[1]=start_position.pose.pose.orientation.y;
		q[2]=start_position.pose.pose.orientation.z;
		q[3]=start_position.pose.pose.orientation.w;
		*/
		//transfer from Quaternion to eulerangles to read the yaw vector
		Eigen::Vector3d euler = q.toRotationMatrix().eulerAngles(0,1,2);
//		ori[0]=euler[2][0];
//		ori[1]=euler[2][1];

		std::cout<<"Eulerangles: "<<euler<<std::endl;

		/*
		 * fub_trajectory_msgs::Trajectory trajectory;

	Eigen::Quaternionf quaternion;
	//Baue Trajectorie vom Ziel zum Start auf und drehe sie um
	std::list<Node>traject_to_goal;
	traject_to_goal[0]=goal;
	Node tmp=goal;
	for(int j=0;tmp.get_parent_pointer()!=nullptr;++j){
		traject_to_goal[j]=tmp;
		tmp=*tmp.get_parent_pointer();
	}
	traject_to_goal.reverse();


	int j=0;
	for (auto &iter : traject_to_goal){
		trajectory.trajectory[j].pose.position.x = iter.get_coordinates()[0];
		trajectory.trajectory[j].pose.position.y = iter.get_coordinates()[1];
		quaternion= Eigen::Quaternion::Quaternion(iter.get_orientation().array());
		trajectory.trajectory[j].pose.orientation.x = quaternion.x();
		trajectory.trajectory[j].pose.orientation.y = quaternion.y();
		trajectory.trajectory[j].pose.orientation.z = quaternion.z();
		trajectory.trajectory[j].pose.orientation.w = quaternion.w();
		++j;
	}
		 */
}
