/*
 * Node.cpp
 *
 *  Created on: 19.02.2018
 *      Author: Arbeit
 */

#include "Node.h"
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <Main.h>
#include <math.h>
#include <iomanip>


using namespace Eigen;


auto Node::calculate_yaw()->bool {
	double par_yaw = parent->get_yaw();
	Vector2d dir = calculate_dir_vector(*parent);
	dir.normalize();
	double dir_yaw = calculate_yaw_from_vec(dir);
	yaw= dir_yaw+(dir_yaw-par_yaw)% (2* M_PI);
}
;
auto Node::reached_goal()->bool {
	if (!(coordinates[0] < GOAL_AREA[0]) && !(coordinates[1] < GOAL_AREA[1])
			&& !(coordinates[0] > (GOAL_AREA[0] + GOAL_AREA[2]))
			&& !(coordinates[1] > (GOAL_AREA[1] + GOAL_AREA[3]))) {
		return true;
	}
	return false;
}
auto Node::is_reachable(Node& parent, const Vector2d& dir_vector)->bool {
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
auto calculate_yaw_from_vec(Vector2d vec)->double{
	Vector2d nn(1,0);
	double yaw = std::acos(vec.dot(nn));
	return yaw;
}

auto Node::easy_set_parent(ListOfNodes & construct, std::list<Node>&parents) ->bool {
	Vector2d dir_vector(0, 0);
	double min_cost = RANGE * 2;
	bool parent_found = construct.find_parents(*this,parents);

	for (auto &iter : list_of_nodes) {
		dir_vector = calculate_dir_vector(iter);
		if (dir_vector.norm() < RADIUS) {
			cost = iter.get_cost() + dir_vector.norm();
			dir_vector.normalize();
			if (cost < min_cost && is_reachable(iter, dir_vector)
					&& not_to_near(iter)) {
				min_cost = cost;
				parent = &iter;
				parent_found = true;
			}
		}
	}
	return parent_found;

}
auto Node::not_to_near(Node& parent)->bool {
	/*
	 * DOC
	 * Funktion checks if node *this is to near for his parent
	 */
	Vector2d right_circle_center;
	Vector2d left_circle_center;
	//calculate orthogonal vectors to yaw-angle
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

auto Node::easy_look_for_parent(std::list<Node>& list_of_nodes) ->bool {
	/*
	 * DOC:
	 * Sucht einen potentiellen Vater für diesen Knoten, der diesen Knoten erreichen kann,
	 * und setzt ihn als Parent. Gibt false zurück, falls kein parent gefunden.
	 */

	Vector2d dir_vector(0, 0);
	bool parent_found = false;
	long tmp_distance;
	long min_distance = RANGE * 2;
	for (auto &iter : list_of_nodes) {
		dir_vector = calculate_dir_vector(iter);
		tmp_distance = dir_vector.norm();
		dir_vector.normalize();
		if (tmp_distance < min_distance && is_reachable(iter, dir_vector)) {
			min_distance = tmp_distance;
			parent = &iter;
			parent_found = true;

		}
	}
	return parent_found;
}
auto Node::project_to_parent(std::list<Node>& list_of_nodes)->bool {
	Vector2d dir_vector;
	if (parent == nullptr) {
		std::cout << "project to parent: Vector has no parent to project!" << std::endl;
		return false;
	}
	dir_vector = calculate_dir_vector(*parent);
	if (dir_vector.norm() < STEPSIZE) {
		//Node ist bereits nah genug dran
		return true;
	}
	dir_vector.normalize();
	dir_vector *= STEPSIZE;
	coordinates = parent->get_coordinates() + dir_vector;
	return true;
}

auto Node::calculate_dir_vector(Node& node)->Vector2d {
	Vector2d dir_vector(0, 0);
	dir_vector = coordinates - node.get_coordinates();
	//TODO Fehlerausgabe spezifizieren
	if (dir_vector.isZero()) {
		std::cout << "calculate dir vector: Warning: dir_vector is null! " << std::endl;
	}

	return dir_vector;
}

Node::Node(const Vector2d& coor) :
		coordinates(coor) {
	if (coor.isZero()) {
		std::cout << "Warning: Node is initialized with 0" << std::endl;
	}
	yaw=0;
	cost = 2 * RANGE;
	parent = nullptr;
	validation = Val::unknown;
}
Node::Node(const Vector2d& coor,double alpha) :
		coordinates(coor), yaw(alpha) {
	if (coor.isZero()) {
		std::cout << "Warning: Node.coordinates is initialized with (0,0)! "
				<< std::endl;
	}
	cost = 2 * RANGE;
	parent = nullptr;
	validation = Val::unknown;
}
Node::Node(const Vector2d& coor, double alpha, Node* parent, Val val, float c) :
		coordinates(coor), yaw(alpha), parent(this), validation(val), cost(
				c) {
	if (coor.isZero()) {
		std::cout << "Warning: Node.coordinates is initialized with (0,0)! "
				<< std::endl;
	}
	if (parent == nullptr) {
		std::cout << "Warning: Node has no parent! " << std::endl;
	}
}
auto Node::get_validation() const->Val {
	return validation;
}
auto Node::get_yaw()->double {
	//TODO Fehler auf Node spezifizieren
	if (yaw<0) {
		std::cout << "Warning from get_yaw(): yaw is negative! " << std::endl;
	}
	return yaw;
}
auto Node::get_coordinates() -> Vector2d {
	return coordinates;
}
auto Node::get_parent_pointer() const ->Node* {
	if (parent == nullptr) {
		std::cout << "Warning! Node has no parent! " << std::endl;
	}
	return parent;
}
auto Node::get_cost() const->int {
	if (cost == 0) {
		std::cout << "Warning! Node has no costs!" << std::endl;
	}
	return cost;
}
auto Node::set_coordinates(Vector2d& coor)->void {
	coordinates = coor;
}
//auto Node::calculate_parent(std::vector<std::list<Node> >& construct_of_nodes,
//		int number_of_nodes)->void {
//	Vector2d node_pos(0, 0);
//	try {
//		node_pos = this->insert_node(construct_of_nodes);
//	} catch (std::out_of_range& e) {
//		std::cerr << e.what() << std::endl;
//	}
//	bool parent_found = false;
//	bool upper_bound_reached = false;
//	bool lower_bound_reached = false;
//	int construct_searched = 0;
//	int size = number_of_nodes/10;
//	int row = node_pos[0];
//	float distance = 5000000000;
//	float tmp_distance;
//	Vector2d dist_vec;
//	Node* tmp = NULL;
//	int local_restrict = node_pos[0];
//	/*
//	 * for-schleife iteriert durch Liste
//	 * des Knoten selbst und dann abwechselnd
//	 * durch die dadrüber und dadrunter
//	 * liegende Listen in construct_of_nodes
//	 */
//	for (int i = 0; ((construct_searched < 2) && parent_found) || i < size;
//			++i) {
//		for (auto &iter : construct_of_nodes[row]) {
//			dist_vec = iter.coordinates - this->coordinates;
//			tmp_distance = dist_vec.norm();
//			if (distance < tmp_distance) {
//				continue;
//			} else {
//				if (this->is_reachable(iter)) {
//					parent_found = true;
//					distance = tmp_distance;
//					tmp = &iter;
//				}
//			}
//		}
//		//Oberste Liste erreicht
//		if (upper_bound_reached) {
//			//Linear nach unten gehen
//		} else if(lower_bound_reached){
//			//Linear nach oben gehen
//		}
//		if (i % 2 == 0) {
//			++construct_searched;
//			row = row + i;
//			if (row > size-1) {
//				upper_bound_reached = true;
//				row=row-i-1;
//			}
//		} else {
//			row = row - i;
//			if (row < 1) {
//				lower_bound_reached = true;
//			}
//		}
//
//	}
//	if (tmp != NULL) {
//		this->parent = tmp;
//	} else {
//		std::cout << "Node is deleted." << std::endl;
//	}
//
//}

//auto Node::insert_node(
//		std::vector<std::list<Node>>& construct_of_nodes)->Vector2d {
//	/*
//	 * construct_of_nodes ist ein vector aus Listen.
//	 * Jede Liste deckt einen Bereich von aufeinanderfolgenden x-Koordinaten ab, e.g. von 0-19 oder von 80-99.
//	 * Jede Liste enthält Knoten in ihrem x-Wertbereich, aufsteigend nach y-Werten sortiert.
//	 * Knoten Einfügen:
//	 * Auswahl der Liste nach x-Wert
//	 * Durchiterieren der Liste bis y-Wert höher ist -> davor einfügen (emplace())
//	 */
//	int x_pos = ((coordinates[0]) / 20);
//	if (x_pos > 49 || x_pos < 0) {
//		throw std::out_of_range("x_pos is out_of_bounds" + x_pos);
//	} else {
//		Vector2d insert_pos(x_pos, 0);
//		//wenn Liste leer: Element anfügen
//		if (construct_of_nodes[x_pos].empty()) {
//			construct_of_nodes[x_pos].push_back(*this);
//		} else {
//
//			for (auto &it : construct_of_nodes[x_pos]) {
//				float this_coor = coordinates[1];
//				std::cout << this_coor << std::endl;
//				std::cout << it.coordinates[0];
//				float tmp_coor = it.coordinates[1];
//				if (this_coor > tmp_coor) {
//					//construct_of_nodes[x_pos].emplace(iter, this);
//					//insert_pos[1] = std::distance(construct_of_nodes[x_pos].begin(),it) - 1;
//
//				}
//			}
//		}
//		return insert_pos;
//	}
//}
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
