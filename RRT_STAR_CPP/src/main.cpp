/*
 * Main.cpp
 *
 *  Created on: 19.02.2018
 *      Author: Arbeit
 */
#include <Calculator.h>
#include <Car.h>
#include <Node.h>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <eigen3/Eigen/Dense>


using namespace std;
using namespace Eigen;

void get_position(Vector2d*pos){
	float tmp[4]={5,7,2,1};
	pos=tmp;
}

const int STEPSIZE=10;
int main(int argc, char* argv[]){
	//Systemkonstanten festlegen:
	//Schrittweite in welcher einheit?

	//Auto - Lenkwinkel in Grad? oder Vektor/radius des Lenkkreises?
	const float STEERING_ANGLE= 45;
	//Auto - Position
	//TODO insert correct get_value function
	Vector2f position(1,2);
	//Radius Rewiring/Parentsuche
	const float RADIUS=20;

	/*
	 * Der Cosinus des befahrbaren Winkels, ausgehend
	 * vom Auto. Alle Punkte außerhalb sind nicht erreichbar,
	 * nahe Punkte innerhalb begrenzt durch den Lenkwinkel.
	 */
	const float COS_ANGLE = STEPSIZE/(2*STEERING_ANGLE);

	//Zeitmessung Start
	struct timespec mytime;
	clock_gettime(CLOCK_MONOTONIC,&mytime);
	float starttime= mytime.tv_nsec;
	//Calculator
	Calculator calc=new Calculator();
	//Startknoten
	// Random initialisiert zwischen -1 und 1, wird danach normalisiert auf 0-1000
	Vector2f start_pos = Vector2f::Random();
	start_pos=(start_pos+1)*500;
	Vector2f start_ori(1,0);
	Node start=new Node();
	start._init_(&start_pos, start_ori);
	//main
	for (int i = 0; i < 500; ++i) {
		Vector2f coor=Vector2f::Random();
		coor=(coor+1)*500;
		Vector2f ori=Vector2f::Random();

		//create_random_node();
		Node new_node = new Node();
		new_node._init_(&coor,&ori);



		//check_if_valid();
		if (!calc.is_reachable(&start,&new_node)){
			continue;
		}
		//find_parent_with_min_cost();

		project_to parent();
		check_if_still_valid_and_set_parent();
		calculate_orientation();
		calculate_cost();
		check_if_goal_reached();
	}

	//Zeitmessung Auswertung
	clock_gettime(CLOCK_MONOTONIC,&mytime);
	float secs = ((float)(mytime.tv_nsec)-(float)(starttime))/1000000;
	cout <<"Time for algorithm: "<< secs << " MiliSeconds.";

}



