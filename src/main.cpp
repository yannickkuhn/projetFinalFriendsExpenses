//============================================================================
// Name        : main.cpp
// Author      : Yannick
// Version     :
// Copyright   : Your copyright notice
// Description : Tutorial - Application to manage friends expenses
//============================================================================

#include "model/Person.hpp"
#include "model/Group.hpp"
#include "controller/LineReader.hpp"
#include "model/CsvReader.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <list>
#include <unistd.h>
#include <stdlib.h>
#include "view/Parser.hpp"

using namespace std;

int main(int argc, char **argv) {

	Parser *aParse;
	aParse = new Parser(argc, argv);
	aParse->parse();

    return 0;
}
