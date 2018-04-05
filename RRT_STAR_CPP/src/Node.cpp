/*
 * Node.cpp
 *
 *  Created on: 19.02.2018
 *      Author: Arbeit
 */

#include "Node.h"
#include <iostream>
#include <eigen3/Eigen/Dense>

using namespace Eigen;

Node::Node(const Vector2f& coor) :
		coordinates(coor) {
	if (coor.isZero()){
		std::cout << "Warning: Node is initialized with 0"<<std::endl;
	}
}
Node::Node(const Vector2f& coor, const Vector2f& ori) :
		coordinates(coor), orientation(ori) {
	if (coor.isZero()){
			std::cout << "Warning: Node is initialized with 0"<<std::endl;
		}
}
auto Node::get_parent_pointer() const ->Node* {
	return parent;
}

auto Node::get_cost() const->int {
	return cost;
}

auto Node::calculate_parent(
		std::vector<std::list<Node> >& construct_of_nodes, int number_of_nodes)->void {
	Vector2i node_pos =this->insert_node(construct_of_nodes);
	bool parent_found=false;
	bool construct_searched=false;
	float distance=5000000000;
	Node* tmp = NULL;
	int local_restrict=node_pos[0];
	for (int i = 0; i < number_of_nodes/10 || (construct_searched && parent_found) ; ++i) {
		if (i%2!=0){
			local_restrict=node_pos[0]+(i+1)/2;
		} else {
			local_restrict=node_pos[0]- i/2;
			std::cout<< "Local restrict index in calculate:parent: " << local_restrict << std::endl;
		}
		for (auto &iter : construct_of_nodes[local_restrict]) {
			Vector2f dist_vec=iter.coordinates-this->coordinates;
			float tmp_distance=dist_vec.norm();
			if (distance<tmp_distance){
				continue;
			} else {
				if(this->is_reachable(iter)){
					parent_found=true;
					distance=tmp_distance;
					tmp=&iter;
				}
			}
		}
		if(local_restrict==-1){
			construct_searched=true;
		}
	}
	if (tmp!=NULL){
		this->parent=tmp;
	} else {
		std::cout << "Node is deleted."<< std::endl;
	}


}

auto Node::set_validation(Val enumVal)->void {
	validation=enumVal;
}

auto Node::insert_node(
		std::vector<std::list<Node>>& construct_of_nodes)->Vector2i {
	/*
	 * construct_of_nodes ist ein vector aus Listen.
	 * Jede Liste deckt einen Bereich von aufeinanderfolgenden x-Koordinaten ab, e.g. von 0-19 oder von 80-99.
	 * Jede Liste enthält Knoten in ihrem x-Wertbereich, aufsteigend nach y-Werten sortiert.
	 * Knoten Einfügen:
	 * Auswahl der Liste nach x-Wert
	 * Durchiterieren der Liste bis y-Wert höher ist -> davor einfügen (emplace())
	 */
	int x_pos = ((this->coordinates[0]) / 20) * 25;
	Vector2i insert_pos(x_pos,0);
	//wenn Liste leer: Element anfügen
	if (construct_of_nodes[x_pos].empty()){
		construct_of_nodes[x_pos].push_back(*this);
	} else {
		for (std::list<Node>::iterator iter = construct_of_nodes[x_pos].begin();
			iter != construct_of_nodes[x_pos].end(); ++iter) {
			if (this->coordinates[1] > iter->coordinates[1]) {
				//construct_of_nodes[x_pos].emplace(iter, this);
				insert_pos[1]=std::distance(construct_of_nodes[x_pos].begin(), iter)-1;

			}
		}
	}
	return insert_pos;
}
auto Node::is_reachable(const Node& parent)->bool {
	return false;
}

auto Node::cos_angle(Eigen::Vector2f parent)->float {
	Eigen::Vector2f direction(this->coordinates-parent);
	direction.normalize();
	this->orientation.normalize();
	return direction.dot(this->orientation);
}
auto Node::get_validation()const->Val{
	return validation;
}

Node::~Node() {
}

