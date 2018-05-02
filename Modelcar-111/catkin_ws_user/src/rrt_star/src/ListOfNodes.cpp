/*
 * ListOfNodes.cpp
 *
 *  Created on: May 2, 2018
 *      Author: besahre
 */

#include "ListOfNodes.h"
#include "const.h"

using namespace std;
ListOfNodes::ListOfNodes(int row, int column, int c) {
	cell_size=c;
	grid.resize(column);


	for (int i = 0; i < column; i++) {
		grid[i].resize(row);
	}


}

auto ListOfNodes::add_node(const Node& node)->void {
	int x_val = node.coordinates[0] / cell_size;
	int y_val = node.coordinates[1] / cell_size;
	grid[x_val][y_val].push_back(node);
	
}

auto ListOfNodes::find_nearest_neighbour(Node& node,
		Node& parent)->bool {
	//slow if only few nodes are inserted! (O(k³) worst case)
	//if many nodes are there: O(9* (n/k²)), k length of axis of grid
	bool found = false;
	int x_val = node.coordinates[0] / cell_size;
	int y_val = node.coordinates[1] / cell_size;
	double distance = RANGE * 2;
	Eigen::Vector2d dir_vector;
	for (int round = 1; !found && !(round > grid.size()); round++) {
		/*
		 * searches a square with size 1+2*round (3*3,5*5,7*7,9*9...)
		 * and with node in center for possible neighbours
		 * checks for reachability and nearest distance
		 */
		for (int j = 0; j < 1 + 2 * round; ++j) {
			//check if entry could be out of bounds:
			//bottom side out of bound
			while ((y_val - round + j < 0)) {
				j++;
			}
			//top side out of bound
			while ((y_val - round + j >= grid[x_val].size())) {
				j--;
				break;
			}
			for (int i = 0; i < 1 + 2 * round; ++i) {
				//left side out of bound
				while ((x_val - round + i < 0)) {
					i++;
				}
				//right side out of bound, avoid infinite loops
				while ((x_val - round + i >= grid.size())) {
					i--;
					break;
				}

				//searches grid entry for matches
				for (auto &iter : grid[x_val + i - round][y_val + j - round]) {
					dir_vector = node.calculate_dir_vector(iter);
					if ((dir_vector.norm() < distance)
							&& node.is_reachable(iter, dir_vector)) {
						distance = dir_vector.norm();
						parent = iter;
						found = true;
					}
				}
			}
		}
	}
	return found;
}


auto ListOfNodes::radius_find_nearest_neighbours(Node& node,
		std::list<Node> neighbours) ->bool {
	int number_of_rounds = RADIUS / cell_size;
	int x_val = node.coordinates[0] / cell_size;
	int y_val = node.coordinates[1] / cell_size;
	bool found = false;
	Eigen::Vector2d dir_vector;
	for (int round = 1; round < number_of_rounds && !(round > grid.size());
			round++) {
		for (int j = 0; j < 1 + 2 * round; ++j) {
			//check if entry could be out of bounds:
			//bottom side out of bound
			while ((y_val - round + j < 0)) {
				j++;
			}
			//top side out of bound
			while ((y_val - round + j >= grid[x_val].size())) {
				j--;
				break;
			}
			for (int i = 0; i < 1 + 2 * round; ++i) {
				//left side out of bound
				while ((x_val - round + i < 0)) {
					i++;
				}
				//right side out of bound, avoid infinite loops
				while ((x_val - round + i >= grid.size())) {
					i--;
					break;
				}

				//searches grid entry for matches
				for (auto &iter : grid[x_val + i - round][y_val + j - round]) {
					dir_vector = iter.calculate_dir_vector(node);
					if (iter.is_reachable(node, dir_vector)) {
						neighbours.push_back(iter);
						found = true;
					}
				}
			}
		}
	}
	return found;
}

ListOfNodes::~ListOfNodes() {
	// TODO Auto-generated destructor stub
}

