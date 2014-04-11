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



class Arguments {
public:
	Arguments(int iargc, char **iargv);
	void AfficherArguments();
private:
	int _argc;
	char **_argv;
};


#endif /* ARGUMENTS_HPP_ */
