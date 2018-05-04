/*
 * ListOfNodes.cpp
 *
 *  Created on: May 2, 2018
 *      Author: besahre
 */

#include "ListOfNodes.h"
#include <iostream>
#include "const.h"

using namespace std;

ListOfNodes::ListOfNodes(int size, double c) {
	cell_size=c;
	grid.resize(size);

	for (int i = 0; i < size; i++) {
		grid[i].resize(size);
	}

}

auto ListOfNodes::add_node(Node& node)->void {
	std::cout << "Entering add_node..." << std::endl;

	int x_val = (node.get_coordinates())[0] / cell_size;
	int y_val = (node.get_coordinates())[1] / cell_size;

	if (!(x_val < 0 || y_val < 0 || x_val > grid.size()
			|| y_val > grid[0].size())) {
		grid[x_val][y_val].push_back(node);
	}
}

auto ListOfNodes::find_nearest_neighbour(Node& node)->bool {
	std::cout << "Entering find_nearest_neighbour..." << std::endl;

	//slow if only few nodes are inserted! (O(k³) worst case)
	//if many nodes are there: O(9* (n/k²)), k length of axis of grid
	int loops = 0;
	bool found = false;
	int x_val = (node.get_coordinates())[0] / cell_size;
	int y_val = (node.get_coordinates())[1] / cell_size;
	double tmp_dist = 0;
	double min_distance = RANGE * 2;
	Eigen::Vector2d dir;
	for (int round = 0; !found && !(round > grid.size()); round++) {
		/*
		 * searches a square with size 1+2*round (3*3,5*5,7*7,9*9...)
		 * and with node in center for possible neighbours
		 * checks for reacha} //namespace rrt
		 * bility and nearest distance
		 */
		for (int j = 0; j < 1 + 2 * round; ++j) {
			//check if entry could be out of bounds:
			//bottom side out of bound
			while ((y_val - round + j < 0)) {
				j++;
			}
			//top side out of bound
			if ((y_val - round + j >= grid[0].size())) {
				break;
			}
			for (int i = 0; i < 1 + 2 * round; ++i) {
				//left side out of bound
				while ((x_val - round + i < 0)
						|| ((j != 0 && j < 2 * round)
								&& (i != 0 && i < 2 * round))) {
					i++;
				}
				//right side out of bound, avoid infinite loops
				if ((x_val - round + i >= grid.size())) {
					break;
				}

				loops++;
				/*
				 std::cout << "x_val: " << x_val << std::endl;
				std::cout << "y_val: " << y_val << std::endl;
				std::cout << "i: " << i << std::endl;
				std::cout << "j: " << j << std::endl;
				std::cout << "round: " << round << std::endl;
				std::cout << "__________________" << std::endl;
				 */
				//searches grid en try for matches
				for (auto &iter : grid[x_val + i - round][y_val + j - round]) {
					if (!(iter.equals(node))) {
						node.calculate_dir_vector(iter, dir);
						tmp_dist = dir.norm();
						if (tmp_dist < min_distance
								&& node.is_reachable(iter, dir)) {

							min_distance = tmp_dist;
							node.set_parent(iter);
							node.set_dir_vector();
							found = true;

						}
					}
				}
			}
		}
	}
	std::cout << "Loops: " << loops << std::endl;

	return found;
}


auto ListOfNodes::radius_find_nearest_neighbours(Node& node,
		std::list<Node>& neighbours) ->bool {
	std::cout << "Entering radius find_nearest_neighbour..." << std::endl;
	/*
	 * Find nearest reachable Neighbours
	 * which has better costs through node
	 */
	//if radius bigger then cellsize, we have to search at least 3 times (5x5)
//	std::cout << "Entering radius_find_nearest_neighbour..." << std::endl;

	int number_of_rounds = (RADIUS / cell_size + 0.9999);
	int x_val = (node.get_coordinates())[0] / cell_size;
	int y_val = (node.get_coordinates())[1] / cell_size;
	bool found = false;
	double cost_new;
	double cost_old;
	Eigen::Vector2d dir;
	for (int round = 0; round < number_of_rounds && round < grid.size();
			round++) {
		for (int j = 0; j < 1 + 2 * round; ++j) {

			//check if entry could be out of bounds:
			//bottom side out of bound
			while ((y_val - round + j < 0)) {
				j++;
			}
			//top side out of bound
			while ((y_val - round + j >= grid[x_val].size())) {
				break;
			}
			for (int i = 0; i < 1 + 2 * round; ++i) {
				//left side out of bound&& node.not_to_near(iter)
				//jump over already searched cells
				while ((x_val - round + i < 0)
						|| ((j != 0 && j < 2 * round)
								&& (i != 0 && i < 2 * round))) {
					i++;
				}
				//right side out of bound, avoid infinite loops
				while ((x_val - round + i >= grid.size())) {
					break;
				}

				//searches grid entry for matches
				for (auto &iter : grid[x_val + i - round][y_val + j - round]) {
					if (!(iter.equals(node))) {
						iter.calculate_dir_vector(node, dir);
						cost_new = node.get_cost() + dir.norm();
						cost_old = iter.get_cost();
						if (cost_new < cost_old && iter.is_reachable(node, dir)
								&& iter.not_to_near(node)) {
							neighbours.push_back(iter);
							found = true;
						}
					}
				}
			}
		}
	}
	return found;
}

auto ListOfNodes::find_nearest_parent(Node& node)->bool {
	std::cout << "Entering find_nearest_parent..." << std::endl;
	int loop = 0;
	//slow if only few nodes are inserted! (O(k³) worst case)
	//if many nodes are there: O(9* (n/k²)), k length of axis of grid
	bool found = false;
	int x_val = (node.get_coordinates())[0] / cell_size;
	int y_val = (node.get_coordinates())[1] / cell_size;
	int number_of_rounds = (RADIUS / cell_size + 0.9999);
	if (number_of_rounds == 0) {
		std::cout << "find_nearest_parent: numerb_of_rounds=0" << std::endl;
	}
	double tmp_dist = 0;
	double min_distance = RANGE * 2;
	Eigen::Vector2d dir;
	for (int round = 0;
			!found && (round < grid.size()) && round < number_of_rounds;
			round++) {
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
			if ((y_val - round + j >= grid[0].size())) {
				break;
			}
			for (int i = 0; i < 1 + 2 * round; ++i) {
				//left side out of bound
				while ((x_val - round + i < 0)
						|| ((j != 0 && j < 2 * round)
								&& (i != 0 && i < 2 * round))) {
					i++;
				}
				//right side out of bound, avoid infinite loops
				if ((x_val - round + i >= grid.size())) {
					break;
				}
				/*
				 std::cout << "x_val: " << x_val << std::endl;
				 std::cout << "y_val: " << y_val << std::endl;
				 std::cout << "i: " << i << std::endl;
				 std::cout << "j: " << j << std::endl;
				 std::cout << "round: " << round << std::endl;
				 std::cout << "__________________" << std::endl;
				 */
				//searches grid en try for matches
				loop++;
				for (auto &iter : grid[x_val + i - round][y_val + j - round]) {
						if (!(iter.equals(node))) {
						node.calculate_dir_vector(iter, dir);
						tmp_dist = dir.norm();
						if (tmp_dist < min_distance) {
							if (node.is_reachable(iter, dir)) {
								if (node.not_to_near(iter)) {
									min_distance = tmp_dist;
									node.set_parent(iter);
									node.set_dir_vector();

									found = true;
									tmp_dist = dir.norm();
									if (tmp_dist < min_distance) {
										if (node.is_reachable(iter, dir)) {
											if (node.not_to_near(iter)) {
												min_distance = tmp_dist;
												node.set_parent(iter);
												node.set_dir_vector();

												found = true;
											}

										}
									}
								}

							}
						}
					}
				}
			}
		}
	}
	std::cout << "Durchläufe: " << loop << std::endl;

	return found;
}
auto ListOfNodes::rewire(Node& node)->void {
	std::cout << "Entering rewiring..." << std::endl;

	std::list<Node> possible_childs;
	this->radius_find_nearest_neighbours(node, possible_childs);
	for (auto &iter : possible_childs) {
			if (!(iter.equals(node))) {
			Node new_node;
			new_node.set_coordinates(iter.get_coordinates_fast());
			new_node.set_validation(iter.get_validation());
			new_node.set_parent(node);
			new_node.set_dir_vector();
			new_node.calculate_yaw();
			new_node.calculate_cost();
			if (new_node.check()) {
				this->add_node(new_node);
				this->rewire(new_node);
			}
		}
	}
	std::cout << "End rewiring..." << std::endl;
 

}

ListOfNodes::~ListOfNodes() {
	// TODO Auto-generated destructor stub
}

ListOfNodes::ListOfNodes() {

}

void ListOfNodes::add_node_easy(Node& node) {
	easy_list.push_back(node);
}

bool ListOfNodes::find_nearest_neighbour_easy(Node& node) {
	double tmp_dist = 0;
	double min_distance = 2 * RANGE;
	Vector2d dir;
	bool found = false;
	for (auto &iter : easy_list) {
		if (!(iter.equals(node))) {
			node.calculate_dir_vector(iter, dir);
			tmp_dist = dir.norm();
			if (tmp_dist < min_distance) {
				if (node.is_reachable(iter, dir)) {
					if (node.not_to_near(iter)) {
						min_distance = tmp_dist;
						node.set_parent(iter);
						node.set_dir_vector();

						found = true;
					}

				}
			}
		}
	}
	return found;
}

bool ListOfNodes::radius_find_nearest_neighbours_easy(Node& node,
		std::list<Node>& neighbours) {
	Vector2d dir;
	bool found = false;
	double cost_new;
	double cost_old;
	for (auto &iter : easy_list) {
		if (!(iter.equals(node))) {
			iter.calculate_dir_vector(node, dir);
			cost_new = node.get_cost() + dir.norm();
			cost_old = iter.get_cost();
			if (cost_new < cost_old && iter.is_reachable(node, dir)
					&& iter.not_to_near(node)) {
				neighbours.push_back(iter);
				found = true;
			}
		}
	}
	return found;
}

void ListOfNodes::rewire_easy(Node& node) {
	std::list<Node> possible_childs;
	this->radius_find_nearest_neighbours_easy(node, possible_childs);
	for (auto &iter : possible_childs) {
		if (!(iter.equals(node))) {

			Node new_node;
			new_node.set_coordinates(iter.get_coordinates_fast());
			new_node.set_validation(iter.get_validation());
			new_node.set_parent(node);
			new_node.set_dir_vector();
			new_node.calculate_yaw();
			new_node.calculate_cost();
			if (new_node.check()) {
				this->add_node(new_node);
				this->rewire_easy(new_node);
			}
		}
	}
	std::cout << "End rewiring..." << std::endl;
}
