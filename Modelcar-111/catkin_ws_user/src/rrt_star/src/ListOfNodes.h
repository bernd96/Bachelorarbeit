/*
 * ListOfNodes.h
 *
 *  Created on: 26.04.2018
 *      Author: name-not-found
 */
#include "Node.h"
#include <list>
#include <eigen3/Eigen/Dense>
#ifndef LISTOFNODES_H_
#define LISTOFNODES_H_

class ListOfNodes {
private:
	//Kantenlänge einer quadratischen Zelle in m
	double cell_size;
	std::vector<std::vector<std::list<Node>>> grid;
public:
	auto add_node(const Node &node)->void;
	auto find_nearest_neighbour(Node&node,
			Node &parent)->bool;
	auto radius_find_nearest_neighbours(Node&node,
			std::list<Node> neighbours)->bool;

	
	ListOfNodes(int y_rows, int x_columns, int cellsize);
	virtual ~ListOfNodes();
};


#endif /* SRC_LISTOFNODES_H_ */
