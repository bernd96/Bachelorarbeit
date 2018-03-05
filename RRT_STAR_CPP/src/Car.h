/*
 * car.h
 *
 *  Created on: 01.03.2018
 *      Author: name-not-found
 */
#include <Calculator.h>

#ifndef CAR_H_
#define CAR_H_

class car {
private:
	float MAX_STEERING_ANGLE_RADIUS;
	float x_coor;
	float y_coor;
public:

	int* get_position();
	car();
	virtual ~car();
};

#endif /* CAR_H_ */
