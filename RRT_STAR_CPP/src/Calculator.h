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
	int calculate_and_set_cost(Node*,Node*, Calculator*);
	void calculate_coordinates_with_stepsize(Node*,Node*,int);
	Node* find_parent(Node*);
	bool is_reachable(Node*,Node*);

	virtual ~Calculator();
};

} /* namespace std */

#endif /* CALCULATOR_H_ */
