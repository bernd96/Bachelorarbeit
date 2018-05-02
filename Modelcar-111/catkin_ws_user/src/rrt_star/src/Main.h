/*
 * Main.h
 *
 *  Created on: 21.03.2018
 *      Author: name-not-found
 */
#pragma once
#include <eigen3/Eigen/Dense>
#include <fub_trajectory_msgs/Trajectory.h>
#include <list>
#include "Node.h"
#include <nav_msgs/Odometry.h>
#ifndef SRC_MAIN_H_
#define SRC_MAIN_H_


	auto RRT_simple(std::list<Node>&, Node& start)-> fub_trajectory_msgs::Trajectory;


	//for startposition
	Eigen::Vector2d pos;
	double yaw;



#endif /* SRC_MAIN_H_ */
