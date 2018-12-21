#include "../includes/Symboltable.h"
#include "../includes/StringTable.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

	Symboltable st;

	cout << "Start" << endl;

	char* str1 = "with";
	char* str2 = "waste";
	//char* str3 = "hello";

	unsigned int key1 = st.insert(str1);
	unsigned int key2 = st.insert(str2);
	//unsigned int key3 = st.insert(str3);

	cout << key1 << endl;
	cout << key2 << endl;


	cout << "sym1: "<< st.lookup(key1)->getInfo()->getName() << endl;
	cout << "sym2: "<< st.lookup(key2)->getInfo()->getName() << endl;
	//cout << "sym3: "<< st.lookup(key3)->getInfo()->getName() << endl;

	bool test = (st.lookup(key1)->getInfo()->getName() == st.lookup(key2)->getInfo()->getName());
	cout << test << endl;


	/*
	 StringTable* stringTable = new StringTable();

	 for (int i = 0; i < 1000; i++) {
	 	 const char* inserted_string = stringTable->insert("test", 4);
	 	 std::cout << i << ": " << inserted_string << std::endl;
	 }

	 delete stringTable;
	 */
	return 0;
}
