/*
 * Donor.hpp
 *
 *  Created on: 11 avr. 2014
 *      Author: Yannick
 */

#ifndef DONOR_HPP_
#define DONOR_HPP_

#include "Person.hpp"

class Donor : public Person {
public:
	Donor();
	Donor(const Group *iGroup);
	void operatePayback(const float iExpensesPerPerson, const int iIfPresenceDonor);
	void setExpenses(const float expenses);
	virtual ~Donor();
};

#endif /* DONOR_HPP_ */
