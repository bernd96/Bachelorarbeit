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
	const double STEPSIZE = 0.5;
//Radius Rewiring/Parentsuche in Meter
	const double RADIUS= 0.6;
//Anzahl Knoten mit Zufallszahlen
const int NUMBER_OF_NODES = 5;

//Konstanten fürs Auto - Lenkwinkel in Grad? oder Vektor/radius des Lenkkreises?
	const double STEERING_ANGLE_RADIUS= 0.3;
//max angle for valid nodes, STEERING_ANGLE_RADIUS / STEPSIZE <= 1!!!
const double MAX_ANGLE = asin(STEERING_ANGLE_RADIUS / STEPSIZE);
//~Speed in m/s, max 1.5 times faster
const double SPEED = 0.5;
	/*
 * Der Cosinus des befahrbaren Winkels, ausgehend
	 * vom Auto. Alle Punkte außerhalb sind nicht erreichbar,
	 * nahe Punkte innerhalb begrenzt durch den Lenkwinkel.
	 */
	const double COS_ANGLE=STEPSIZE / (2 * STEERING_ANGLE_RADIUS);

//Konstanten des Arbeitsbereiches; Ursprung ist "Am Fenster bei den Schränken",
//x: 0-10m, y:0-10m, TODO Anpassen auf 6x4m, Datenstruktur
const double RANGE = 6.0;
// Zielbereich,(x,y,Ausdehnung Richtung X, Ausdehnung Richtung Y)
const Eigen::Vector4d GOAL_AREA(5, 7, 3, 3);

//Konstanten für die Datenstruktur:
const double CELL_SIZE = 0.6;
const double SIZE = RANGE / CELL_SIZE;

//Gibt die Rundungsgenauigkeit bei Vergleichen etc. an, hier 4 Stellen
const double ACCURACY = 0.0001;





#endif /* CONST_H_ */
