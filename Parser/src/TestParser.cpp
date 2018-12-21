/*
 * TestParser.cpp
 *
 *  Created on: 08.01.2017
 *      Author: yannick
 */

#include "../includes/Parser.h"
#include "../includes/ParseTree.h"
#include "../includes/ParseTreeVisitor.h"
#include "../includes/ParseTreeVisitorType.h"
#include "../includes/ParseTreeVisitorCode.h"
#include <iostream>

using namespace std;

/**
 * Main-Methode.
 * Startet den kompletten Compiler.
 */
int main(int argc, char **argv) {
	cout << "parsing..." << endl;
	Parser* parser = new Parser(argv[1]);
	ParseTree* tree = parser->parse();

	cout << "type checking..." << endl;
	ParseTreeVisitorType tc;
	tc.typeCheck(tree);

	cout << "generate code..." << endl;
	ParseTreeVisitorCode mc;
	mc.makeCode(tree, argv[2]);
}
