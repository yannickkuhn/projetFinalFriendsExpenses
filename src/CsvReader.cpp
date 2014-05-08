/*
 * CsvReader.cpp
 *
 *  Created on: 26 mars 2014
 *      Author: Yannick
 */

#include "CsvReader.hpp"

CsvReader::CsvReader(string iFile) {
	_file = iFile;
	_df = new ifstream(_file.data(), ios::in);
	if ( !_df )
		cout << "fichier inexistant";
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
			aPerson->setType(aFields.at(4));

			const type_info &aT1 = typeid(*aPerson);
			string aST1(aT1.name());
			//cout << " (debug) >> Donor or Person : " << aST1 << aFields.at(0) << " " << aFields.at(1) << " " << aPerson->getExpenses() << " " << aFields.at(3) << " " << aPerson->getType() << " "<< aPerson->getGroup()->getName() << endl;

			aNewGroup->push_back(aPerson);

		}
		if(aLine == 0) aLine = 1;
	}while( !_df->eof() );

	cout << "Liste des groupes crées : " << endl;
	for(size_t i=0; i < _groups.size(); i++) {

		Group *tmpGroup = _groups.at(i);

		tmpGroup->calculExpensesPerPerson();
		tmpGroup->calculNbOfExpensesPerson();

		cout << fixed << showpoint << setprecision(2);
		cout << endl;
		cout << "Group " << tmpGroup->getName() << endl;
		cout << "Total expenses:\t\t" << tmpGroup->getTotalExpenses() << endl;
		cout << "Expenses per person:\t" << tmpGroup->getExpensePerPerson() << endl;
		cout << endl;

		cout << "Name\t\t" << "Phone Number\t" << "Expenses\t"
		<< "Payback\t\t" << "Group" << endl;
		cout << "--------------------------------------------------------------------------"
		<< endl;

		for (size_t j=0; j<tmpGroup->size(); ++j) {
			// operate the payback first
			tmpGroup->at(j)->operatePayback(tmpGroup->getExpensePerPerson(),tmpGroup->ifOfNotPresenceDonor());
			// display the values
			cout << tmpGroup->at(j)->getName() << "\t\t" << tmpGroup->at(j)->getPhoneNumber()
			<< "\t\t" << tmpGroup->at(j)->getExpenses() << "\t\t"
			<< tmpGroup->at(j)->getPayback() << "\t\t" << tmpGroup->at(j)->getGroup()->getName() << endl;
		}

	}

}

CsvReader::~CsvReader() {

}

float CsvReader::round(float data) {
	float nearest = floorf(data * 100 + 0.5) / 100;
	return nearest;
}

