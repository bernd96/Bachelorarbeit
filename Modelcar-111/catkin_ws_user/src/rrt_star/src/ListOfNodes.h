/*
 * ListOfNodes.h
 *
 *  Created on: 26.04.2018
 *      Author: name-not-found
 */
#include <Node.h>
#ifndef SRC_LISTOFNODES_H_
#define SRC_LISTOFNODES_H_

class ListOfNodes {
	int size;
public:
	auto size()->int;
	auto add_node(const Node&node)->void;
	auto find_node(const Node&node)->void;

	auto find_parents(const Node&node, std::list<Node>&parents)->bool;


	ListOfNodes();
	virtual ~ListOfNodes();
};

#endif /* SRC_LISTOFNODES_H_ */
