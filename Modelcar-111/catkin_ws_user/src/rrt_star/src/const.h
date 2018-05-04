/*
 * const.h
 *
 *  Created on: May 2, 2018
 *      Author: besahre
 */
#include <eigen3/Eigen/Dense>
#ifndef CONST_H_
#define CONST_H_


//Konstanten für den RRT Algorithmus:
//Ausbreitungsgeschwindigkeit (max Abstand zwischen Nodes) in Meter
const double STEPSIZE = 0.7;
//Radius Rewiring/Parentsuche in Meter
const double RADIUS = 1;
//Anzahl Knoten mit Zufallszahlen
const int NUMBER_OF_NODES = 500;

//Konstanten fürs Auto - Lenkwinkel in Grad? oder Vektor/radius des Lenkkreises? (2.momentan)
const double STEERING_ANGLE_RADIUS = 0.5;
//max angle for valid nodes. If the angle is higher, node cant be reached from the car.
// acos(x): x in Intervall[-1,1], or MAX_ANGLE will be imaginär
const double MAX_ANGLE = M_PI / 2
		- acos(STEPSIZE / (2 * STEERING_ANGLE_RADIUS));
//~Speed in m/s, max 1.5 times faster
const double SPEED = 0.5;

//Konstanten des Arbeitsbereiches; Ursprung ist "Am Fenster bei den Schränken",
//x: 0-10m, y:0-10m, TODO Anpassen auf 6x4m, Datenstruktur
const double RANGE = 6.0;
// Zielbereich,(x,y,Ausdehnung Richtung X, Ausdehnung Richtung Y)
const Eigen::Vector4d GOAL_AREA(4, 2, 1, 1);

//Konstanten für die Datenstruktur:
const double CELL_SIZE = 1;
const double SIZE = RANGE / CELL_SIZE;

//Gibt die Rundungsgenauigkeit bei Vergleichen etc. an, hier 4 Stellen
const double ACCURACY = 0.0001;





#endif /* CONST_H_ */
