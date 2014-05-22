/*
 * CsvReader.cpp
 *
 *  Created on: 26 mars 2014
 *      Author: Yannick
 */

#include "CsvReaderOrWriter.hpp"

CsvReaderOrWriter::CsvReaderOrWriter() {

}

CsvReaderOrWriter::CsvReaderOrWriter(int iReadOrWrite, char *iFile) {
	_file = iFile;
	_readOrWrite = iReadOrWrite;
	//cout << "CsvReaderOrWriter recuperer le fichier : " << _file << endl;
}

// setters and getters

void CsvReaderOrWriter::setFile(char *iFile) {
	_file = iFile;
}
void CsvReaderOrWriter::setReadOrWrite(const int iReadOrWrite) {
	_readOrWrite = iReadOrWrite;
}

const char * CsvReaderOrWriter::getFile() const {
	return _file;
}
const int CsvReaderOrWriter::getReadOrWrite() const {
	return _readOrWrite;
}

int CsvReaderOrWriter::testGroupInMemory(string iName) {
	for(size_t i=0; i < _groups.size(); i++) {
		if(_groups.at(i)->getName() == iName) {
			return i;
		}
	}
	return -1;
}

int CsvReaderOrWriter::testPersonInMemory(Group *iGroup, string iNamePerson) {
	for(size_t i=0; i < iGroup->size(); i++) {
		if(iGroup->at(i)->getName() == iNamePerson) {
			return i;
		}
	}
	return -1;
}

int CsvReaderOrWriter::testLineContent(string iLineContent) {

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

int CsvReaderOrWriter::getObjects() {
	ifstream *_df;
	if(_readOrWrite == 1) {
		cerr << "Problème, fichier ouvert en écriture (_readOrWrite = 1) ..." << endl;
		return -1;
	}
	_df = new ifstream(_file, ios::in);
	if ( !_df ) {
		cout << "fichier inexistant";
		return -1;
	}
	cout << "lecture du fichier ok" << endl;

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

			// vérifier si le groupe n'est pas déjà en mémoire
			int aActualGroup = testGroupInMemory(aCWordGroupName);
			Group *aNewGroup;

			if(aActualGroup == -1) {
				aNewGroup = new Group(aCWordGroupName);
				_groups.push_back(aNewGroup);
				//cout << "creation du groupe " << aNewGroup->getName() << endl;
			}
			else {
				aNewGroup = _groups.at(aActualGroup);
			}

			// on a récupérer le groupe qu'il nous faut, maintenant travaillons sur les personnes
			// vérifier si la personne n'est pas déjà en mémoire
			int aActualPerson = testPersonInMemory(aNewGroup, aFields.at(0));
			Person *aPerson;

			if(aActualPerson == -1) {

				//cout << "on créer la personne ..." << endl;

				if(aFields.at(4) == "Person")
					aPerson = new Person(aNewGroup);
				else if(aFields.at(4) == "Donor")
					aPerson = new Donor(aNewGroup);
				else {
					cerr << "error - read CSV file - problem with type of Person" << endl;
					return -10;
				}

				aPerson->setName(aFields.at(0));
				aPerson->setPhoneNumber(aFields.at(1));
				aPerson->setExpenses((float)atof(aFields.at(2).c_str()));

				aNewGroup->push_back(aPerson);
			}
			else {
				aPerson = aNewGroup->at(aActualPerson);

				//cout << "on récupère la personne déjà créer ..." << aPerson->getType() << endl;
				if(aPerson->getType() == "Person") {
					if(aFields.at(4) == "Donor") {
						int aTotal = aPerson->getExpenses()-(float)atof(aFields.at(2).c_str());
						//cout << "cas Person Doneur ..." << aTotal << endl;
						if(aTotal > 0) {	// si une personne, est doneuse, et que la somme est positive, c'est une personne
							cout << "Person " << aPerson->getName() << " -> Doneur == " << aTotal;
							aPerson->setExpenses(aTotal);
						}
						else {
							// sinon c'est un doneur (il faut le transformer)
							aPerson = new Donor(aPerson->getName(),aPerson->getPhoneNumber(),-aTotal,aPerson->getGroup());
							//cout << "Transformation en doneur ..." << -aTotal << endl;
							aNewGroup->at(aActualPerson) = aPerson;
						}
					}
					if(aFields.at(4) == "Person") {
						int aTotal = aPerson->getExpenses()+(float)atof(aFields.at(2).c_str());
						aPerson->setExpenses(aTotal);
					}
				}
				else if(aPerson->getType() == "Donor") {
					if(aFields.at(4) == "Donor") {
						int aTotal = aPerson->getExpenses()-(float)atof(aFields.at(2).c_str());
						//cout << "cas du doneur doneur" << aTotal << endl;
						aPerson->setExpenses(-aTotal);
					}
					if(aFields.at(4) == "Person") {
						int aTotal = aPerson->getExpenses()+(float)atof(aFields.at(2).c_str());
						if(aTotal > 0) {	// si une personne, est doneuse, et que la somme est positive, c'est une personne
							// c'est une personne (il faut la transformer)
							aPerson = new Person(aPerson->getName(),aPerson->getPhoneNumber(),aTotal,aPerson->getGroup());
							aNewGroup->at(aActualPerson) = aPerson;
						}
						else {
							aPerson->setExpenses(-aTotal);
						}
					}
				}
			}

			const type_info &aT1 = typeid(*aPerson);
			string aST1(aT1.name());
			//cout << " (debug) >> Donor or Person : " << aST1 << aFields.at(0) << " " << aFields.at(1) << " " << aPerson->getExpenses() << " " << aFields.at(3) << " " << aPerson->getType() << " "<< aPerson->getGroup()->getName() << endl;

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
	_df->close();

	cout << endl << color(34) << "Balances :" << endl;
	cout << "---------------------------" << color(37) << endl << endl;

	for(size_t i=0; i < _groups.size(); i++) {
		Group *aTmpGroup = _groups.at(i);
		aTmpGroup->doBalance();
	}

	return 1;

}

CsvReaderOrWriter::~CsvReaderOrWriter() {

}

float CsvReaderOrWriter::round(float iData) {
	float nearest = floor(iData * 100 + 0.5) / 100;
	return nearest;
}

void CsvReaderOrWriter::printColorValues(string iText, float iValue) {
	cout << iText;
	if(iValue <= 0)
		cout << color(30) << iValue << color(37);
	else
		cout << color(31) << iValue << color(37);
}

int CsvReaderOrWriter::writeLine(string iName, string iPhone, string iExpense, string iGroup, string iType) {
	if(iType == "")
		iType = "Person";
	ofstream ofs;
	ofs.open ((char *)_file, std::ofstream::out | std::ofstream::app);
	ofs << iName << ";" << iPhone << ";" << iExpense << ";" << iGroup << ";" << iType << endl;
	ofs.close();
	return 1;
}
