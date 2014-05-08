//============================================================================
// Name        : main.cpp
// Author      : Yannick
// Version     :
// Copyright   : Your copyright notice
// Description : Tutorial - Application to manage friends expenses
//============================================================================

#include "Person.hpp"
#include "Group.hpp"
#include "LineReader.hpp"
#include "CsvReader.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <list>
#include <unistd.h>
#include <stdlib.h>
#include "Parser.hpp"

using namespace std;

int main(int argc, char **argv) {

	Parser *parse;
	parse = new Parser(argc, argv);
	parse->parse();

    return 0;
}
