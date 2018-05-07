/*
 * Node.h
 *
 *  Created on: 19.02.2018
 *      Author: Arbeit
 */

#include <eigen3/Eigen/Dense>
#include <list>
#include <stdlib.h>
#ifndef NODE_H_
#define NODE_H_

using namespace Eigen;

enum class Val{invalid, valid, unknown};
class Node {
	private:

	//yaw angle of car when passing the nodestd::list<Node>
		double yaw;
	Node* parent;
	//dir_vector from parent to Node
	Vector2d dir_vector;
		//3 possibilities: unkown:-1, valid:1, invalid:0
		Val validation;
		//costs to get to that node
	double cost;
	//absolut euklid coordinates in m
	Vector2d coordinates;

	public:

	//Überlegung: Delegieren von Konstruktoren. Dazu müsste man allerdings überall Standartwerte angeben...
	Node(Vector2d& coor);

	Node();
	Node(Vector2d coor, double yaw, Node* parent, Vector2d dir,
			Val validation,
			double cost);
	Node(const Node&node);
	//TODO Operator= kopierkonstruktor  überladen

	auto get_coordinates_fast() -> Vector2d&;
	auto get_coordinates() const-> Vector2d;
	auto get_yaw() const->double;
	auto get_parent_pointer() const-> Node*;
	auto get_cost() const-> double;
	auto get_validation() const-> Val;
	auto get_dir_vector() const ->Vector2d;

	auto set_coordinates(Vector2d&)->void;
	auto set_validation(Val)->void;
	auto set_parent(Node& node)->void;
	auto set_dir_vector()->bool;
	auto set_dir_vector(Vector2d& dir)->void;


	//Helper Functions
	auto calculate_dir_vector(Node& node, Vector2d&dir) ->bool;
	auto calculate_cost(const Node&parent) const->double;
	auto calculate_yaw_and_cost()->void;

	auto calculate_yaw_from_vec(Vector2d& vec) const->double;
	auto calculate_cost()->bool;
	auto calculate_direction(Vector2d&direct) const ->void;

	auto project_to_parent(Node&parent)->bool;

	//Check validity
	auto not_to_near(Node& parent) const->bool;
	auto is_reachable(const Node& parent,
			const Vector2d& dir_vector) const->bool;
	auto check()->bool;

	auto reached_goal()->bool;


	virtual ~Node();
	auto equals(Node& b) ->bool;

	auto print_node_short()->void;
	auto print_node() const->void;
};
#endif /* NODE_H_ */
