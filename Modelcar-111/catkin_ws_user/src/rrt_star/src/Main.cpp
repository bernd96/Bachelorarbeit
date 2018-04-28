/*
 * Main.cpp
 *
 *  Created on: 19.02.2018
 *      Author: Arbeit
 */
#include <time.h>
#include <Car.h>
#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <Main.h>
#include <fub_trajectory_msgs/Trajectory.h>
#include <fub_trajectory_msgs/TrajectoryPoint.h>
#include "ros/ros.h"
#include <nodelet/nodelet.h>
#include <tf/tf.h>
#include <RRTSTAR.h>

using namespace Eigen;

void callback(const nav_msgs::Odometry & odom){
	nav_msgs::Odometry start_position;
	start_position=odom;
	pos[0]=start_position.pose.pose.position.x;
	pos[1]=start_position.pose.pose.position.y;
	yaw=tf::getYaw(start_position.pose.pose.orientation);
	yaw+=M_PI;
	return;
}


int main(int argc, char **argv) {
	//Zeitmessung Start
	struct timespec mytime;
	clock_gettime(CLOCK_MONOTONIC, &mytime);
	float starttime = mytime.tv_nsec;
	
	ros::init(argc, argv, "rrt_star");
	ros::NodeHandle n;
	ros::Publisher traj = n.advertise<fub_trajectory_msgs::Trajectory>("planned_path",1000);

	//Auto - get Position and Orientation and write to start_position
	//TODO compare spin of subscriber with spin of publisher, adjustments?
	ros::Subscriber sub =n.subscribe("/odom",100, callback);
	Node start(pos, yaw, nullptr, Val::valid, 0);

	start.print_node();

	std::list<Node> list_of_nodes;

		int count = 0;
		while (ros::ok()){
			fub_trajectory_msgs::Trajectory trajectory;
			RRTSTAR rrt;
			trajectory=rrt.rrt_star(start);

			ros::Rate loop_rate(1);
			ros::Time now = ros::Time::now();
			trajectory.header.stamp=now;
			trajectory.header.frame_id="odom";
			trajectory.child_frame_id="base_link";
			traj.publish(trajectory);
			ros::spinOnce();
			loop_rate.sleep();
			++count;




	//Zeitmessung Auswertung
	clock_gettime(CLOCK_MONOTONIC, &mytime);
	double msecs = ((float) (mytime.tv_nsec) - (float) (starttime)) / 1000000;
	double secs = msecs / 1000;
	std::cout << "Time for algorithm: " << msecs << " MiliSeconds or " << secs
			<< " seconds." << std::endl;

	return 0;
}

