/*
 * RRTSTAR.cpp
 *
 *  Created on: 26.04.2018
 *      Author: name-not-found
 */

#include "RRTSTAR.h"
#include <list>


auto rrt_star(const Node& start)->fub_trajectory_msgs::Trajectory {
	//TODO Größe bestimmen
	std::vector<std::list<Node>> list_of_nodes[100];

	std::random_device rn;
	std::mt19937 engine(rn());
	std::uniform_real_distribution<double> randoms(1.0, RANGE);
	add_node(start);
//	list_of_nodes.push_front(start);
	Vector2d coor;
	Node goal;
	for (int i = 0; i < NUMBER_OF_NODES; ++i) {
		double a = randoms(engine);
		double b = randoms(engine);
		coor << a, b;
		Node node { coor };
		if (node.easy_look_for_parent(list_of_nodes)) {
			if (node.project_to_parent(list_of_nodes)) {
				//Hier werden auch gleich die Kosten gesetzt.
				//Ändern falls diese von mehr als nur Entfernung abhängen!
				if (node.easy_set_parent(list_of_nodes)) {
					node.set_validation(Val::valid);
					if ((node.get_validation() == Val::valid)) {
						if (node.calculate_yaw()) {
							//TODO check_if_goal_reached()
							list_of_nodes.push_front(node);
							if (node.reached_goal()) {
								std::cout << "Geschafft! Und nun?" << std::endl;
								goal=node;
							}
						} else {
							std::cout << "calculate yaw failed with i="
									<< i << std::endl;
						}

					} else {
						std::cout << "get_validation failed with i=" << i
								<< std::endl;
					}

				} else {
					std::cout << "easy_set_parent failed with i=" << i
							<< std::endl;
				}

			} else {
				std::cout << "project_to_parent failed with i=" << i
						<< std::endl;
			}
		} else {
			std::cout << "Easy lookout failed with i=" << i << std::endl;
		}
	}				//for loop



	//Baue Trajectorie vom Ziel zum Start auf und drehe sie um
	std::list<Node>traject_to_goal;
	Node tmp=goal;
	for(int j=0;tmp.get_parent_pointer()!=nullptr;++j){
		traject_to_goal[j]=tmp;
		tmp=*tmp.get_parent_pointer();
	}
	traject_to_goal.reverse();
	fub_trajectory_msgs::Trajectory trajectory;
	int j=0;
	for (auto &iter : traject_to_goal){
		fub_trajectory_msgs::TrajectoryPoint traj_point;
		traj_point.pose.position.x = iter.get_coordinates()[0];
		traj_point.pose.position.y = iter.get_coordinates()[1];
		//a quaternion created from yaw
		geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(iter.get_yaw());
		traj_point.pose.orientation = odom_quat;
		//TODO calcute duration from distance of nodes
		ros::Duration dur((5*j)+1);
		traj_point.time_from_start=dur;

		trajectory.trajectory.push_back(traj_point);
		++j;

	}

	return trajectory;
}

RRTSTAR::RRTSTAR() {
	// TODO Auto-generated constructor stub

}

RRTSTAR::~RRTSTAR() {
	// TODO Auto-generated destructor stub
}

