#include "../includes/Symboltable.h"
#include <cstring>

using namespace std;

Symboltable::Symboltable() {
	stringTable = new StringTable();
	table = new SymtabEntry*[TABLE_SIZE];
	for (unsigned int i = 0; i < TABLE_SIZE; i++) {
		table[i] = NULL;
	}
	initSymbols();
}

Symboltable::~Symboltable() {
	delete stringTable;
	for (unsigned int i = 0; i < TABLE_SIZE; i++) {
		if (table[i] != NULL) {
			SymtabEntry *prevEntry = NULL;
			SymtabEntry *entry = table[i];
			while (entry != NULL) {
				prevEntry = entry;
				entry = entry->getNext();
				delete prevEntry;
			}
		}
	}
	delete[] table;
}

SymtabEntry* Symboltable::insert(char* lexem) {
	unsigned int hashValue = hash(lexem);
	SymtabEntry* tmpSymtabEntry = table[hashValue % TABLE_SIZE];

	if (tmpSymtabEntry == NULL) { //noch keinen Eintrag in der HashTable gefunden
		char* p = stringTable->insert(lexem, stringLength(lexem));
		table[hashValue % TABLE_SIZE] = new SymtabEntry(new Information(p, hashValue));
	} else {
		while (tmpSymtabEntry != NULL) {
			if (tmpSymtabEntry->getInfo()->compareLex(lexem)) {
				return tmpSymtabEntry;
				//return table[hashValue % TABLE_SIZE]; /* pointer zurück geben */
			}
			tmpSymtabEntry = tmpSymtabEntry->getNext();
		}

		tmpSymtabEntry = table[hashValue % TABLE_SIZE];
		while (tmpSymtabEntry->getNext() != NULL) {
			tmpSymtabEntry = tmpSymtabEntry->getNext();
		}

		char* p = stringTable->insert(lexem, strlen(lexem));
		SymtabEntry* newEntry = new SymtabEntry(new Information(p, hashValue));
		tmpSymtabEntry->setNext(newEntry);
		return newEntry;
	}

	return table[hashValue % TABLE_SIZE]; /* pointer zurück geben */
}

Information* Symboltable::lookup(unsigned int key) {
	SymtabEntry* element = table[key % TABLE_SIZE];
	while (element != NULL) {
		if (element->getInfo()->getKey() == key) {
			return element->getInfo();
		}
		element = element->getNext();
	}
	return element->getInfo();
}

unsigned int Symboltable::hash(const char* s, unsigned int seed) {
	unsigned int hash = seed;
	while (*s) {
		hash = hash * 101 + *s++;
	}
	return hash;
}

int Symboltable::stringLength(char* lexem) {
    int length = 0;
    const unsigned char *tmp = (const unsigned char *)lexem;
    while (*tmp != '\0') {
        tmp++;
        length++;
    }
    return length;
}

void Symboltable::initSymbols() {
	insert("if");
	insert("IF");
	insert("while");
	insert("WHILE");
}
