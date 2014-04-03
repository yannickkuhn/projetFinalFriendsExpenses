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

void Person::operatePayback(const float iExpensesPerPerson) {
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

// setters of Person

void Person::setName(const string& name) {
	_name = name;
}
void Person::setPhoneNumber(const string& phoneNumber) {
	_phoneNumber = phoneNumber;
}
void Person::setExpenses(const float expenses) {
	_expenses = expenses;
}
void Person::setPayback(const float payback) {
	_payback = payback;
}
