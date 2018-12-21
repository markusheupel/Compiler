/*
 * NodeStatementRead.h
 *
 *  Created on: 08.01.2017
 *      Author: yannick
 */

#ifndef PARSER_INCLUDES_NODES_NODESTATEMENTREAD_H_
#define PARSER_INCLUDES_NODES_NODESTATEMENTREAD_H_

class NodeStatementRead: public NodeStatement {
private:
	NodeIdentifier* identifier;
	NodeIndex* index;

public:
	~NodeStatementRead() {
		delete this->identifier;
		delete this->index;
	}

	void addNode(NodeIdentifier* identifier) {
		this->identifier = identifier;
	}

	void addNode(NodeIndex* index) {
		this->index = index;
	}

	void accept(ParseTreeVisitor* visitor) {
		visitor->visitNode(this);
	}

	NodeIdentifier* getIdentifier() {
		return this->identifier;
	}

	NodeIndex* getIndex() {
		return this->index;
	}
};


#endif /* PARSER_INCLUDES_NODES_NODESTATEMENTREAD_H_ */
