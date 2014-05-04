/*
 * parser.hpp
 *
 *  Created on: 11 avr. 2014
 *      Author: lau
 */

#ifndef PARSER_HPP_
#define PARSER_HPP_
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unistd.h>
#include <stdlib.h>
// pour pouvoir récupérer ce qu'il y a sur la console on passe : int argc, char **argv

class Parser
{
public:
	Parser(int argc,char **argv);
	virtual ~Parser();

	int getArgc();
	char **getArgv();

	void setArgc(int argc);
	void setArgv(char **argv);

	void parse();
	void displayLongHelp();
	void readcsvfile();

private:
		int _argc;
		char **_argv;

};

#endif /* PARSER_HPP_ */
