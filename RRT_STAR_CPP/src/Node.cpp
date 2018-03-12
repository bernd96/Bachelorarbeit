/*
 * Node.cpp
 *
 *  Created on: 19.02.2018
 *      Author: Arbeit
 */

#include "Node.h"
#include <float.h>

using namespace Eigen;

Node::Node(){}

Node* Node::get_parent_pointer() {
	return parent;
}

int Node::get_cost() {
	return cost;
}

void Node::set_parent_pointer(Node* parent_pointer) {
	parent=parent_pointer;
}

void Node::set_validation(int valid) {
	is_valid=valid;
}

int Node::get_validation() {
	return 0;
}

void Node::_init_(const Eigen::Vector2f& coor, const Eigen::Vector2f& ori) {
	coordinates=coor;
	orientation=ori;
}

Node::~Node() {}




