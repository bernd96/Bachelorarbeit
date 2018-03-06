/*
 * AdvancedCalculater.h
 *
 *  Created on: 02.03.2018
 *      Author: name-not-found
 */
#include <Node.h>
#include <Obstacle.h>

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

namespace std {

class Calculator {
public:

	Calculator();
	bool is_in_area(Node*,Obstacle*);
	float get_length(float x, float y);
	float get_distance(Node*,Node*);
	void unit_vector(float* vector);
	float cos_angle(float* v1, float* v2);
	virtual ~Calculator();
};

} /* namespace std */

#endif /* CALCULATOR_H_ */
