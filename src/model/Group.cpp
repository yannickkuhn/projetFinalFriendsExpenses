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
