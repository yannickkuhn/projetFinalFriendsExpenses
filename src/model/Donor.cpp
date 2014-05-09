/*
 * Donor.cpp
 *
 *  Created on: 11 avr. 2014
 *      Author: Yannick
 */

#include "Donor.hpp"

Donor::Donor() {
	_expenses = 0;
	_payback = 0;
}

Donor::Donor(const Group *iGroup) {
	_expenses = 0;
	_payback = 0;
	_group = iGroup;
}

Donor::Donor(const string iName, const string& iPhoneNumber, const float iExpenses) {
	_name = iName;
	_phoneNumber = iPhoneNumber;
	_expenses = -iExpenses;
}

Donor::Donor(const string iName, const string& iPhoneNumber, const float iExpenses, const Group *iGroup) {
	_name = iName;
	_phoneNumber = iPhoneNumber;
	_expenses = -iExpenses;
	_group = iGroup;
}

Donor::~Donor() {

}

void Donor::setExpenses(const float iExpenses) {		// Positive expenses become negative expenses (Donor)
	_expenses = -iExpenses;
}

void Donor::operatePayback(const float iExpensesPerPerson, const int iIfPresenceDonor) {
	_payback = 0;
}

const string Donor::getType() const {
	return "Donor";
}

