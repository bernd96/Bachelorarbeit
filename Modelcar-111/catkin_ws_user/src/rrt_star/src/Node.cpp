/*
 * Node.cpp
 *
 *  Created on: 19.02.2018
 *      Author: Arbeit
 */

#include "Node.h"
#include <iostream>
#include "const.h"
#include <math.h>
#include <iomanip>


using namespace Eigen;


auto Node::calculate_yaw()->bool {
	double par_yaw = parent->get_yaw();
	Vector2d dir = calculate_dir_vector(*parent);
	dir.normalize();
	double dir_yaw = calculate_yaw_from_vec(dir);
	yaw = dir_yaw + fmod((dir_yaw - par_yaw), (2 * M_PI));
	return true;
}
auto Node::calculate_yaw_from_vec(Vector2d vec)->double {
	Vector2d nn(1, 0);
	double yaw = std::acos(vec.dot(nn));
	return yaw;
}
auto Node::calculate_dir_vector(Node& node)->Vector2d {
	//Direction Vector from Node to *this
	Vector2d dir_vector(0, 0);
	dir_vector = coordinates - node.get_coordinates();
	if (dir_vector.isZero()) {
		std::cout << "calculate dir vector: Warning: dir_vector is null! "
				<< std::endl;
	}

	return dir_vector;
}
auto Node::calculate_cost()->bool {
	//Precondition: Node is complete, e.g. correct yaw, coor, parent etc.
	Vector2d dir_vector = calculate_dir_vector(*parent);
	double eukl_cost = dir_vector.norm();
	double yaw_diff = abs(yaw - parent->get_yaw());
	//TODO Absprache, wie die Kostenfkt. aussehen soll. Mehrkosten hier max *pi/2
	cost = eukl_cost * (1 + yaw_diff);
	if (cost != 0) {
		return true;
	} else {
		return false;
	}
}

auto Node::reached_goal()->bool {
	if (!(coordinates[0] < GOAL_AREA[0]) && !(coordinates[1] < GOAL_AREA[1])
			&& !(coordinates[0] > (GOAL_AREA[0] + GOAL_AREA[2]))
			&& !(coordinates[1] > (GOAL_AREA[1] + GOAL_AREA[3]))) {
		return true;
	}
	return false;
}
auto Node::is_reachable(Node& parent, Vector2d& dir_vector)->bool {
	//Tests if parent can reach *this (Node ist reachable from parent)
	double par_yaw=parent.get_yaw();
	if (std::abs((double) (dir_vector.norm() - 1)) > ACCURACY) {
		std::cout << "Warning! Direction Vector is not normalised! \n"
				<< dir_vector << std::endl;
	}
	double dir_yaw= calculate_yaw_from_vec(dir_vector);
	double diff =(dir_yaw-par_yaw);
	if (diff<0){
		diff *=-1;
	}
	if (diff > MAX_ANGLE){
		return false;
	} else {
		return true;
	}

}
auto Node::not_to_near(Node& parent)->bool {
	/*
	 * DOC
	 * Funktion checks if node *this
	 * is to near for his parent
	 * TODO check correctness with examples
	 */
	Vector2d right_circle_center;
	Vector2d left_circle_center;
	//calculate orthogonal vectors to yaw-anglefloat
	double par_yaw = parent.get_yaw();
	double x,y;
	if (abs(par_yaw-90) <0.0001){
		right_circle_center<<1,0;
	} else if (abs(par_yaw-270)<0.0001){
		right_circle_center<<-1,0;
	} else {
		x= sqrt(tan(par_yaw)*tan(par_yaw)/(tan(par_yaw)*tan(par_yaw)+1));
		y=sqrt(1-x*x);
		//First Szenario: Auto looks in Positive y direction -> x of 90° vec always positive
		if (0<par_yaw && par_yaw<180){
			right_circle_center<<x,y;
		//Second: Auto looks in negative y direction -> x of 90° vec always negative
		} else {
			right_circle_center<<-x,y;
		}

	}
	right_circle_center.normalize();
	right_circle_center *= STEERING_ANGLE_RADIUS;
	left_circle_center = right_circle_center * (-1);
	right_circle_center = parent.get_coordinates() + right_circle_center;
	left_circle_center = parent.get_coordinates() + left_circle_center;
	double distance_right = (coordinates - right_circle_center).norm();
	double distance_left = (coordinates - left_circle_center).norm();
	if (distance_right < STEERING_ANGLE_RADIUS
			|| distance_left < STEERING_ANGLE_RADIUS) {
		return false;
	}
	return true;
}
auto Node::check()->bool {
	if (coordinates.isZero()) {
		std::cout << "Check: Coordinates are Zero" << std::endl;
		return false;
	}
	if (yaw < 0 || yaw > 2 * M_PI) {
		std::cout << "Check: Yaw is negativ or to big: " << yaw << std::endl;
		return false;
	}
	if (parent == nullptr) {
		std::cout << "Check: Parent is nullptr!" << std::endl;
		return false;
	}
	if (validation == Val::invalid || validation == Val::unknown) {
		std::cout << "Check: Validation is unkown or invalid" << std::endl;
		return false;
	}
	if (cost <= 0) {
		std::cout << "Check: Costs are 0 or negative" << std::endl;
		return false;
	}
	return true;
}

auto Node::project_to_parent(Node&parent)->bool {
	Vector2d dir_vector;
	if (&parent == nullptr) {
		std::cout << "project to parent: Parent is null!" << std::endl;
		return false;
	}
	dir_vector = calculate_dir_vector(parent);
	if (dir_vector.norm() < STEPSIZE) {
		//Node ist bereits nah genug dran
		return true;
	}
	dir_vector.normalize();
	dir_vector *= STEPSIZE;
	coordinates = parent.get_coordinates() + dir_vector;
	return true;
}

Node::Node(Vector2d& coor) :
		coordinates(coor) {
	if (coor.isZero()) {
		std::cout << "Warning: Node is initialized with 0" << std::endl;
	}
	yaw=0;
	cost = 2 * RANGE;
	parent = nullptr;
	validation = Val::unknown;
}
Node::Node() {
	//default values
	coordinates << 2 * RANGE, 2 * RANGE;
	yaw = 0;
	cost = 2 * RANGE;
	parent = nullptr;
	validation = Val::unknown;
}
Node::Node(Vector2d& coor, double alpha, Node* parent, Val val, double c) :
		coordinates(coor), yaw(alpha), parent(nullptr), validation(val), cost(
				c) {
	if (coor.isZero()) {
		std::cout
				<< "Node::Node(Full): Warning! Node.coordinates is initialized with (0,0)! "
				<< std::endl;
	}
	if (parent == nullptr) {
		std::cout << "Node::Node(Full): Warning! Node has no parent! "
				<< std::endl;
	}
}


auto Node::get_validation()->Val {
	return validation;
}
auto Node::get_yaw()->double {
	//TODO Fehler auf Node spezifizieren
	if (yaw<0) {
		std::cout << "Node::get_yaw: Warning! yaw is negative! " << std::endl;
	}
	return yaw;
}
auto Node::get_coordinates() -> Vector2d& {
	return coordinates;
}
auto Node::get_parent_pointer() ->Node* {
	if (parent == nullptr) {
		std::cout << "Node::get_parent_pointer: Warning! Node has no parent! "
				<< std::endl;
	}
	return parent;
}
auto Node::get_cost()->double {
	if (cost == 0) {
		std::cout << "Node::Get_costs: Warning! Node has no costs!"
				<< std::endl;
	}
	return cost;
}

auto Node::set_parent(Node* node)->void {
	if (node == nullptr) {
		std::cout << "Node::set_parent: Warning! parent is set to null"
				<< std::endl;
	}
	parent = node;
}
auto Node::set_coordinates(Vector2d& coor)->void {
	if (coor.isZero()) {
		std::cout << "Node::set_coordinates: Warning!  coor is zero!"
				<< std::endl;
	}
	coordinates = coor;
}
auto Node::set_validation(Val enumVal)->void {
	validation = enumVal;
}
auto Node::print_node()->void {
	std::cout << "Coordinates: " << coordinates << std::endl;
	std::cout << "Yaw: " << yaw<< std::endl;
	std::cout << "Parent: " << parent << std::endl;
	std::cout << "Costs to node: " << cost << std::endl;
}
auto Node::print_node_short()->void {
	std::cout << "Node with cost: " << cost << std::endl;
}
Node::~Node() {
}


