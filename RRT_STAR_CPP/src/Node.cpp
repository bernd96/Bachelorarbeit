/*
 * Node.cpp
 *
 *  Created on: 19.02.2018
 *      Author: Arbeit
 */

#include "Node.h"
#include <limits.h>

Node::Node(float x,float y, float ox, float oy) {
	x_coor=x;
	y_coor=y;
	ori_x=ox;
	ori_y=oy;
	isvalid=-1;
	parent =0;
	cost = limits();
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}
void calculate_coordinates_with_stepsize(int bla){
	bla=5;
}

