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
	Car(const Eigen::Vector2f& pos, const Eigen::Vector2f& ori, float, float, float);
	virtual ~Car();

	auto get_position()->Eigen::Vector2f&;
	auto get_orientation()->Eigen::Vector2f&;


};

#endif /* CAR_H_ */
