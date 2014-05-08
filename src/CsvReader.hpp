/*
 * CsvReader.hpp
 *
 *  Created on: 26 mars 2014
 *      Author: Yannick
 */

#ifndef CSV_HPP_
#define CSV_HPP_

#include "Person.hpp"
#include "Donor.hpp"
#include "Group.hpp"
#include "LineReader.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <list>
#include <unistd.h>
#include <stdlib.h>
#include <typeinfo>
#include <math.h>

using namespace std;

class CsvReader {
public:
	CsvReader(string iFile);
	void getObjects();
	int testLineContent(string iLineContent);
	int testGroupInMemory(string iName);
	float round(float data);
	virtual ~CsvReader();
private:
	string _file;
	ifstream *_df;
	vector<Group *> _groups;
};

#endif /* CSV_HPP_ */
