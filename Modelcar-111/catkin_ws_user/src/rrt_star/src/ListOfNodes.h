/*
 * ListOfNodes.h
 *
 *  Created on: 26.04.2018
 *      Author: name-not-found
 */
#include "Node.h"
#include <list>
#ifndef LISTOFNODES_H_
#define LISTOFNODES_H_

class ListOfNodes {
private:
	//Kantenlänge einer quadratischen Zelle in m
	double cell_size;
	std::vector<std::vector<std::list<Node>>> grid;
public:
	auto add_node(Node &node)->void;
	auto find_nearest_neighbour(Node&node)->bool;
	auto radius_find_nearest_neighbours(Node&node,
			std::list<Node>& neighbours)->bool;

	auto rewire(Node&node)->void;
	ListOfNodes(int size, double cellsize);
	virtual ~ListOfNodes();
};


#endif /* SRC_LISTOFNODES_H_ */
