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
	UNKNOWN=0,
	HELP=1,
	FILENAME=2,
	NOTHING=3

}ARG;
Arguments::Arguments(int iargc, char **iargv)
{
	_argc = iargc;
	_argv = iargv;

}
void Arguments::AfficherArguments()
{
	int i;
	  cout << "Nom de programme " << _argv[0] << endl;
	  cout << "Nombre d'arguments : %d\n"<< _argc - 1 << endl;
	  for(i=1;i<_argc;++i)
	  {

	  }
    	  cout << "Argument" << i << " ==> " <<_argv[i]<< endl;
}
void Arguments::SwitchArguments()
{

}


