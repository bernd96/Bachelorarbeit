/*
 * car.cpp
 *
 *  Created on: 01.03.2018
 *      Author: name-not-found
 */

#include "Car.h"

Car::Car(Eigen::Vector2f pos, Eigen::Vector2f ori, float angle_rad,
		float l, float w) :
		position(pos), orientation(ori), MAX_STEERING_ANGLE_RADIUS(angle_rad),length(l), width(w)  {
	// TODO Auto-generated constructor stub

}

float* Car::get_position() {
	return 0;

}

Car::~Car() {
	// TODO Auto-generated destructor stub
}

