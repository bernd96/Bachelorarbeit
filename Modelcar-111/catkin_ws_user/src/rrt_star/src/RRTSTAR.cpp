/*
 * RRTSTAR.cpp
 *
 *  Created on: 26.04.2018
 *      Author: name-not-found
 */

#include "RRTSTAR.h"
#include "const.h"
#include <tf/tf.h>
#include <list>

auto build_trajectory(fub_trajectory_msgs::Trajectory& trajectory,
		Node *goal)->void {
	/*
	 * Baue Trajectorie aus Pointern vom Ziel zum Start auf,
	 * füge Pointer auf neue Knoten vorne an
	 */
	std::list<Node*> traject_to_goal;
	if (goal == nullptr) {
		return;
	}
	traject_to_goal.push_back(goal);
	Node* tmp = goal->get_parent_pointer();
	for (int j = 0; tmp != nullptr; ++j) {

		traject_to_goal.push_front(tmp);
		tmp = (*tmp).get_parent_pointer();



	}
		//first try for duration: eukl. distance
	double duration = 0;
	double path_length = 0;
	for (auto &iter : traject_to_goal) {

		fub_trajectory_msgs::TrajectoryPoint traj_point;
		traj_point.pose.position.x = (*iter).get_coordinates_fast()[0];
		traj_point.pose.position.y = (*iter).get_coordinates_fast()[1];
		//a quaternion created from yaw
		geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(
				(*iter).get_yaw() - M_PI);
		traj_point.pose.orientation = odom_quat;
		if (iter->get_parent_pointer() != nullptr) {
			path_length =
					(iter->get_coordinates_fast()
							- iter->get_parent_pointer()->get_coordinates_fast()).norm();
		} else {
			path_length = 1;
			}
		// macht min. 3.6km/h
		duration += path_length / SPEED;
			ros::Duration dur(duration);
			traj_point.time_from_start = dur;
		std::cout << traj_point.time_from_start << std::endl;
			trajectory.trajectory.push_back(traj_point);
	
	}
}


auto rrt_star(Node& start,
		std::list<Node>&raw_nodes,
		fub_trajectory_msgs::Trajectory& trajectory)->bool {
	ListOfNodes list_of_nodes(SIZE, CELL_SIZE);

	std::random_device rn;
	std::mt19937 engine(rn());
	std::uniform_real_distribution<double> randoms(0, -RANGE);
//TODO easy
	list_of_nodes.add_node_easy(start);

	Vector2d coor;
	Node* goal = nullptr;

	for (auto &node : raw_nodes) {
		//randoms efficient?
		double a = randoms(engine);
		double b = randoms(engine);
		coor << a, b;
		//	std::cout << "________________________" << std::endl;
		node.set_coordinates(coor);

		//function find nearest implicit set parent
		//TODO easy
		if (!list_of_nodes.find_nearest_neighbour_easy(node)) {
			//std::cout << "No nearest neighbour node found..." << std::endl;
			continue;
		}
		node.project_to_parent(*node.get_parent_pointer());
		//TODO  real validation check
		node.set_validation(Val::valid);
		if (node.get_validation() != Val::valid) {
			continue;
		}
		//TODO easy
		if (!list_of_nodes.find_nearest_parent_easy(node)) {
			std::cout << "Cant find nearest_parent::Node to near now"
					<< std::endl;
			continue;
		}
		node.calculate_yaw_and_cost();

		//TODO easy
		list_of_nodes.add_node_easy(node);

		//TODO Verhalten wenn Ziel erreicht
		if (node.reached_goal()) {
					if (goal != nullptr) {
				if (node.get_cost() < goal->get_cost()) {
						goal = &node;
					std::cout << "Better goal node found" << std::endl;

						}
					} else {
						goal = &node;
					}
		}
		//TODO easy
		list_of_nodes.rewire_easy(node);

	}		//for loop
	build_trajectory(trajectory, goal);
	if (goal == nullptr) {
		return false;
	}
	return true;
}

