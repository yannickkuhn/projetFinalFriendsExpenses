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

int Parser::parse(string iChaine) {
	// If no custom argument.
	if (_argc == 1) {
		displayLongHelp();
	}
	else {
		// Contains either "help" or "file".
		if (strcmp(_argv[1], "--help") == 0) {
			displayLongHelp();
			return 0;
		}
		else if (strcmp(_argv[1], "--file") == 0) {
			return readCsvFile(iChaine);
		}
		else {
			displayLongHelp();
			return 0;
		}
	}
	return 0;
}

void Parser::displayLongHelp() {
	cout << "Usage: " << "friends-expenses [--help] [--file filename]\n"
	"--help display the usage.\n"
	"--file filename read the file to render the results.\n";
}

int Parser::readCsvFile(string iChaine) {
	if(_argc == 3 && _argv[2] != (char *)"") {
		string aFilename(_argv[2]);
		string::size_type aIdx;
		aIdx = aFilename.rfind(".");
		if(aIdx != std::string::npos) {
		    string aExt = aFilename.substr(aIdx+1);
		    if(aExt == "csv") {
		    	if(iChaine != "test") {
					cout << "Affichage du fichier CSV" << endl;
					CsvReader *fileCsv = new CsvReader(_argv[2]);
					fileCsv->getObjects();
		    	}
		    	return 1;
		    }
		    else {
		    	cout << "Error: this file is not in extension .csv" << endl;
		    	return -1;
		    }
		}
		else {
			cout << "Error: this file is not in extension .csv" << endl;
			return -1;
		}
	}
	else {
		cout << "Error: no file mentioned" << endl;
		return -2;
	}
}
