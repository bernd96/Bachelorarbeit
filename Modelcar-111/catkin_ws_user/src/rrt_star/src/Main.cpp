/*
 * Main.cpp
 *
 *  Created on: 19.02.2018
 *      Author: Arbeit
 */
#include <time.h>
#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include "ros/ros.h"
#include <nodelet/nodelet.h>
#include "const.h"
#include <tf/tf.h>
#include "RRTSTAR.h"
#include "Node.h"

using namespace Eigen;

Eigen::Vector2d pos;
double yaw;

void callback(const nav_msgs::Odometry & odom){
	nav_msgs::Odometry start_position;
	start_position=odom;
	pos[0]=start_position.pose.pose.position.x;
	pos[1]=start_position.pose.pose.position.y;
	yaw=tf::getYaw(start_position.pose.pose.orientation);
	//yaw: [0,2*Pi), 0 is vec(1,0), Pi is (-1,0)
	yaw+=M_PI;
	return;
}


int main(int argc, char **argv) {
	//Zeitmessung Start
	struct timespec mytime;
	clock_gettime(CLOCK_MONOTONIC, &mytime);
	long double starttime = mytime.tv_nsec;
	double startsecs = mytime.tv_sec;

	
	ros::init(argc, argv, "rrt_star");
	ros::NodeHandle n;
	ros::Publisher traj = n.advertise<fub_trajectory_msgs::Trajectory>("planned_path",1000);

	//Auto - get Position and Orientation and write to start_position
	ros::Subscriber sub =n.subscribe("/odom",100, callback);
	yaw = M_PI;
	pos << 1, 2;
	Node start { pos, yaw, nullptr, Val::valid, 0 };

	start.print_node();

	//while (ros::ok()){
		fub_trajectory_msgs::Trajectory trajectory;
		trajectory = rrt_star(start);
		ros::Rate loop_rate(4);
			ros::Time now = ros::Time::now();
			trajectory.header.stamp=now;
			trajectory.header.frame_id="odom";
			trajectory.child_frame_id="base_link";
			traj.publish(trajectory);
			ros::spinOnce();
			loop_rate.sleep();

	//}



	//Zeitmessung Auswertung
	clock_gettime(CLOCK_MONOTONIC, &mytime);
	double msecs = ((mytime.tv_nsec) - (starttime)) / (double) 1000000;
	double secs = ((double) (mytime.tv_sec) - (double) (startsecs));
	std::cout << "Time for algorithm: " << msecs << " MiliSeconds or " << secs
			<< " seconds." << std::endl;

	return 0;
}

