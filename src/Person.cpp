/*
 * Person.cpp
 *
 *  Created on: Feb 18, 2014
 *      Author: aabou
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
const string& Person::getType() const {
	return _type;
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

// setters of Person

void Person::setName(const string& name) {
	_name = name;
}
void Person::setPhoneNumber(const string& phoneNumber) {
	_phoneNumber = phoneNumber;
}
void Person::setType(const string& type) {
	_type = type;
}
void Person::setExpenses(const float expenses) {
	_expenses = expenses;
}
void Person::setPayback(const float payback) {
	_payback = payback;
}
