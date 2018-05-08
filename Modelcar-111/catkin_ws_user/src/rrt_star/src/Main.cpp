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
	yaw = tf::getYaw(start_position.pose.pose.orientation);
	std::cout << pos << std::endl;
	//yaw: [0,2*Pi), 0 is vec(1,0), Pi is (-1,0)
	yaw+=M_PI;
	return;
}


int main(int argc, char **argv) {
	//Zeitmessung Start
	struct timespec mytime;
	clock_gettime(CLOCK_MONOTONIC, &mytime);
	std::list<Node> raw_nodes;

	//create list of raw nodes for later use
	for (int i = 0; i < NUMBER_OF_NODES; ++i) {
		Vector2d position(0, 0);
		Vector2d direction(0, 0);
		raw_nodes.emplace_back(position, 0, nullptr, direction, Val::unknown,
				-1);
	}
	ros::init(argc, argv, "rrt_star");
	ros::NodeHandle n;
	ros::Publisher traj = n.advertise<fub_trajectory_msgs::Trajectory>("planned_path",1000);

	//Auto - get Position and Orientation and write to start_position
	ros::Subscriber sub = n.subscribe("/odom", 100, callback);
	yaw = 0;
	pos << 0, 0;
	Vector2d dir;
	dir << 0, 0;
	//start.print_node();

	while (ros::ok()) {
		long double starttime = mytime.tv_nsec;
		double startsecs = mytime.tv_sec;
		fub_trajectory_msgs::Trajectory trajectory;
		Node start { pos, yaw, nullptr, dir, Val::valid, 0 };

		rrt_star(start, raw_nodes, trajectory);

		clock_gettime(CLOCK_MONOTONIC, &mytime);
		double nansecs = mytime.tv_nsec;
		if (nansecs < 0) {
			nansecs -= 1000000000;
		}
		double msecs = ((nansecs) - (starttime)) / (double) 1000000;
		double secs = ((double) (mytime.tv_sec) - (double) (startsecs));
		std::cout << "Time for algorithm: " << secs << " seconds and " << msecs
				<< " MiliSeconds." << std::endl;

		ros::Rate loop_rate(4);
		ros::Time now = ros::Time::now();
		trajectory.header.stamp = now;
		trajectory.header.frame_id = "map";
		trajectory.child_frame_id = "base_link";
		traj.publish(trajectory);
		ros::spinOnce();
		loop_rate.sleep();

	}



	//Zeitmessung Auswertung


	return 0;
}

