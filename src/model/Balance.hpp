/*
 * Balance.hpp
 *
 *  Created on: 22 mai 2014
 *      Author: Yannick
 */

#ifndef BALANCE_HPP_
#define BALANCE_HPP_

#include "Person.hpp"

using namespace std;

class Balance {
public:
	Balance();
	Balance(Person iPersonPut, Person iPersonGet, float iValue);

	const Person getPersonPut() const;
	const Person getPersonGet() const;
	const float getValue() const;

	virtual ~Balance();
private:
	float _value;
	Person _personPut, _personGet;
};

#endif /* BALANCE_HPP_ */
