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

public:
	float x_coor;
	float y_coor;
	float ori_x;
	float ori_y;
	void set_position();
	void set_orientation();
	Car();
	virtual ~Car();
};

#endif /* CAR_H_ */
