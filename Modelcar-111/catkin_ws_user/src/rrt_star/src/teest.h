/*
 * ListOfNodes.h
 *
 *  Created on: 26.04.2018
 *      Author: name-not-found
 */
#include "Node.h"
#include <list>


class ListOfNodes {
private:

	std::vector<std::vector<std::list<Node>>> grid;


public:
	auto size()->int;
	auto add_node(const Node &node)->void;

	auto rewire_Nodes(Node & node)->void;
	auto find_parents(const Node&node, std::list<Node>&parents)->bool;

	ListOfNodes(int rows, int columns);
	virtual ~ListOfNodes();
};

#endif /* SRC_LISTOFNODES_H_ */
