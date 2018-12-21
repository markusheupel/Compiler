/*
 * NodeOp.h
 *
 *  Created on: 08.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODEOP_H_
#define PARSER_INCLUDES_NODES_NODEOP_H_

#include "../../../Scanner/includes/Token.h"

class NodeOp: public Node {
private:
	Token* token;
public:
	NodeOp (Token* token) {
		this->token = token;
	}

	~NodeOp() {}

	void accept(ParseTreeVisitor* visitor) {
		visitor->visitNode(this);
	}

	Token* getToken() {
		return this->token;
	}
};

#endif /* PARSER_INCLUDES_NODES_NODEOP_H_ */
