/*
 * Main.cpp
 *
 *  Created on: 19.02.2018
 *      Author: Arbeit
 */
#include <Calculator.h>
#include <Car.h>
#include <Node.h>
#include <iostream>
using namespace std;


int main(int argc, char* argv[]){

	int iterations=1000;
	Car car = new Car();
	car.set_position();
	car.set_orientation();
	Node startnode= new Node(car.x_coor, car.y_coor, car.ori_x, car.ori_y);
	for (int i = 0; i < iterations; ++i) {

	}
	return 0;
}


