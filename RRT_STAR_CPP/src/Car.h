/*
 * car.h
 *
 *  Created on: 01.03.2018
 *      Author: name-not-found
 */
#include <Calculator.h>

#ifndef CAR_H_
#define CAR_H_

class Car {
private:
	float MAX_STEERING_ANGLE_RADIUS;
	float x_coor;
	float y_coor;
public:

	float* get_position();

	Car();
	virtual ~Car();
};

#endif /* CAR_H_ */
