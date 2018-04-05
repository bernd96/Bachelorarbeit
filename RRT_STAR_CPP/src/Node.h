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
	//absolut euklid coordinates
		Vector2d coordinates;
	//absolut orientation vector
		Vector2d orientation;
		Node* parent;
		//3 possibilities: unkown:-1, valid:1, invalid:0
		Val validation;
		//costs to get to that node
		float cost;



	public:

		//Überlegung: Delegieren von Konstruktoren. Dazu müsste man allerdings überall Standartwerte angeben...
		Node(const Vector2d& coor);

		Node(const Vector2d& coor,Vector2d& ori);
		Node(const Vector2d& coor,Vector2d& ori, Node* parent, Val validation,float cost);

		auto get_coordinates()->Vector2d;
		auto get_orientation()->Vector2d;
		auto get_parent_pointer() const -> Node*;
		auto get_cost() const -> int;
		auto get_validation() const -> Val;

		auto set_coordinates(Vector2d&)->void;
		auto set_validation(Val)->void;

		auto calculate_dir_vector(Node& node)->Vector2d;
		auto calculate_orientation()->bool;
		auto project_to_parent(std::list<Node>& list_of_nodes)->bool;
		auto easy_set_parent(std::list<Node>& list_of_nodes)->bool;

		auto easy_look_for_parent(std::list<Node>& list_of_nodes)->bool;
		auto not_to_near(Node& parent)->bool;
		auto reached_goal()->bool;
		auto is_reachable(Node& parent,const Vector2d& dir_vector)->bool;

		//auto search_parent(std::vector<std::list<Node>>&)-> void;

		//auto calculate_parent(std::vector<std::list<Node>>&, int)-> void;
		//auto insert_node(std::vector<std::list<Node>>& construct_of_nodes)->Vector2d;
		virtual ~Node();

		auto print_node_short()->void;
		auto print_node()->void;
};

#endif /* NODE_H_ */
