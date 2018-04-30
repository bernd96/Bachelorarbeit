/*
 * ListOfNodes.h
 *
 *  Created on: 26.04.2018
 *      Author: name-not-found
 */
#include <Node.h>
#include <list>
#ifndef SRC_LISTOFNODES_H_
#define SRC_LISTOFNODES_H_

class ListOfNodes {
	int size;
	int NUMBER_OF_ROWS;

	std::vector<std::vector<std::list<Node>>> grid;



public:
	auto size()->int;
	auto add_node(const Node &node)->void;
	auto find_nearest_neighbour(const Node&node)->bool;

	auto rewire_Nodes(Node & node)->void;
	auto find_parents(const Node&node, std::list<Node>&parents)->bool;

	ListOfNodes(int rows, int columns);

	virtual ~ListOfNodes();
};

#endif /* SRC_LISTOFNODES_H_ */
