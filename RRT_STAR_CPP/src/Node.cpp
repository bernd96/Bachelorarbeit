/*
 * Node.cpp
 *
 *  Created on: 19.02.2018
 *      Author: Arbeit
 */

#include "Node.h"
#include <float.h>

Node::Node(float x, float y, float ox, float oy){
	x_coor=x;
	y_coor=y;
	ori_x=ox;
	ori_y=oy;
	parent=0;
	cost=3400000000000000000;
	isvalid=-1;
}

Node* Node::get_parent_pointer() {
	return parent;
}

int Node::get_cost() {
	return cost;
}

void Node::set_parent_pointer(Node* parent_pointer) {
	parent=parent_pointer;
}

void Node::set_valid(int valid) {
	isvalid=valid;
}

int Node::is_valid() {
	return 0;
}

Node::~Node() {}




