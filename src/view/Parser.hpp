/*
* parser.hpp
*
* Created on: 11 avr. 2014
* Author: lau
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <list>
#include <unistd.h>
#include <stdlib.h>
#include "../model/CsvReaderOrWriter.hpp"

// pour pouvoir récupérer ce qu'il y a sur la console on passe : int argc, char **argv

class Parser
{
public:
	Parser(int argc,char **argv);
	virtual ~Parser();

	int getArgc();
	char **getArgv();

	void setArgc(int iArgc);
	void setArgv(char **iArgv);

	int parse(string iChaine = "");
	void displayLongHelp();
	int readWriteCsvFile(int iReadOrWrite, int iNumArgFile, string iChaine = "");

	int testArgsWriter();

private:
	int _argc;
	char **_argv;
	string _argName, _argGroup, _argType, _argExpense, _argPhone;
};

#endif /* PARSER_HPP_ */
