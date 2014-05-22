/*
 * Balance.hpp
 *
 *  Created on: 16 mai 2014
 *      Author: Yannick
 */

#ifndef BALANCE_HPP_
#define BALANCE_HPP_

#include "Person.hpp"

class Balance {

public:
	Balance(Person iPersonPut, Person iPersonGet, float iValue);
	virtual ~Balance();

	const Person getPersonPut() const;
	const Person getPersonGet() const;
	const float getValue() const;

private:
	Balance();
	Person _personPut;
	Person _personGet;
	float _value;
};

#endif /* BALANCE_HPP_ */
