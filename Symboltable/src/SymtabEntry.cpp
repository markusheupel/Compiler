#include "../includes/SymtabEntry.h"
#include <cstring>

SymtabEntry::SymtabEntry(Information* info) {
	this->info = info;
	this->next = NULL;
}

SymtabEntry::~SymtabEntry() {
}

SymtabEntry* SymtabEntry::getNext() {
	return this->next;
}

void SymtabEntry::setNext(SymtabEntry* next) {
	this->next = next;
}

Information* SymtabEntry::getInfo() {
	return this->info;
}
