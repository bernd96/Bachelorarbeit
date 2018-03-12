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
#include <eigen3/Eigen/src/Core/Array.h>

using namespace std;

void get_position(float pos[]){
	float tmp[4]={5,7,2,1};
	pos=tmp;
}
void printarray (float arg[], int length) {
	  for (int n=0; n<length; ++n)
	    cout << arg[n] << ' ';
	  cout << '\n';
	}
const int STEPSIZE=10;
int main(int argc, char* argv[]){
	//Systemkonstanten festlegen:
	//Schrittweite in welcher einheit?

	//Auto - Lenkwinkel in Grad? oder Vektor/radius des Lenkkreises?
	const float STEERING_ANGLE= 45;
	//Auto - Position
	float pos[4]={1,2,3,4};
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

	//Startknoten
	std::srand(std::time(nullptr)); // use current time as seed for random generator
	    float rand = (float)std::rand()/(float)2147483.647;
	    float rand2=(float)std::rand()/2147483.647;

	//main
	printarray(pos,4);


	//Zeitmessung Auswertung
	clock_gettime(CLOCK_MONOTONIC,&mytime);
	float secs = ((float)(mytime.tv_nsec)-(float)(starttime))/1000000;
	cout <<"Time for algorithm: "<< secs << " MiliSeconds.";

}



