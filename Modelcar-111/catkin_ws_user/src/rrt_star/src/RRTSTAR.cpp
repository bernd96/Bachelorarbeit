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
		Node&goal)->void {
	/*
	 * Baue Trajectorie aus Pointern vom Ziel zum Start auf,
	 * füge Pointer auf neue Knoten vorne an
	 */
	std::list<Node*> traject_to_goal;
	Node* tmp = goal.get_parent_pointer();
	for (int j = 0; tmp != nullptr; ++j) {
		traject_to_goal.push_front(tmp);
		tmp = (*tmp).get_parent_pointer();
	}
	//first try for duration: eukl. distance
	double duration = 2;
	double path_length = 0;
	for (auto &iter : traject_to_goal) {
		fub_trajectory_msgs::TrajectoryPoint traj_point;
		traj_point.pose.position.x = (*iter).get_coordinates()[0];
		traj_point.pose.position.y = (*iter).get_coordinates()[1];
		//a quaternion created from yaw
		geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(
				(*iter).get_yaw());
		traj_point.pose.orientation = odom_quat;
		//TODO calcute duration from distance of nodes
		path_length = (iter->get_coordinates()
				- iter->get_parent_pointer()->get_coordinates()).norm();
		duration *= path_length / SPEED;
		ros::Duration dur((5 * duration) + 1);
		traj_point.time_from_start = dur;

		trajectory.trajectory.push_back(traj_point);

	}
}

auto rrt_star(Node& start)->fub_trajectory_msgs::Trajectory {
	ListOfNodes list_of_nodes(SIZE, CELL_SIZE);

	std::random_device rn;
	std::mt19937 engine(rn());
	std::uniform_real_distribution<double> randoms(1.0, RANGE);

	list_of_nodes.add_node(start);

	Vector2d coor;
	Node goal;

	for (int i = 0; i < NUMBER_OF_NODES; ++i) {
		double a = randoms(engine);
		double b = randoms(engine);
		coor << a, b;
		Node node { coor };
		Node* nearest;
		if (!list_of_nodes.find_nearest_neighbour(node, nearest)) {
			std::cout << "No node found..." << std::endl;
			continue;
		}
		//TODO what if no parent found?
		node.project_to_parent(*nearest);
		//TODO  real validation check
		node.set_validation(Val::valid);
		if (node.get_validation() != Val::valid) {
			continue;
		}
		list_of_nodes.find_nearest_neighbour(node, nearest);

		node.set_parent(nearest);
		node.calculate_yaw();
		node.calculate_cost();
		if (!node.check()) {
			continue;
		}
		list_of_nodes.add_node(node);

		//TODO Verhalten wenn Ziel erreicht
		if (node.reached_goal()) {
			std::cout << "Geschafft! Und nun?" << std::endl;
			if (node.get_cost() < goal.get_cost()) {
				goal = node;
			}
		}
		list_of_nodes.rewire(node);

	}		//for loop



	fub_trajectory_msgs::Trajectory trajectory;
	build_trajectory(trajectory, goal);


	return trajectory;
}

