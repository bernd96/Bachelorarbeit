/*
 * Main.h
 *
 *  Created on: 21.03.2018
 *      Author: name-not-found
 */
#include <eigen3/Eigen/Dense>
#include <fub_trajectory_msgs/Trajectory.h>
#include <list>
#include <Node.h>
#include <nav_msgs/Odometry.h>
#ifndef SRC_MAIN_H_
#define SRC_MAIN_H_

//Systemkonstanten festlegen:
	//ALL UNITS ARE IN METERS
	const double STEPSIZE = 0.5;
	//Radius Rewiring/Parentsuche
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
	auto RRT_simple(std::list<Node>&, Node& start)-> fub_trajectory_msgs::Trajectory;

	const int COMPARE_QUOTIENT=100;
	//Gibt die Rundungsgenauigkeit bei Vergleichen etc. an, hier 4 Stellen
	const double ACCURACY=0.0001;
	//Ursprung ist "unten rechts", (x,y,Ausdehnung Richtung X, Ausdehnung Richtung Y)
	const Eigen::Vector4d GOAL_AREA(5,7, 3,3);
	//for startposition
	Vector2d pos;
	double yaw;



#endif /* SRC_MAIN_H_ */
