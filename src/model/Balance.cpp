/*
 * Balance.cpp
 *
 *  Created on: 22 mai 2014
 *      Author: Yannick
 */

#include "Person.hpp"
#include "Balance.hpp"

Balance::Balance() {
}

Balance::Balance(Person iPersonPut, Person iPersonGet, float iValue) {
	_personPut = iPersonPut;
	_personGet = iPersonGet;
	_value = iValue;
}

const Person Balance::getPersonPut() const {
	return _personPut;
}
const Person Balance::getPersonGet() const {
	return _personGet;
}
const float Balance::getValue() const {
	return _value;
}

Balance::~Balance() {
}

