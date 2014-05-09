/*
 * CsvReader.cpp
 *
 *  Created on: 26 mars 2014
 *      Author: Yannick
 */

#include "CsvReader.hpp"

CsvReader::CsvReader() {

}

CsvReader::CsvReader(string iFile) {
	_file = iFile;
	cout << "recuperer le fichier : " << _file << endl;
	_df = new ifstream(_file.data(), ios::in);
	if ( !_df )
		cout << "fichier inexistant";
	cout << "lecture du fichier ok" << endl;
}

// setters and getters

void CsvReader::setFile(const string& iFile) {
	_file = iFile;
}

const string& CsvReader::getFile() const {
	return _file;
}


int CsvReader::testGroupInMemory(string iName) {
	for(size_t i=0; i < _groups.size(); i++) {
		if(_groups.at(i)->getName() == iName) {
			return i;
		}
	}
	return -1;
}

int CsvReader::testLineContent(string iLineContent) {

	vector<string> aFields;
	LineReader aCWord(iLineContent);
	aFields = aCWord.splitWord((char *)";");

	if(aFields.size() == 5) {
		string aName = aFields.at(0);
		const char *aTelNum;
		aTelNum = aFields.at(1).data();
		const char *aExpenses;
		aExpenses = aFields.at(2).data();
		string aGroup = aFields.at(3);
		string aType = aFields.at(4);

		if(aName != "" && atoi(aTelNum) > 0 && atof(aExpenses) > 0 && aGroup != "" && aType != "")
			return 1;
		else
			cout << "(debug)probleme de types au niveau d'une ligne dans le fichier" << endl;
	}
	else
		cout << "(debug)probleme de formalisme au niveau d'une ligne dans le fichier" << endl;

	return 0;
}

void CsvReader::getObjects() {
	vector <string> aFileLines;
	int aLine=0;	/* compteur qui permet de récupérer les données à partir de la ligne 2 */

	/* on récupère les lignes de façon dynamique
	 * on place directement les infos dans des objets (gain en mémoire ram)
	 */
	do
	{
		string aFileLine;
		getline(*_df, aFileLine);
		// si la ligne est vide, on la retire
		if(!aFileLine.empty() && aLine > 0 && testLineContent(aFileLine)) {

			//cout << "(debug) recuperation de la ligne :" << aFileLine << endl;

			vector<string> aFields;
			LineReader aCWord(aFileLine);
			aFields = aCWord.splitWord((char *)";");

			string aCWordGroupName = aFields.at(3);
			Group *aNewGroup;

			int aActualGroup = testGroupInMemory(aCWordGroupName);

			// vérifier si le groupe n'est pas déjà en mémoire
			if(aActualGroup == -1) {
				aNewGroup = new Group(aCWordGroupName);
				_groups.push_back(aNewGroup);
				//cout << "creation du groupe " << aNewGroup->getName() << endl;
			}
			else {
				aNewGroup = _groups.at(aActualGroup);
			}

			// on a récupérer le groupe qu'il nous faut, maintenant travaillons sur les personnes
			Person *aPerson;

			if(aFields.at(4) == "Person") {
			aPerson = new Person(aNewGroup);
			}
			else if(aFields.at(4) == "Donor") {
			aPerson = new Donor(aNewGroup);
			}
			else {
			cerr << "error - read CSV file - problem with type of Person" << endl;
			}

			aPerson->setName(aFields.at(0));
			aPerson->setPhoneNumber(aFields.at(1));
			aPerson->setExpenses((float)atof(aFields.at(2).c_str()));

			const type_info &aT1 = typeid(*aPerson);
			string aST1(aT1.name());
			//cout << " (debug) >> Donor or Person : " << aST1 << aFields.at(0) << " " << aFields.at(1) << " " << aPerson->getExpenses() << " " << aFields.at(3) << " " << aPerson->getType() << " "<< aPerson->getGroup()->getName() << endl;

			aNewGroup->push_back(aPerson);

		}
		if(aLine == 0) aLine = 1;
	}while( !_df->eof() );

	cout << "Liste des groupes crées : " << endl;
	for(size_t i=0; i < _groups.size(); i++) {

		Group *aTmpGroup = _groups.at(i);

		aTmpGroup->calculExpensesPerPerson();
		aTmpGroup->calculNbOfExpensesPerson();

		cout << fixed << showpoint << setprecision(2);
		cout << endl;
		cout << color(34) << "Group " << aTmpGroup->getName() << endl << "---------------------------"  << color(37) << endl;
		printColorValues("Total expenses:\t\t",aTmpGroup->getTotalExpenses());
		cout << endl;
		printColorValues("Expenses per person:\t",aTmpGroup->getExpensePerPerson());
		cout << endl;
		cout << endl;

		cout << color(34) << "Name\t\t" << "Phone Number\t" << "Expenses\t"
		<< "Payback\t\t" << "Group\t\t" << "Type" << endl;
		cout << "--------------------------------------------------------------------------------------"
		<< color(37) << endl;

		for (size_t j=0; j<aTmpGroup->size(); ++j) {
			// operate the payback first
			aTmpGroup->at(j)->operatePayback(aTmpGroup->getExpensePerPerson(),aTmpGroup->ifOfNotPresenceDonor());
			// display the values
			cout << aTmpGroup->at(j)->getName() << "\t\t" << aTmpGroup->at(j)->getPhoneNumber()
			<< "\t\t";
			printColorValues("",aTmpGroup->at(j)->getExpenses());
			cout << "\t\t";
			printColorValues("",aTmpGroup->at(j)->getPayback());
			cout << "\t\t" << aTmpGroup->at(j)->getGroup()->getName() << "\t\t" << aTmpGroup->at(j)->getType() << endl;
		}

	}

}

CsvReader::~CsvReader() {

}

float CsvReader::round(float iData) {
	float nearest = floor(iData * 100 + 0.5) / 100;
	return nearest;
}

void CsvReader::printColorValues(string iText, float iValue) {
	cout << iText;
	if(iValue <= 0)
		cout << color(30) << iValue << color(37);
	else
		cout << color(31) << iValue << color(37);
}
