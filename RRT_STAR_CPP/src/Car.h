/*
 * car.h
 *
 *  Created on: 01.03.2018
 *      Author: name-not-found
 */

#include <eigen3/Eigen/Dense>

#ifndef CAR_H_
#define CAR_H_

class Car {
private:
	float MAX_STEERING_ANGLE_RADIUS;

	Eigen::Vector2f position;
	Eigen::Vector2f orientation;
	float length;
	float width;
public:

	void set_position();
	Car(Eigen::Vector2f, Eigen::Vector2f, float, float, float);
	virtual ~Car();
};

#endif /* CAR_H_ */
