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

void Parser::setArgv(char **iArgv) {
	_argv = iArgv;
}

void Parser::setArgc(int iArgc) {
	_argc = iArgc;
}

int Parser::testArgsWriter() {
	int aCptArgs = 0;
	int aErrorCode = 1;
	for(int i=0; i < _argc; i++) {
		//cout << "on parcours ... " << _argv[i] << endl;
		if(strcmp(_argv[i],(char *)"--name") == 0 || strcmp(_argv[i],(char *)"--phone") == 0 || strcmp(_argv[i],(char *)"--expense") == 0 || strcmp(_argv[i],(char *)"--group") == 0)
			aCptArgs++;
	}
	if(aCptArgs == 4) {
		// on teste les arguments qui suivent
		for(int i=0; i < _argc; i++) {
			if(strcmp(_argv[i],(char *)"--name") == 0 || strcmp(_argv[i],(char *)"--group") == 0 || strcmp(_argv[i],(char *)"--phone") == 0 || strcmp(_argv[i],(char *)"--expense") == 0 || strcmp(_argv[i],(char *)"--type") == 0) {
				// il ne faut ni que les deux premiers caractères qui suivent soient "--"
				if(i >= _argc || (_argv[i+1][0] + _argv[i+1][1] == 90) || string(_argv[i+1]).length() < 1) {
					cout << "Error: " << _argv[i] << " must be completed " << endl;
					aErrorCode = -4;
				}
			}
			if(strcmp(_argv[i],(char *)"--phone") == 0 && atoi(_argv[i+1]) <= 0) {
				cout << "Error: " << _argv[i] << " must be a integer (actual : " << atoi(_argv[i+1]) << ")"<< endl;
				aErrorCode = -5;
			}
			if(strcmp(_argv[i],(char *)"--expense") == 0 && atof(_argv[i+1]) <= 0) {
				cout << "Error: " << _argv[i] << " must be a integer or a float " << endl;
				aErrorCode = -5;
			}
			if(strcmp(_argv[i],(char *)"--type") == 0 && !(strcmp(_argv[i+1],(char *)"Person") == 0 || strcmp(_argv[i+1],(char *)"Donor") == 0)) {
				cout << "Error: " << _argv[i] << " must be a Person or a Donor"<< endl;
				aErrorCode = -6;
			}
			if(aErrorCode == 1) {
				if(strcmp(_argv[i],(char *)"--name") == 0)
					_argName = _argv[i+1];
				if(strcmp(_argv[i],(char *)"--group") == 0)
					_argGroup = _argv[i+1];
				if(strcmp(_argv[i],(char *)"--phone") == 0)
					_argPhone = _argv[i+1];
				if(strcmp(_argv[i],(char *)"--expense") == 0)
					_argExpense = _argv[i+1];
				if(strcmp(_argv[i],(char *)"--type") == 0)
					_argType = _argv[i+1];
			}
		}
		return aErrorCode;
	}
	else if(aCptArgs == 0) {
		cout << "ok, on peut directement lire" << endl;
		return aCptArgs;
	}
	else {
		cout << "Error: options --name, --phone, --expense, --type and --group must be strictly used together" << endl;
		return -3;
	}
}

int Parser::parse(string iChaine) {
	// If no custom argument.
	if (_argc == 1) {
		displayLongHelp();
	}
	else {
		// Contains either "help" or "file".
		for(int i=0; i < _argc; i++) {
			if (strcmp(_argv[i], "--help") == 0) {
				displayLongHelp();
				return 0;
			}
		}
		// si on ne veut pas afficher d'aide ... on cherche l'argument --file et on lit/écrit dans le fichier suivant les autres arguments
		int aI;
		for(aI=0; aI < _argc; aI++) {
			if(strcmp(_argv[aI],(char *)"--file") == 0) {
				int aReadWrite = testArgsWriter();
				if((aReadWrite == 0 || aReadWrite == 1)) {
					return readWriteCsvFile(aReadWrite,aI,iChaine);
				}
				else
					return aReadWrite;
			}
		}
		displayLongHelp();
	}
	return 0;
}

void Parser::displayLongHelp() {
	cout << "Usage: " << "friends-expenses [--help] [--file filename] [--file filename --name yaya --phone 60 --expense 50 --group titi]\n"
	"--help display the usage.\n"
	"--file filename read the file to render the results.\n"
	"--file filename --name yaya --phone 60 --expense 50 --type Person --group titi write line in the file.\n";
}

int Parser::readWriteCsvFile(int iReadOrWrite, int iNumArgFile, string iChaine) {
	if(iNumArgFile >= _argc-1) {
		cout << "Error: no file mentioned" << endl;
		return -2;
	}
	if(iNumArgFile > 0 && _argv[iNumArgFile+1] != (char *)"") {
		string aFilename(_argv[iNumArgFile+1]);
		string::size_type aIdx;
		aIdx = aFilename.rfind(".");
		if(aIdx != std::string::npos) {
		    string aExt = aFilename.substr(aIdx+1);
		    if(aExt == "csv") {
		    	if(iChaine != "test") {
		    		CsvReaderOrWriter *fileCsv = new CsvReaderOrWriter(iReadOrWrite,_argv[iNumArgFile+1]);
		    		if(iReadOrWrite == 0) {
						cout << "Affichage du fichier CSV" << endl;
						fileCsv->getObjects();
		    		}
		    		else if(iReadOrWrite == 1) {
		    			cout << "ecriture dans le fichier CSV" << endl;
		    			fileCsv->writeLine(_argName,_argPhone,_argExpense,_argGroup,_argType);
		    		}
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
