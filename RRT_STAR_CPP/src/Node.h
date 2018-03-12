/*
 * Node.h
 *
 *  Created on: 19.02.2018
 *      Author: Arbeit
 */

#include <eigen3/Eigen/Dense>
#ifndef NODE_H_
#define NODE_H_

class Node {
private:
	Node* parent;

	//3 possibilities: unkown:-1, valid:1, invalid:0
	//if the node is invalid, it will be deleted after init
	int is_valid;

	//costs to get to that node
	float cost;
public:
	Node();
	//absolut euklid coordinates
	Eigen::Vector2f coordinates;
	//absolut orientation vector
	Eigen::Vector2f orientation;



	Node* get_parent_pointer();
	int get_cost();
	void set_parent_pointer(Node*);
	void set_validation(int);

	int get_validation();


	virtual ~Node();
};

#endif /* NODE_H_ */
