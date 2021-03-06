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

//auto ListOfNodes::add_node(Node& node)->void {
//	std::cout << "Entering add_node..." << std::endl;
//
//	int x_val = (node.get_coordinates())[0] / cell_size;
//	int y_val = (node.get_coordinates())[1] / cell_size;
//
//	if (!(x_val < 0 || y_val < 0 || x_val > grid.size()
//			|| y_val > grid[0].size())) {
//		grid[x_val][y_val].push_back(node);
//	}
//}

//auto ListOfNodes::find_nearest_neighbour(Node& node)->bool {
//	//deprecated
//
//	std::cout << "Entering find_nearest_neighbour..." << std::endl;
//
//	//slow if only few nodes are inserted! (O(k³) worst case)
//	//if many nodes are there: O(9* (n/k²)), k length of axis of grid
//	int loops = 0;
//	bool found = false;
//	int x_val = (node.get_coordinates())[0] / cell_size;
//	int y_val = (node.get_coordinates())[1] / cell_size;
//	double tmp_dist = 0;
//	double min_distance = RANGE * 2;
//	Eigen::Vector2d dir;
//	for (int round = 0; !found && !(round > grid.size()); round++) {
//		/*
//		 * searches a square with size 1+2*round (3*3,5*5,7*7,9*9...)
//		 * and with node in center for possible neighbours
//		 * checks for reacha} //namespace rrt
//		 * bility and nearest distance
//		 */
//		for (int j = 0; j < 1 + 2 * round; ++j) {
//			//check if entry could be out of bounds:
//			//bottom side out of bound
//			while ((y_val - round + j < 0)) {
//				j++;
//			}
//			//top side out of bound
//			if ((y_val - round + j >= grid[0].size())) {
//				break;
//			}
//			for (int i = 0; i < 1 + 2 * round; ++i) {
//				//left side out of bound
//				while ((x_val - round + i < 0)
//						|| ((j != 0 && j < 2 * round)
//								&& (i != 0 && i < 2 * round))) {
//					i++;
//				}
//				//right side out of bound, avoid infinite loops
//				if ((x_val - round + i >= grid.size())) {
//					break;
//				}
//
//				loops++;
//				/*
//				 std::cout << "x_val: " << x_val << std::endl;
//				std::cout << "y_val: " << y_val << std::endl;
//				std::cout << "i: " << i << std::endl;
//				std::cout << "j: " << j << std::endl;
//				std::cout << "round: " << round << std::endl;
//				std::cout << "__________________" << std::endl;
//				 */
//				//searches grid en try for matches
//				for (auto &iter : grid[x_val + i - round][y_val + j - round]) {
//					if (!(iter.equals(node))) {
//						node.calculate_dir_vector(iter, dir);
//						tmp_dist = dir.norm();
//						if (tmp_dist < min_distance
//								&& node.is_reachable(iter, dir)) {
//
//							min_distance = tmp_dist;
//							node.set_parent(iter);
//							node.set_dir_vector();
//							found = true;
//
//						}
//					}
//				}
//			}
//		}
//	}
//	std::cout << "Loops: " << loops << std::endl;
//
//	return found;
//}


//auto ListOfNodes:: (Node& node,
//		std::list<Node>& neighbours, std::vector<Node>&rewire_nodes) ->bool {
//	std::cout << "Entering radius find_nearest_neighbour..." << std::endl;
//	//highly deprecated
//	/*
//	 * Find nearest reachable Neighbours
//	 * which has better costs through node
//	 */
//	//if radius bigger then cellsize, we have to search at least 3 times (5x5)
////	std::cout << "Entering radius_find_nearest_neighbour..." << std::endl;
//
//	bool found = false;
//	double cost_new;
//	double cost_old;
//	Eigen::Vector2d dir;
//	for (auto &iter : easy_list) {
//		if (!(iter.equals(node))) {
//			//Bessere Datenstruktur für schnellere Suche wäre cool
//			iter.calculate_dir_vector(node, dir);
//			dist = dir.norm();
//			if (dist < RADIUS) {
//				iter.calculate_yaw_cost(node,dir, new_yaw, new_cost);
//				cost_old = iter.get_cost();
//				if (new_cost < cost_old && iter.not_to_near(node)) {
//					iter.set_parent(node);
//					iter.set_dir_vector();
//					iter.set_yaw(new_yaw);
//					iter.set_cost(new_cost);
//					found = true;
//				}
//			}
//
//			}
//		}
//	return found;
//}

//auto ListOfNodes::find_nearest_parent(Node& node)->bool {
//	//deprecated
//
//	std::cout << "Entering find_nearest_parent..." << std::endl;
//	int loop = 0;
//	//slow if only few nodes are inserted! (O(k³) worst case)
//	//if many nodes are there: O(9* (n/k²)), k length of axis of grid
//	bool found = false;
//	int x_val = (node.get_coordinates())[0] / cell_size;
//	int y_val = (node.get_coordinates())[1] / cell_size;
//	int number_of_rounds = (RADIUS / cell_size + 0.9999);
//	if (number_of_rounds == 0) {
//		std::cout << "find_nearest_parent: numerb_of_rounds=0" << std::endl;
//	}
//	double tmp_dist = 0;
//	double min_distance = RANGE * 2;
//	Eigen::Vector2d dir;
//	for (int round = 0;
//			!found && (round < grid.size()) && round < number_of_rounds;
//			round++) {
//		/*
//		 * searches a square with size 1+2*round (1*1,3*3,5*5,7*7,9*9...)
//		 * and with node in center for possible neighbours
//		 * checks for reachability and nearest distance
//		 */
//		for (int j = 0; j < 1 + 2 * round; ++j) {
//			//check if entry could be out of bounds:
//			//bottom side out of bound
//			while ((y_val - round + j < 0)) {
//				j++;
//			}
//			//top side out of bound
//			if ((y_val - round + j >= grid[0].size())) {
//				break;
//			}
//			for (int i = 0; i < 1 + 2 * round; ++i) {
//				//left side out of bound
//				while ((x_val - round + i < 0)
//						|| ((j != 0 && j < 2 * round)
//								&& (i != 0 && i < 2 * round))) {
//					i++;
//				}
//				//right side out of bound, avoid infinite loops
//				if ((x_val - round + i >= grid.size())) {
//					break;
//				}
//				/*
//				 std::cout << "x_val: " << x_val << std::endl;
//				 std::cout << "y_val: " << y_val << std::endl;
//				 std::cout << "i: " << i << std::endl;
//				 std::cout << "j: " << j << std::endl;
//				 std::cout << "round: " << round << std::endl;
//				 std::cout << "__________________" << std::endl;
//				 */
//				//searches grid en try for matches
//				loop++;
//				for (auto &iter : grid[x_val + i - round][y_val + j - round]) {
//						if (!(iter.equals(node))) {
//						node.calculate_dir_vector(iter, dir);
//						tmp_dist = dir.norm();
//						if (tmp_dist < min_distance) {
//							if (node.is_reachable(iter, dir)) {
//								if (node.not_to_near(iter)) {
//									min_distance = tmp_dist;
//									node.set_parent(iter);
//									node.set_dir_vector();
//
//									found = true;
//								}
//
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	std::cout << "Durchläufe: " << loop << std::endl;
//
//	return found;
//}
//auto ListOfNodes::rewire(Node& node)->void {
//	//deprecated
//
//	std::cout << "Entering rewiring..." << std::endl;
//
//	std::list<Node> possible_childs;
//	this->radius_find_nearest_neighbours(node, possible_childs);
//	for (auto &iter : possible_childs) {
//			if (!(iter.equals(node))) {
//			Node new_node;
//			new_node.set_coordinates(iter.get_coordinates_fast());
//			new_node.set_validation(iter.get_validation());
//			new_node.set_parent(node);
//			new_node.set_dir_vector();
//			new_node.calculate_yaw_and_cost();
//			if (new_node.check()) {
//				this->add_node(new_node);
//				this->rewire(new_node);
//			}
//		}
//	}
//	std::cout << "End rewiring..." << std::endl;
//
//
//}

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
	bool projected = false;
	bool found = false;
	for (auto &iter : easy_list) {
		if (!(iter.equals(node))) {
			node.calculate_dir_vector(iter, dir);
			if (dir[1] < min_distance && dir[0] < min_distance) {
				tmp_dist = dir.norm();
				if (tmp_dist < min_distance) {
					min_distance = tmp_dist;
					node.set_parent(iter);
					found = true;
				}
			}
		}
	}
	if (found) {
		node.set_dir_vector(dir);
	}
	return found;
}
bool ListOfNodes::find_nearest_parent_easy(Node& node) {
	//TODO not to near for every node....
	double new_cost = 0;
	double min_cost = RANGE * RANGE;
	double new_yaw;
	Vector2d dir;
	bool found = false;
	for (auto &iter : easy_list) {
		if (!(iter.equals(node))) {
			node.calculate_dir_vector(iter, dir);
			if (dir.norm < min_cost && node.not_to_near(iter)) {
				node.calculate_yaw_cost(iter, dir, new_yaw, new_cost);
				if (new_cost < min_cost) {
					min_cost = new_cost;
					node.set_parent(iter);
					node.set_yaw(new_yaw);
					node.set_cost(new_cost + iter.get_cost());
					found = true;
				}
			}
		}
	}
	if (found) {
		node.set_dir_vector(dir);
	}
	return found;
}

bool ListOfNodes::rewire_easy(Node& node) {
	Vector2d dir;
	bool found = false;
	double old_cost;
	double new_yaw;
	double new_cost;
	Node* best_node_ptr = nullptr;
	Node* actual_node_ptr = &node;
	double cost_reduction = 0;
	//laufzeit n*logn
	do {
		found = false;
		for (auto &iter : easy_list) {
			if (!(iter.equals(*actual_node_ptr))) {
				iter.calculate_dir_vector(*actual_node_ptr, dir);
				//Rewire in Quadrat um Laufzeit zu sparen
				if (dir[1] < RADIUS && dir[0] < RADIUS) {
					iter.calculate_yaw_cost(*actual_node_ptr, dir, new_yaw,
								new_cost);
					double cost_sum = new_cost + actual_node_ptr->get_cost();
					old_cost = iter.get_cost();
					if (cost_sum < old_cost
								&& iter.not_to_near(*actual_node_ptr)) {
							easy_list.emplace_back(iter.get_coordinates(),
									new_yaw,
								*actual_node_ptr, dir, Val::valid, cost_sum);
							found = true;
							if (cost_reduction < old_cost - new_cost) {
								cost_reduction = old_cost - new_cost;
								best_node_ptr = &easy_list.back();
							}
						}
					}

			}
		}
		if (best_node_ptr != nullptr) {
			cost_reduction = 0;
			actual_node_ptr = best_node_ptr;
			best_node_ptr = nullptr;

		}
	} while (found);

	return found;
}
bool ListOfNodes::rewire_euklid(Node& node) {
	Vector2d dir;
	bool found = false;
	double cost;
	double cost_new;
	double norm;
	for (auto &iter : easy_list) {
		if (!(iter.equals(node))) {
			//Bessere Datenstruktur für schnellere Suche wäre cool
			iter.calculate_dir_vector(node, dir);
			if (dir[1] < RADIUS && dir[0] < RADIUS) {
				norm = dir.norm();
				if (norm < RADIUS) {
					cost = iter.get_cost();
					cost_new = norm + node.get_cost();
					if (cost_new < cost) {
						iter.set_parent(node);
						iter.set_dir_vector();
						iter.set_cost(cost_new);
						found = true;
					}
				}
			}

		}
	}
	return found;
}
