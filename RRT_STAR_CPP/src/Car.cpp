/*
 * car.cpp
 *
 *  Created on: 01.03.2018
 *      Author: name-not-found
 */

#include "Car.h"
using namespace Eigen;
Car::Car(const Vector2f& pos,const Vector2f& ori, float angle_rad,
		float l, float w) :
		position(pos), orientation(ori), MAX_STEERING_ANGLE_RADIUS(angle_rad),length(l), width(w)  {}


Car::~Car() {
	// TODO Auto-generated destructor stub
}

auto Car::get_position() -> Vector2f&{
	return position;
}

auto Car::get_orientation() -> Vector2f&{
	return orientation;
}
