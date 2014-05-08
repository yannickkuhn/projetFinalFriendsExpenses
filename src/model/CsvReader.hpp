/*
 * CsvReader.hpp
 *
 *  Created on: 26 mars 2014
 *      Author: Yannick
 */

#ifndef CSV_HPP_
#define CSV_HPP_

#include "../model/Person.hpp"
#include "../model/Donor.hpp"
#include "../model/Group.hpp"
#include "../controller/LineReader.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <list>
#include <unistd.h>
#include <stdlib.h>
#include <typeinfo>
#include <iomanip>
#include <cmath>

#define color(param) "\033[" << param << "m"
/*30, 31, 32, 33, 34, 35, 36, 37 couleur des caractères
  noir, rouge, vert, jaune, bleu, magenta, cyan et blanc */

using namespace std;

class CsvReader {
public:
	CsvReader(string iFile);
	void getObjects();
	int testLineContent(string iLineContent);
	int testGroupInMemory(string iName);
	void printColorValues(string iText, float iValue);
	float round(float iData);
	virtual ~CsvReader();
private:
	string _file;
	ifstream *_df;
	vector<Group *> _groups;
};

#endif /* CSV_HPP_ */
