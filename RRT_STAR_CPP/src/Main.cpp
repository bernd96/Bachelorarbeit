/*
 * Main.cpp
 *
 *  Created on: 19.02.2018
 *      Author: Arbeit
 */
#include <time.h>
#include <Car.h>
#include <Node.h>
#include <iostream>
#include <array>
#include <list>
#include <cstdlib>
#include <ctime>
#include <eigen3/Eigen/Dense>
#include <Main.h>
#include <Returnclass.h>

using namespace Eigen;

auto RRT_simple(std::list<Node>& list_of_nodes, Node& start)->Returnclass {
	std::random_device rn;
	std::mt19937 engine(rn());
	std::uniform_real_distribution<double> randoms(1.0, RANGE);
	list_of_nodes.push_front(start);
	Vector2d coor;
	Returnclass traject;
	for (int i = 0; i < NUMBER_OF_NODES; ++i) {
		double a = randoms(engine);
		double b = randoms(engine);
		coor << a, b;
		Node node { coor };
		if (node.easy_look_for_parent(list_of_nodes)) {
			if (node.project_to_parent(list_of_nodes)) {

				//check_if_still_valid_and_set_parent();
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
							}
						} else {
							std::cout << "calculate_orientation faild with i="
									<< i << std::endl;
						}

					} else {
						std::cout << "get_validation faild with i=" << i
								<< std::endl;
					}

				} else {
					std::cout << "easy_set_parent faild with i=" << i
							<< std::endl;
				}

			} else {
				std::cout << "project_to_parent faild with i=" << i
						<< std::endl;
			}
		} else {
			std::cout << "Easy lookout fail with i=" << i << std::endl;
		}
	}				//for loop
	return traject;
}

int main() {
	//Zeitmessung Start
	struct timespec mytime;
	clock_gettime(CLOCK_MONOTONIC, &mytime);
	float starttime = mytime.tv_nsec;

	//TODO insert correct get_value function for Auto - Position
	Vector2d pos(1, 1);
	Vector2d ori(1, 0);
	Node start(pos, ori, &start, Val::valid, 0);
	/*Datenstruktur:
	 //std::vector<std::list<Node>> list_of_nodes(NUMBER_OF_NODES / 10);
	 //start.insert_node(list_of_nodes);
	 */
	Returnclass trajectorie;
	std::list<Node> list_of_nodes;
	trajectorie = RRT_simple(list_of_nodes, start);

	for (auto &iter : list_of_nodes) {
		iter.print_node();
	}
	//Zeitmessung Auswertung
	clock_gettime(CLOCK_MONOTONIC, &mytime);
	double msecs = ((float) (mytime.tv_nsec) - (float) (starttime)) / 1000000;
	double secs = msecs / 1000;
	std::cout << "Time for algorithm: " << msecs << " MiliSeconds or " << secs
			<< " seconds." << std::endl;

	return 0;
}

