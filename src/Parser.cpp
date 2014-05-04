/*
 * parser.cpp
 *
 *  Created on: 11 avr. 2014
 *      Author: lau
 */

#include "Parser.hpp"
#include <string.h>
Parser::Parser(int argc, char **argv) :
		_argc(argc), _argv(argv) {

}

Parser::~Parser() {
	// TODO Auto-generated destructor stub
}

int Parser::getArgc() {
	return _argc;
}

char **Parser::getArgv() {
	return _argv;
}

void Parser::setArgv(char **argv) {
	**_argv = **argv;
}

void Parser::setArgc(int argc) {
	_argc = argc;
}

void Parser::parse() {
	// If no custom argument.
	if (_argc == 1) {
		displayLongHelp();
	} else {
		// Contains either "help" or "file".
		if(strcmp(_argv[1],"help") == 0){
			displayLongHelp();
		}else{
			cout << "file" <<endl;
		}
	}
}

void Parser::displayLongHelp() {
	cout << "Usage: " << "friends-expenses [--help] [--file filename]\n"
			"--help display the usage.\n"
			"--file filename read the file to render the results.\n";
}

void Parser::readcsvfile() {
	cout << "readcsvfile\n";

	/*if (_argc!=6 and _argv)
	 {
	 std::cout << "Invalid arguments..." << endl;
	 return 1;
	 }
	 {
	 cout<<"Error::no file mentioned"<<endl;
	 }*/
}

