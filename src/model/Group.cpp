/*
 * Group.cpp
 *
 *  Created on: Feb 18, 2014
 *      Author: Yannick
 */

#include "Person.hpp"
#include "Group.hpp"


Group::Group() :
	_expensePerPerson(0),
	_totalExpenses(0),
	_nbPerson(0) {

}

Group::Group(string iName) :
	_expensePerPerson(0),
	_totalExpenses(0),
	_nbPerson(0),
	_name(iName) {

}

Group::~Group() {

}

void Group::totalExpenses() {
	_totalExpenses = 0;
    for (size_t i=0; i < this->size(); i++) {
    	_totalExpenses += this->at(i)->getExpenses();
    }
}

void Group::calculNbOfExpensesPerson() {
	_nbPerson = 0;
	for (size_t i=0; i < this->size(); i++) {
		if(this->at(i)->getType() == "Person") {
			_nbPerson++;
		}
	}
}

void Group::calculExpensesPerPerson() {
    //float aExpense = this->totalExpenses() / this->size();  -- obsolete with Donor
	this->totalExpenses();
	this->calculNbOfExpensesPerson();
	_expensePerPerson = _totalExpenses / _nbPerson;
}

int Group::ifOfNotPresenceDonor() {
	for (size_t i=0; i < this->size(); i++) {
		if(this->at(i)->getType() == "Donor") {
			return 1;
		}
	}
	return 0;
}

vector<Balance> Group::doBalance() {

    string _aName;
    vector<Balance> aBalances;

	vector<Person> aPersonspositives;
	vector<Person> aPersonsnegatives;
	float aPositive = 0;
	float aNegative = 0;

	for(size_t i=0; i < this->size(); i++) {
		if(this->at(i)->getType() != "Donor") {
			this->at(i)->setBalance(this->at(i)->getPayback());
			if (this->at(i)->getPayback() > 0) {
				aPersonspositives.push_back(*(this->at(i)));
				aPositive = aPositive + this->at(i)->getPayback();
			} else {
				aPersonsnegatives.push_back(*(this->at(i)));
				aNegative = aNegative + this->at(i)->getPayback();
			}
		}
	}

	//cout << "Remplissage du tableau avec ... nb de personnes positives : " << aPersonspositives.size() << endl;
	//cout << "Remplissage du tableau avec ... nb de personnes negatives : " << aPersonsnegatives.size() << endl;

	for(size_t i=0; i < aPersonsnegatives.size(); i++) {
		for(size_t j=0; j < aPersonspositives.size(); j++) {
			if (aPersonsnegatives[i].getBalance() < 0) {
				if (aPersonspositives[j].getBalance() > 0) {

					float giveto = 0 - aPersonsnegatives[i].getBalance();
					float receivefrom = aPersonspositives[j].getBalance();
					if (giveto > receivefrom) {
						aPersonsnegatives[i].setBalance(aPersonsnegatives[i].getBalance() + receivefrom);
						aPersonspositives[j].setBalance(aPersonspositives[j].getBalance() - receivefrom);
						aBalances.push_back(Balance(aPersonsnegatives[i], aPersonspositives[j], receivefrom));
					} else {
						aPersonsnegatives[i].setBalance(aPersonsnegatives[i].getBalance() + giveto);
						aPersonspositives[j].setBalance(aPersonspositives[j].getBalance() - giveto);
						aBalances.push_back(Balance(aPersonsnegatives[i], aPersonspositives[j], giveto));
					}
				}
			}
		}
	}


	if(aBalances.size()>0) {
		cout << "Pour le groupe : " << this->getName() << endl;
		cout << "----------------------------------------------" << endl;
	}

	for(int aIBalances=0; aIBalances < aBalances.size(); aIBalances ++)
	{
		cout << "* " << aBalances.at(aIBalances).getPersonGet().getName() << " envoie: " << aBalances.at(aIBalances).getValue();
		cout << " euros et " << aBalances.at(aIBalances).getPersonPut().getName() << " recoit: " << aBalances.at(aIBalances).getValue() << " euros" << endl;
	}

	if(aBalances.size()>0)
		cout << "----------------------------------------------" << endl << endl;

	return aBalances;

}

// Getters of Person

const float Group::getExpensePerPerson() const {
	return _expensePerPerson;
}
const float Group::getTotalExpenses() const {
	return _totalExpenses;
}
const string& Group::getName() const {
	return _name;
}
const int Group::getNbPerson() const {
	return _nbPerson;
}

// Setters of Person

void Group::setExpensePerPerson(const float iExpensePerPerson) {
	_expensePerPerson = iExpensePerPerson;
}

void Group::setTotalExpenses(const float iTotalExpenses) {
	_totalExpenses = iTotalExpenses;
}

void Group::setName(const string& iName) {
	_name = iName;
}

void Group::setNbPerson(const int iNbPerson) {
	_nbPerson = iNbPerson;
}
