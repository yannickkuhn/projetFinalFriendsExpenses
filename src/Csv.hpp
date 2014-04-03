/*
 * Csv.hpp
 *
 *  Created on: 26 mars 2014
 *      Author: ubuntu
 */

#ifndef CSV_HPP_
#define CSV_HPP_

#include "Person.hpp"
#include "Group.hpp"
#include "CountWord.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <list>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

class Csv {
public:
	Csv(string iFile);
	void getObjects();
	virtual ~Csv();
private:
	string _file;
	ifstream *_df;
	vector<Group> _groups;
};

#endif /* CSV_HPP_ */
