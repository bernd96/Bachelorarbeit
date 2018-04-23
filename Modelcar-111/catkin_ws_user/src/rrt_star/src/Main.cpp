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


using namespace Eigen;

auto RRT_simple(std::list<Node>& list_of_nodes, Node& start)->fub_trajectory_msgs::Trajectory {
	std::random_device rn;
	std::mt19937 engine(rn());
	std::uniform_real_distribution<double> randoms(1.0, RANGE);
	list_of_nodes.push_front(start);
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
						if (node.calculate_orientation()) {
							//TODO check_if_goal_reached()
							list_of_nodes.push_front(node);
							if (node.reached_goal()) {
								std::cout << "Geschafft! Und nun?" << std::endl;
								goal=node;
							}
						} else {
							std::cout << "calculate_orientation failed with i="
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
	fub_trajectory_msgs::Trajectory trajectory;

	Eigen::Quaternionf quaternion;

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
	return trajectory;
}
void callback(const nav_msgs::Odometry odom){
	start_position=odom;
	return;
}

int main(int argc, char **argv) {
	//Zeitmessung Start
	struct timespec mytime;
	clock_gettime(CLOCK_MONOTONIC, &mytime);
	float starttime = mytime.tv_nsec;
	ros::init(argc, argv, "rrt_star");
	ros::NodeHandle n;

	ros::Publisher trajectoryPublisher = n.advertise<fub_trajectory_msgs::Trajectory>("planned_path", 10);

	//Auto - get Position and Orientation and write to start_position
	ros::Subscriber sub =n.subscribe("visual_gps\odom",100, callback);
	Vector2d pos;
	pos[0]=start_position.pose.pose.position.x;
	pos[1]=start_position.pose.pose.position.y;
	Vector2d ori;
	Eigen::Quaternionf q;
	q[0]=start_position.pose.pose.orientation.x;
	q[1]=start_position.pose.pose.orientation.y;
	q[2]=start_position.pose.pose.orientation.z;
	q[3]=start_position.pose.pose.orientation.w;
	//transfer from Quaternion to eulerangles to read the yaw vector
	auto euler = q.toRotationMatrix().eulerAngles(0,1,2);
	ori[0]=euler[2][0];
	ori[1]=euler[2][1];
	Node start(pos, ori, nullptr, Val::valid, 0);

	start.print_node();

	fub_trajectory_msgs::Trajectory trajectmsg;
	std::list<Node> list_of_nodes;
	trajectmsg = RRT_simple(list_of_nodes, start);

	for (auto &iter : list_of_nodes) {
		iter.print_node();
	}
	trajectoryPublisher.publish(trajectmsg);
	//Zeitmessung Auswertung
	clock_gettime(CLOCK_MONOTONIC, &mytime);
	double msecs = ((float) (mytime.tv_nsec) - (float) (starttime)) / 1000000;
	double secs = msecs / 1000;
	std::cout << "Time for algorithm: " << msecs << " MiliSeconds or " << secs
			<< " seconds." << std::endl;

	return 0;
}

