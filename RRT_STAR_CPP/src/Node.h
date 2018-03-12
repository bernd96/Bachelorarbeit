/*
 * Node.h
 *
 *  Created on: 19.02.2018
 *      Author: Arbeit
 */


#ifndef NODE_H_
#define NODE_H_

class Node {
private:
	Node* parent;

	//3 possibilities: unkown:-1, valid:1, invalid:0
	//if the node is invalid, it will be deleted after init
	int isvalid;

	//costs to get to that node
	float cost;
public:
	//absolut euklid coordinates
	float x_coor;
	float y_coor;
	//absolut orientation vector
	float ori_x;
	float ori_y;

	Node(float,float,float,float);


	Node* get_parent_pointer();
	int get_cost();

	void set_parent_pointer(Node*);
	void set_valid(int);

	int calculate_and_set_cost(Node*, Calculator*);


	void calculate_coordinates_with_stepsize(int);
	bool is_reachable(Node*);
	int is_valid();


	virtual ~Node();
};

#endif /* NODE_H_ */
