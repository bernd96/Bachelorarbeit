/*
 * const.h
 *
 *  Created on: May 2, 2018
 *      Author: besahre
 */
#include <eigen3/Eigen/Dense>
#ifndef CONST_H_
#define CONST_H_


//Systemkonstanten festlegen:
	//ALL UNITS ARE IN METERS
	const double STEPSIZE = 0.5;
//Radius Rewiring/Parentsuche in m
	const double RADIUS= 0.6;
	//Auto - Lenkwinkel in Grad? oder Vektor/radius des Lenkkreises?
	const double STEERING_ANGLE_RADIUS= 0.3;
	const double MAX_ANGLE = M_PI;
	//
	const int StructSize = 50;
	const int StructRange=5;

	/*
	 * Der Cosinus des befahrbaren Winkels, ausgehend
	 * vom Auto. Alle Punkte außerhalb sind nicht erreichbar,
	 * nahe Punkte innerhalb begrenzt durch den Lenkwinkel.
	 */
	const double COS_ANGLE=STEPSIZE / (2 * STEERING_ANGLE_RADIUS);
	const int NUMBER_OF_NODES=5;
	//x: 0-10m, y:0-10m
	const int RANGE=10.0;
	const int COMPARE_QUOTIENT=100;
		//Gibt die Rundungsgenauigkeit bei Vergleichen etc. an, hier 4 Stellen
		const double ACCURACY=0.0001;
		//Ursprung ist "unten rechts", (x,y,Ausdehnung Richtung X, Ausdehnung Richtung Y)
		const Eigen::Vector4d GOAL_AREA(5,7, 3,3);


#endif /* CONST_H_ */
