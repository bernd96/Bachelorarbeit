/*
 * NodeError.h
 *
 *  Created on: 23.03.2018
 *      Author: name-not-found
 */
#include <vector>
#include <string>
#ifndef SRC_NODEERROR_H_
#define SRC_NODEERROR_H_

class NodeError {
	std::vector<std::string> msg;
	int err_code;

public:
	enum class Err{ORIENTATION,DIR_VECTOR, PARENT};
	NodeError(const Err err):err_code(static_cast<int>(err)){
		msg.push_back("Node.orientation is null!");
		msg.push_back("Direction vector is null!");
		msg.push_back("Node has no parent!");
	}
	const std::string&what(){
		return msg.at(err_code);
	}
};

#endif /* SRC_NODEERROR_H_ */
