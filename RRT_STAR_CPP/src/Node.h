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

enum class Val{invalid, valid, unknown};
class Node {
private:
	Node* parent;
	//3 possibilities: unkown:-1, valid:1, invalid:0
	Val validation;
	//costs to get to that node
	float cost;
	//absolut euklid coordinates
	Eigen::Vector2f coordinates;
	//absolut orientation vector
	Eigen::Vector2f orientation;
public:
	//Überlegung: Delegieren von Konstruktoren. Dazu müsste man allerdings überall Standartwerte angeben...
	Node();
	Node(const Eigen::Vector2f& coor);
	Node(const Eigen::Vector2f& coor, Eigen::Vector2f& ori);
	Node(const Eigen::Vector2f& coor,const Eigen::Vector2f& ori, Node&, int,float);

	auto calculate_parent(std::vector<std::list<Node>>&, int)-> void;
	auto set_validation(Val)->void;
	auto insert_node(std::vector<std::list<Node>>&)->Eigen::Vector2i;
	auto is_reachable(Node& parent)->bool;
	auto search_parent(std::vector<std::list<Node>>&)-> void;

	auto get_parent_pointer() const -> Node*;
	auto get_cost() const -> int;
	auto get_validation() const -> Val;

	void set_parent_pointer(Node*);

	virtual ~Node();
};

#endif /* NODE_H_ */
