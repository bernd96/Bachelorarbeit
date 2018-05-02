/*
 * Node.h
 *
 *  Created on: 19.02.2018
 *      Author: Arbeit
 */

#include <eigen3/Eigen/Dense>
#include <list>
#ifndef NODE_H_
#define NODE_H_

using namespace Eigen;

enum class Val{invalid, valid, unknown};
class Node {
	private:

	//yaw angle of car when passing the node
		double yaw;
		Node* parent;
		//3 possibilities: unkown:-1, valid:1, invalid:0
		Val validation;
		//costs to get to that node
		float cost;



	public:
	//absolut euklid coordinates in m
	Vector2d coordinates;

		//Überlegung: Delegieren von Konstruktoren. Dazu müsste man allerdings überall Standartwerte angeben...
		Node(const Vector2d& coor);

		Node(const Vector2d& coor,double yaw);
		Node(const Vector2d& coor,double yaw, Node* parent, Val validation,float cost);

	const auto get_coordinates()->Vector2d;
		auto get_yaw()->double;
		auto get_parent_pointer() const -> Node*;
		auto get_cost() const -> int;
		auto get_validation() const -> Val;

		auto set_coordinates(Vector2d&)->void;
		auto set_validation(Val)->void;

	auto calculate_dir_vector(Node& node)->Vector2d;
		auto calculate_yaw()->bool;
		auto project_to_parent(ListOfNodes& construct)->bool;
		auto easy_set_parent(ListOfNodes& construct)->bool;

		auto easy_look_for_parent(ListOfNodes& construct)->bool;
		auto not_to_near(Node& parent)->bool;
		auto reached_goal()->bool;
		auto is_reachable(Node& parent,const Vector2d& dir_vector)->bool;

		auto calculate_yaw_from_vec(Vector2d vec)->double;

		//auto search_parent(std::vector<std::list<Node>>&)-> void;

		//auto calculate_parent(std::vector<std::list<Node>>&, int)-> void;
		//auto insert_node(std::vector<std::list<Node>>& construct_of_nodes)->Vector2d;
		virtual ~Node();

		auto print_node_short()->void;
		auto print_node()->void;
};

#endif /* NODE_H_ */
