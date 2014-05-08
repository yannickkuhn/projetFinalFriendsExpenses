/*
* parser.cpp
*
* Created on: 11 avr. 2014
* Author: lau
*/

#include "Parser.hpp"


Parser::Parser(int argc, char **argv) :
	_argc(argc), _argv(argv) {

}

Parser::~Parser() {
}

int Parser::getArgc() {
	return _argc;
}

char **Parser::getArgv() {
	return _argv;
}

void Parser::setArgv(char **argv) {
	_argv = argv;
}

void Parser::setArgc(int argc) {
	_argc = argc;
}

void Parser::parse() {
	// If no custom argument.
	if (_argc == 1) {
		displayLongHelp();
	}
	else {
		// Contains either "help" or "file".
		if (strcmp(_argv[1], "--help") == 0)
			displayLongHelp();
		else if (strcmp(_argv[1], "--file") == 0)
			readCsvFile();
		else
			displayLongHelp();
	}
}

void Parser::displayLongHelp() {
	cout << "Usage: " << "friends-expenses [--help] [--file filename]\n"
	"--help display the usage.\n"
	"--file filename read the file to render the results.\n";
}

void Parser::readCsvFile() {
	if(_argc == 3 && _argv[2] != (char *)"") {
		string aFilename(_argv[2]);
		string::size_type aIdx;
		aIdx = aFilename.rfind(".");
		if(aIdx != std::string::npos) {
		    string aExt = aFilename.substr(aIdx+1);
		    if(aExt == "csv") {
		    	cout << "Affichage du fichier CSV" << endl;
		    	CsvReader *fileCsv = new CsvReader(_argv[2]);
		    	fileCsv->getObjects();
		    }
		    else
		    	cout << "Error: this file is not in extension .csv" << endl;
		}
		else
			cout << "Error: this file is not in extension .csv" << endl;
	}
	else {
		cout << "Error: no file mentioned" << endl;
	}
}
