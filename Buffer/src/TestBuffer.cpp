#include <iostream>
#include "../includes/Buffer.h"

using namespace std;

int main(int argc, char **argv) {

	Buffer*  buffer;

	buffer = new Buffer("Buffer/includes/test.txt");
	char test;

//	while ((test = buffer->getChar()) != '\0') {
//		cout << test << endl;
//	}

	cout << buffer->getChar() << endl; //a
	cout << buffer->getChar() << endl; //b
	cout << buffer->getChar() << endl; //c
	cout << buffer->getChar() << endl; //d
	cout << buffer->getChar() << endl; //Bufferwechsel -> e
	cout << buffer->getChar() << endl; // f
	try {
		buffer->ungetChar(35);
	} catch (const char* msg) {
		cout << msg << endl;
	}

	cout << buffer->getChar() << endl;

	/*for (int i = 0; i < 10; ++i) {
		cout << i << ". " << buffer->getChar() << endl;
	}*/
}
