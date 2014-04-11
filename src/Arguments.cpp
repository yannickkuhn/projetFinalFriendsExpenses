/*
 * Arguments.cpp
 *
 *  Created on: 11 avr. 2014
 *      Author: lapie
 */

#include "Arguments.hpp"



using namespace std;

typedef enum
{
	unknown=0,
	help=1,
	filename=2,
	nothing=3

}ARG;
Arguments::Arguments(int iargc, char **iargv)
{
	_argc = iargc;
	_argv = iargv;

}
vector<string> Arguments::AfficherArguments()
{
	int i;
	vector<string> myarguments;
	_argument=unknown;
	/*  cout << "Nom de programme " << _argv[0] << endl;
	/*  cout << "Nom de programme " << _argv[0] << endl;
	  cout << "Nombre d'arguments : %d\n"<< _argc - 1 << endl;*/
	  for(i=1;i<_argc;++i)
	  {
		  string toto =  _argv[i];
		  if(toto.compare("--help")==0)
		  {
			  _argument=help;
		  }
		  myarguments.push_back(toto);
	  }
	 // _arguments = myarguments;
     return myarguments;  //cout << "Argument" << i << " ==> " <<_argv[i]<< endl;
}
string Arguments::SwitchArguments(vector<string> iArguments)
{
	if(_argument==help)
	{
		AfficherHelp();
	}
	else
	{
		for(unsigned int i=0;i<iArguments.size();i++)
			{
				if(iArguments.at(i).compare("--file")==0)
				{
					return iArguments.at(i+1);
				}
			}
	}

}
void Arguments::AfficherHelp()
{
	cout << "--help                display me"<< endl;
	cout << "--file filename       read the file to render the result"<< endl;
	cout << endl;
}


