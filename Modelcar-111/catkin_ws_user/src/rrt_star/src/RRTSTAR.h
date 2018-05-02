/*
 * RRTSTAR.h
 *
 *  Created on: 26.04.2018
 *      Author: name-not-found
 */
#include <fub_trajectory_msgs/Trajectory.h>
#include <nav_msgs/Odometry.h>
#include <eigen3/Eigen/Dense>
#include <Node.h>
#include <ListOfNodes.h>
#ifndef SRC_RRTSTAR_H_
#define SRC_RRTSTAR_H_

class RRTSTAR {
	double yaw;
	Eigen::Vector2d position;
public:
	auto rrt_star(const Node& start)->fub_trajectory_msgs::Trajectory;
	auto get_odom()->void;

	RRTSTAR();
	virtual ~RRTSTAR();
};

#endif /* SRC_RRTSTAR_H_ */
