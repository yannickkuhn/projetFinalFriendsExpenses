//============================================================================
// Name        : main.cpp
// Author      : yannick kuhn
// Version     :
// Copyright   : Your copyright notice
// Description : Tutorial - Application to manage friends expenses
//============================================================================

#include "Person.hpp"
#include "Group.hpp"
#include "CountWord.hpp"
#include "Csv.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <list>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv) {
	Csv *fileCsv = new Csv("src/fichier.csv");

	fileCsv->getObjects();
    return 0;
}
