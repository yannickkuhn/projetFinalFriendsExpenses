/*
 * Person.cpp
 *
 *  Created on: Feb 18, 2014
 *      Author: Yannick
 */

#include "Group.hpp"
#include "Person.hpp"


Person::Person() :
    _expenses(0),
    _payback(0) {

}

Person::Person(const Group *iGroup) :
	_expenses(0),
	_payback(0),
	_group(iGroup) {
}

Person::Person(const string iName, const string& iPhoneNumber, const float iExpenses) {
	_name = iName;
	_phoneNumber = iPhoneNumber;
	_expenses = iExpenses;
}

Person::Person(const string iName, const string& iPhoneNumber, const float iExpenses, const Group *iGroup) {
	_name = iName;
	_phoneNumber = iPhoneNumber;
	_expenses = iExpenses;
	_group = iGroup;
}

Person::~Person() {

}

void Person::operatePayback(const float iExpensesPerPerson, const int iIfPresenceDonor) {
	if(iIfPresenceDonor)
		_payback = iExpensesPerPerson;
	else
		_payback = _expenses - iExpensesPerPerson;
}

// getters of Person

const string& Person::getName() const {
	return _name;
}
const string& Person::getPhoneNumber() const {
	return _phoneNumber;
}
const float Person::getExpenses() const {
	return _expenses;
}
const float Person::getPayback() const {
	return _payback;
}
const Group* Person::getGroup() const {
	return _group;
}
const string Person::getType() const {
	return "Person";
}

// setters of Person

void Person::setName(const string& iName) {
	_name = iName;
}
void Person::setPhoneNumber(const string& iPhoneNumber) {
	_phoneNumber = iPhoneNumber;
}
void Person::setExpenses(const float iExpenses) {
	_expenses = iExpenses;
}
void Person::setPayback(const float iPayback) {
	_payback = iPayback;
}
