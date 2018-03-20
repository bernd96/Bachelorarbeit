/*
 * Main.cpp
 *
 *  Created on: 19.02.2018
 *      Author: Arbeit
 */
#include <Calculator.h>
#include <time.h>
#include <Car.h>
#include <Node.h>
#include <iostream>
#include <array>
#include <list>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <eigen3/Eigen/Dense>

//Systemkonstanten festlegen:
//Schrittweite in welcher einheit?
const int STEPSIZE = 10;
//Radius Rewiring/Parentsuche
const float RADIUS = 20;
//Auto - Lenkwinkel in Grad? oder Vektor/radius des Lenkkreises?
const float STEERING_ANGLE = 45;
/*
 * Der Cosinus des befahrbaren Winkels, ausgehend
 * vom Auto. Alle Punkte außerhalb sind nicht erreichbar,
 * nahe Punkte innerhalb begrenzt durch den Lenkwinkel.
 */
const float COS_ANGLE = STEPSIZE / (2 * STEERING_ANGLE);
int number_of_nodes=500;
int main(int argc, char* argv[]) {

	//Zeitmessung Start
	struct timespec mytime;
	clock_gettime(CLOCK_MONOTONIC, &mytime);
	float starttime = mytime.tv_nsec;


	//Auto - Position
	//TODO insert correct get_value function
	Eigen::Vector2f position(0, 0);
	Eigen::Vector2f orientation(1, 0);
	Car car(position, orientation, STEERING_ANGLE, 0.3, 0.15);

	Node start(position, orientation);
	//main

	std::vector<std::list<Node>> list_of_y_coor(number_of_nodes/10);

	for (int i = 0; i < number_of_nodes; ++i) {
		//create_random_node();
		Eigen::Vector2f coor = Eigen::Vector2f::Random();
		coor = coor*number_of_nodes;
		Eigen::Vector2f ori = Eigen::Vector2f::Random();
		//TODO Konstruktor schön machen
		Node node(coor);

		//check_if_valid();
		node.set_validation(Val::valid);
		if(node.get_validation()==Val::valid){
			//find_parent_with_min_cost();
			node.calculate_parent(list_of_y_coor, number_of_nodes);
			//project_to parent();
			//check_if_still_valid_and_set_parent();
			//calculate_orientation();
			//calculate_cost();
			//check_if_goal_reached()
		}
	}

	//Zeitmessung Auswertung
	clock_gettime(CLOCK_MONOTONIC, &mytime);
	float secs = ((float) (mytime.tv_nsec) - (float) (starttime)) / 1000000;
	std::cout << "Time for algorithm: " << secs << " MiliSeconds." << std::endl;

}
