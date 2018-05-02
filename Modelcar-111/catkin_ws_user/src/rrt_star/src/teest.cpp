

/*
 * ListOfNodes.cpp
 *
 *  Created on: 26.04.2018
 *      Author: name-not-found
 */

#include "ListOfNodes.h"
#include <list>
#include "const.h"
#include <vector>

using namespace std;

auto size()->int{
	return size;
}



ListOfNodes::ListOfNodes(int rows, int columns) {
	list<Node>entry;
	vector<list<Node>> row;
	row.resize(columns, row);


}

ListOfNodes::~ListOfNodes() {
	// TODO Auto-generated destructor stub
}
