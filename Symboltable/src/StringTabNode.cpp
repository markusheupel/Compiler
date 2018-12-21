#include "../includes/StringTabNode.h"

char* StringTabNode::getVector() {
	return vector;
}

void StringTabNode::setNext(StringTabNode* next) {
	this->next = next;
}

StringTabNode* StringTabNode::getNext() {
	return this->next;
}
