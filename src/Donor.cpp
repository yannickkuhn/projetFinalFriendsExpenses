/*
 * Donor.cpp
 *
 *  Created on: 11 avr. 2014
 *      Author: ubuntu
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

Donor::~Donor() {

}

void Donor::setExpenses(const float expenses) {		// Positive expenses become negative expenses (Donor)
	_expenses = -expenses;
}

void Donor::operatePayback(const float iExpensesPerPerson, const int iIfPresenceDonor) {
	_payback = 0;
}

