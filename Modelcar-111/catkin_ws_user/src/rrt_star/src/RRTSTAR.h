/*
 * RRTSTAR.h
 *
 *  Created on: 26.04.2018
 *      Author: name-not-found
 */
#include <fub_trajectory_msgs/Trajectory.h>
#include <nav_msgs/Odometry.h>
#include <eigen3/Eigen/Dense>
#include "Node.h"
#include "ListOfNodes.h"
#ifndef SRC_RRTSTAR_H_
#define SRC_RRTSTAR_H_
auto rrt_star(Node& start)->fub_trajectory_msgs::Trajectory;
auto build_trajectory(fub_trajectory_msgs::Trajectory& traj,
		Node&node)->void;
//um zwischendurch die Odometrie zu bekommen
auto get_odom()->void;

#endif /* SRC_RRTSTAR_H_ */
