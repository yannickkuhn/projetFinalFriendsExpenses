/*
 * parser.cpp
 *
 *  Created on: 11 avr. 2014
 *      Author: lau
 */

#include "Parser.hpp"

Parser::Parser(int argc, char **argv) :
		_argc(argc), _argv(argv) {
	if(argc > 1){
		cout << argv[argc];
	}
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

	if (_argc == 0) {
		displayLongHelp();
	} else {
		while (_argc <= 6) {
			cout << "Unknown command.\n";
			displayLongHelp();
			readcsvfile();
			//std::string arg1 = _argv[1];
			//if (arg1 == "--help") {
			//					   displayLongHelp();
			//					   }else{
			//							   std::cout<<"Unknown command.\n";}
			//}

			//if(arg == "--file")
			//{
			//readcsvfile();
			//std::cout<<"file.\n";
			//	}else{
			//				 std::cout<<"Unknown command.\n";}
			//}
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

