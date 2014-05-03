/*
 * Csv.cpp
 *
 *  Created on: 26 mars 2014
 *      Author: ubuntu
 */

#include "Csv.hpp"

Csv::Csv(string iFile) {
	_file = iFile;
	_df = new ifstream(_file.data(), ios::in);
	if ( !_df )
		cout << "fichier inexistant";
}

void Csv::getObjects() {
	vector <string> aFileLines;

	/* on récupère les lignes dans un vecteur de chaine de caractères pour pouvoir
	 * les parcourir de façon rapide (les informations sont en mémoire ram)
	 */
	while( !_df->eof() )
	{
		aFileLines.push_back("");
		getline(*_df, aFileLines.back());
		int ligne = aFileLines.size() - 1;
		/* si la ligne est vide, on la retire */
		if(aFileLines[ligne].empty())
			aFileLines.pop_back();
	}

	/* creation d'une liste pour récupérer les noms de groupes */
	list<string> aStrGroups;

	for(unsigned int i=1; i<aFileLines.size(); i++) {
		vector<string> aFields;
		CountWord aCWord(aFileLines.at(i).data());
		aFields = aCWord.split();
		aStrGroups.push_back(aFields.at(3));
	}

	/* on tri la liste, puis on enlève les doublons */
	aStrGroups.sort();
	aStrGroups.unique();


	/* on va récupérer les personnes par groupe grâce à un vecteur de groupes */
	for (list<string>::iterator it = aStrGroups.begin() ; it != aStrGroups.end(); ++it) {
		//cout << "(debug) >> Groupe : " << *it << endl;
		Group aGroup;
		aGroup.setName(*it);

		for(unsigned int i=1; i<aFileLines.size(); i++) {
			vector<string> aFields;
			CountWord aCWord(aFileLines.at(i).data());
			aFields = aCWord.split();

			/* si la personne correspond au nom du groupe (dans l'ordre) */

			if(aFields.at(3) == aGroup.getName()) {

				Person *aPerson;

				if(aFields.at(4) == "Person") {
					aPerson = new Person(&aGroup);
				}
				else if(aFields.at(4) == "Donor") {
					aPerson = new Donor(&aGroup);
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
				cout << "  (debug) >> Donor or Person : " << aFields.at(0) << " " << aFields.at(1) << " " << aPerson->getExpenses() << " " << aFields.at(3) << " " << aPerson->getType() << endl;

				aGroup.push_back(aPerson);

			}
		}

		_groups.push_back(aGroup);
	}

	/* affichage */

	for (vector<Group>::iterator it = _groups.begin() ; it != _groups.end(); ++it) {

		it->calculExpensesPerPerson();

		cout << endl;
		cout << "Group " << it->getName() << endl;
		cout << "Total expenses:\t\t" << it->getTotalExpenses() << endl;
		cout << "Expenses per person:\t" << it->getExpensePerPerson() << endl;
		cout << endl;

		cout << "Name\t\t" << "Phone Number\t" << "Expenses\t"
		<< "Payback\t\t" << "Type\t\t" << "Group" << endl;
		cout << "------------------------------------------------------------------------------------"
		<< endl;

		Group aGroup = *it;

		for (size_t i=0; i < aGroup.size(); ++i) {
			// operate the payback first
			aGroup.calculExpensesPerPerson();
			aGroup[i]->operatePayback(aGroup.getExpensePerPerson(),aGroup.ifOfNotPresenceDonor());
			// display the values
			cout << aGroup[i]->getName() << "\t\t" << aGroup[i]->getPhoneNumber()
			<< "\t\t" << round(aGroup[i]->getExpenses()) << "\t\t"
			<< round(aGroup[i]->getPayback()) << "\t\t"
			<< aGroup[i]->getType() << "\t\t" << aGroup[i]->getGroup()->getName() << endl;
		}
		cout << endl;
	}


}

Csv::~Csv() {

}

float Csv::round(float data) {
	float nearest = floorf(data * 100 + 0.5) / 100;
	return nearest;
}

