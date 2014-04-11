/*
 * Arguments.hpp
 *
 *  Created on: 11 avr. 2014
 *      Author: lapie
 */

#ifndef ARGUMENTS_HPP_
#define ARGUMENTS_HPP_
#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
using namespace std;
#include <vector>



class Arguments {
public:
	Arguments(int iargc, char **iargv);
	vector<string> AfficherArguments();
	string SwitchArguments(vector<string> iArguments);
private:
	int _argc;
	char **_argv;
	vector<string> _arguments;
};


#endif /* ARGUMENTS_HPP_ */
