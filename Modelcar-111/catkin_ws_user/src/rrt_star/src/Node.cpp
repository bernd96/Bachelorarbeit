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
#include <cmath>
#include <iomanip>

using namespace Eigen;


auto Node::calculate_yaw_cost(Node&parent, Vector2d&dir_new, double& new_yaw,
		double & new_cost) ->void {
	//calculate the costs from parent to this without changing anything
	//call when *this dont has a parentpointer
	//dir_new is direction vector from parent to node
	Vector2d dir_par;

	double par_yaw = parent.get_yaw();
	double eukl_cost = dir_new.norm();
	dir_new.normalize();
	parent.calculate_direction(dir_par);
	double alpha = M_PI-acos(dir_par.dot(dir_new));
	//new_yaw: yaw of node if parent is the parent
	new_yaw=fmod((2 * alpha + par_yaw), (2 * M_PI));
	//mehrkosten: Eukl bei gerader Strecke, 7* euklid bei 360°
	//Durch Verschiebung der Bedeutung von Alpha und der Konstante 1 variationen möglich
	new_cost = eukl_cost * (1 + (2*M_PI - 2*alpha));
}

auto Node::calculate_direction(Vector2d&direct) const->void {
	//Put normalised direction vector of own yaw into Vector direct
	direct[0] = cos(yaw);
	direct[1] = sin(yaw);
}
//auto Node::calculate_yaw_from_vec(Vector2d& vec) const->double {
//	//deprecated
//
//	//precondition: vec has to be normalized
//	Vector2d dir = vec;
//	double ret_yaw;
//	//y is positive, yaw from [0-M_PI)
//	if (dir[1] > 0) {
//		ret_yaw = std::acos(dir[0]);
//	} else {
//		//y is negative, yaw from [M_PI-2*M_PI
//		ret_yaw = 2 * M_PI - std::acos(dir[0]);
//	}
//
//	return ret_yaw;
//}
auto Node::calculate_dir_vector(Node& node, Vector2d& dir) ->bool {
	//Direction Vector from Node to *this
	dir = this->get_coordinates_fast() - node.get_coordinates_fast();
	/*	if (dir.isZero()) {
		std::cout << "calculate dir vector: Warning: dir_vector is null! "
				<< std::endl;
		return false;
	 }*/
	return true;
}
auto Node::calculate_cost()->bool {
	cost = parent->get_cost() + dir_vector.norm();
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
//auto Node::is_reachable(const Node& parent, const Vector2d& dir_v) const->bool {
//	//deprecated
//	//Tests if parent can reach *this (Node ist reachable from parent)
//	Vector2d dir = dir_v.normalized();
//	double par_yaw=parent.get_yaw();
//	/*	if (std::abs((double) (dir.norm() - 1)) > ACCURACY) {
//		std::cout << "Warning! Direction Vector is not normalised! \n"
//				<< dir
//				<< std::endl;
//	 }*/
//	double dir_yaw = calculate_yaw_from_vec(dir);
//	double diff = abs(dir_yaw - par_yaw);
//	if (diff > M_PI) {
//		diff = 2 * M_PI - diff;
//	}
//	if (diff > MAX_ANGLE){
//		return false;
//	} else {
//		return true;
//	}
//
//}
auto Node::not_to_near(Node& parent) const->bool {
	/*
	 * DOC
	 * Funktion checks if node *this
	 * is to near for his parent
	 */
	Vector2d left_circle_center, right_circle_center;
	//calculate orthogonal vectors to yaw-anglefloat
	double par_yaw = parent.get_yaw();
	Vector2d par_coor = parent.get_coordinates_fast();
	double x = -sin(par_yaw);
	double y = cos(par_yaw);
	left_circle_center << x, y;
	left_circle_center *= STEERING_ANGLE_RADIUS;
	right_circle_center = left_circle_center * (-1);
	left_circle_center += par_coor;
	right_circle_center += par_coor;
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
	http: //www.cplusplus.com/reference/memory/shared_ptr/
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
	if (dir_vector.norm() < 0 || dir_vector.norm() > 2 * RANGE || (dir_vector.norm())== 0) {
		std::cout << "Check: Dir_vector ist seltsam: " << dir_vector
				<< std::endl;

	}
	return true;
}

auto Node::project_to_parent(Node&parent)->bool {
	Eigen::GenericNumTraits::Real norm = dir_vector.norm();
	//Effects: new coordinates and new dir_vector
//	std::cout << "Entering proeject to parent..." << std::endl;
	/*
	if (&parent == nullptr) {
		std::cout << "project to parent: Parent is null!" << std::endl;d GOAL_AREA(-6, -6, 1, 1);

		return false;
	}

	 }*/
	//it is ok to change dir_vector, because node has new coordinates
	//projected if to far away or to close(if not reachable)
	/*	if (dist < STEPSIZE) {
		//Node ist bereits nah genug dran
		std::cout << "project to parent: Near enough" << std::endl;
		return true;
	 }*/
	if (norm > STEPSIZE || !not_to_near(parent)) {
		dir_vector /= norm;	//normalize
		dir_vector *= STEPSIZE;
		coordinates = parent.get_coordinates_fast() + dir_vector;
	}

	return true;
}
auto Node::simple_project()->double {
	//Effects: new coordinates and new dir_vector
//	std::cout << "Entering proeject to parent..." << std::endl;
	/*
	 if (&parent == nullptr) {
	 std::cout << "project to parent: Parent is null!" << std::endl;d GOAL_AREA(-6, -6, 1, 1);

	 return false;
	 }

	 }*/
	//it is ok to change dir_vector, because node has new coordinates
	//projected if to far away or to close, innerhalb der wendekreise
	/*	if (dist < STEPSIZE) {
	 //Node ist bereits nah genug dran
	 std::cout << "project to parent: Near enough" << std::endl;
	 return true;
	 }*/
	double norm = dir_vector.norm();
	if (norm > STEPSIZE) {
		dir_vector.normalize();	//normalize
		dir_vector *= STEPSIZE;
		coordinates = parent->get_coordinates_fast() + dir_vector;
	}


	return parent->get_coordinates() + norm;
}

auto Node::get_validation() const->Val {
	return validation;
}
auto Node::get_yaw() const->double {
	//TODO Fehler auf Node spezifizieren
	/*	if (yaw<0) {
		std::cout << "Node::get_yaw: Warning! yaw is negative! " << std::endl;
	 }*/
	return yaw;
}
auto Node::get_coordinates_fast() -> Vector2d& {
	return this->coordinates;
}
auto Node::get_parent_pointer() const->Node* {
	/*if (parent == nullptr) {
		std::cout << "Node::get_parent_pointer: Warning! Node has no parent! "
				<< std::endl;
	 }*/
	return parent;
}
auto Node::get_cost() const->double {
	/*if (cost == 0) {
		std::cout << "Node::Get_costs: Warning! Node has no costs!"
				<< std::endl;
	 }*/
	return cost;
}
auto Node::get_dir_vector() const->Vector2d {
	return dir_vector;
}
auto Node::get_coordinates() const->Vector2d {
	return coordinates;
}

auto Node::set_parent(Node& node)->void {
	if (&node == nullptr) {
		std::cout << "Node::set_parent: Warning! parent is set to null"
				<< std::endl;
	}
	this->parent = &node;
}
auto Node::set_dir_vector()->bool {
	//Preconditions: Node has coordinates, node has parent
	dir_vector = this->coordinates - parent->get_coordinates_fast();
	if (dir_vector.isZero()) {
		std::cout << "Node::set_dir_vector(): Warning! dir_vector is Zero"
				<< std::endl;
		return false;
	} else if (dir_vector.norm() <= 0) {
		std::cout << "Node::set_dir_vector(): Norm is terrible wrong!"
				<< std::endl;
		return false;
	}
	return true;
}
auto Node::set_dir_vector(Vector2d& dir)->void {
	if (dir.isZero()) {

		std::cout << "Node::set_dir_vector(): Warning! dir_vector would be Zero"<<std::endl;
		return;
	}
	dir_vector=dir;
}
auto Node::set_coordinates(Vector2d& coor)->void {
	coordinates = coor;
}
auto Node::set_validation(Val enumVal)->void {
	validation = enumVal;
}
auto Node::set_cost(double costs)->void{
	if(costs <=0){
		std::cout<<"Set cost: cost <=0, fail!"<<std::endl;
		return;
	}
	cost=costs;
}
auto Node::set_yaw(double ya)->void{
	if (ya<0 || ya > 2* M_PI){
		return;
	}
	yaw=ya;
}



auto Node::print_node() const->void {
	std::cout << "________________________" << std::endl;
	std::cout << "Coordinates: " << coordinates << std::endl;
	std::cout << "Yaw: " << yaw<< std::endl;
	std::cout << "Parent: " << parent << std::endl;
	std::cout << "Costs to node: " << cost << std::endl;
	std::cout << "Direction vector: " << dir_vector << std::endl;
	std::cout << "------------------------" << std::endl;

}
auto Node::print_node_short()->void {
	std::cout << "Node with cost: " << cost << std::endl;
}
auto Node::equals(Node&b) ->bool {
	if (this->get_coordinates_fast() == b.get_coordinates_fast()) {
		return true;
	}
	return false;
}

Node::Node(const Node&node) {
	this->coordinates = node.get_coordinates();
	this->cost = node.get_cost();
	this->dir_vector = node.get_dir_vector();
	this->parent = node.get_parent_pointer();
	this->validation = node.get_validation();
	this->yaw = node.get_yaw();
}
Node::Node(Vector2d& coor) :
		coordinates(coor) {
	if (coor.isZero()) {
		std::cout << "Warning: Node is initialized with 0" << std::endl;
	}
	yaw = 0;
	cost = 2 * RANGE;
	parent = nullptr;
	validation = Val::unknown;
	dir_vector << 0, 0;
}
Node::Node() {
	//default values
	coordinates << 2 * RANGE, 2 * RANGE;
	yaw = 0;
	cost = 2 * RANGE;
	parent = nullptr;
	validation = Val::unknown;
	dir_vector << 0, 0;
}
Node::Node(Vector2d coor, double alpha, Node* parent, Vector2d dir, Val val,
		double c) :
		coordinates(coor), yaw(alpha), parent(parent), dir_vector(dir), validation(
				val), cost(c) {
}

Node::~Node() {
}


