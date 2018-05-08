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
const double STEPSIZE = 1;
//Radius Rewiring/Parentsuche in Meter
const double RADIUS = 1;
//Anzahl Knoten mit Zufallszahlen
const int NUMBER_OF_NODES = 1000;
//~Speed in m/s, max 1.5 times faster
const double SPEED = 1;
//Konstanten des Arbeitsbereiches; Ursprung ist "Am Fenster bei den Schränken",
//x: 0-10m, y:0-10m, TODO Anpassen auf 6x4m;   sampling in a square between lower and upper bound
const double RANGE = 12.0;
const double UPPER_BOUND = 10;
const double LOWER_BOUND=-2;
// Zielbereich,(x,y,Ausdehnung Richtung X, Ausdehnung Richtung Y)
const Eigen::Vector4d GOAL_AREA(6, 6, 1, 1);

//Konstanten für die Datenstruktur:
const double CELL_SIZE = 1;
const double SIZE = RANGE / CELL_SIZE;

//Gibt die Rundungsgenauigkeit bei Vergleichen etc. an, hier 4 Stellen
const double ACCURACY = 0.0001;

//Konstanten fürs Auto - Lenkwinkel in Grad? oder Vektor/radius des Lenkkreises? (2.momentan)
const double STEERING_ANGLE_RADIUS = 0.5;
//max angle for valid nodes. If the angle is higher, node cant be reached from the car.
// acos(x): x in Intervall[-1,1], or MAX_ANGLE will be imaginär
//as long as you use easy func no problem
const double MAX_ANGLE = 0;
//M_PI / 2 - acos(STEPSIZE / (2 * STEERING_ANGLE_RADIUS));







#endif /* CONST_H_ */
