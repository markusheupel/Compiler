#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_

#include "SymtabEntry.h"
#include "StringTable.h"

class Symboltable {
	public:
		Symboltable();
		virtual ~Symboltable();
		SymtabEntry* insert(char* lexem);
		Information* lookup(unsigned int key);

	private:
		static const unsigned TABLE_SIZE = 1024;
		StringTable* stringTable;
		SymtabEntry** table;
		unsigned int hash(const char* s, unsigned int seed = 0);
		void initSymbols();
		int stringLength(char* lexem);
};

#endif /* SYMBOLTABLE_H_ */
