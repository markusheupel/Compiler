#include "../includes/StringTable.h"
#include <cstring>
#include <cstdlib>

StringTable::StringTable() {
	this->first = (StringTabNode*) malloc(sizeof(StringTabNode));
	this->currentNode = first;
	this->freeSpace = MEM;
	this->freeP = first->getVector();
}

StringTable::~StringTable() {
	currentNode = this->first;
	StringTabNode* tmp;
	while (currentNode != NULL) {
		tmp = currentNode->getNext();
		free(currentNode);
		currentNode = tmp;
	}
}

char* StringTable::insert(char* lexem, unsigned int size) {
	char* tmp = this->freeP;
	if (size < this->freeSpace) {
		memcpy(this->freeP, lexem, size + 1);
		this->freeP[size] = '\0';
		this->freeP += size + 1;
		this->freeSpace -= size + 1;
	} else {
		StringTabNode* newStringTabNode = (StringTabNode*) malloc(sizeof(StringTabNode));
		this->freeSpace = MEM;
		this->currentNode->setNext(newStringTabNode);
		this->currentNode = newStringTabNode;
		this->freeP = newStringTabNode->getVector();
		return insert(lexem, size);
	}

	return tmp;
}
