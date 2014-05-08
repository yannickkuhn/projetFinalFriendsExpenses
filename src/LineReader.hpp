/*
 * LineReader.hpp
 *
 *  Created on: 20 mars 2014
 *      Author: Yannick
 */

#ifndef COUNTWORD_HPP_
#define COUNTWORD_HPP_

#include <vector>
#include <string>
#include <cstring>

using namespace std;

class LineReader {

public:
	LineReader();
	LineReader(string iText);
    unsigned int count();
    vector<string> split();

private:
    string _text;
};

#endif /* COUNTWORD_HPP_ */
