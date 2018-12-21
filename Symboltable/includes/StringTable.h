#ifndef STRINGTABLE_H_
#define STRINGTABLE_H_

#include "../includes/StringTabNode.h"

class StringTable {
	public:
		StringTable();
		virtual ~StringTable();
		char* insert(char* lexem, unsigned int size);
	private:
		char* freeP;
		unsigned int freeSpace;
		StringTabNode* first;
		StringTabNode* currentNode;
};

#endif /* STRINGTABLE_H_ */
