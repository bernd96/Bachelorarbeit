/*
 * Node.h
 *
 *  Created on: 19.02.2018
 *      Author: Arbeit
 */
#include <string>

#ifndef NODE_H_
#define NODE_H_

class Node {
private:
	//absolut euklid coordinates
	int x_coor;
	int y_coor;
	//absolut orientation vector
	int ori_x;
	int ori_y;

	Node* parent;

	//3 possibilities: invalid:0 , valid:1, unknown:-1
	int isvalid;


public:
	Node();
	int get_coordinates();
	bool set_coordinates();
	Node* get_parent();
	int get_orientation();
	virtual ~Node();
};

#endif /* NODE_H_ */
