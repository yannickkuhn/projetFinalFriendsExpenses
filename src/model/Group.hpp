/*
 * Group.hpp
 *
 *  Created on: Feb 18, 2014
 *      Author: Yannick
 */

#ifndef GROUP_HPP_
#define GROUP_HPP_

#include <vector>
#include <string>
#include <typeinfo>
#include <iostream>
#include "Person.hpp"


class Group : public vector<Person *> {

public:
    Group();
    Group(string iName);
    virtual ~Group();

    void totalExpenses();
    void calculExpensesPerPerson();
    void calculNbOfExpensesPerson();

    int ifOfNotPresenceDonor();

// getters of Group
    const float getExpensePerPerson() const;
    const float getTotalExpenses() const;
    const string& getName() const;
    const int getNbPerson() const;

// setters of Group
    void setExpensePerPerson(const float iExpensePerPerson);
    void setTotalExpenses(const float iTotalExpenses);
    void setName(const string& iName);
    void setNbPerson(const int iNbPerson);

private:
	float _expensePerPerson;
	float _totalExpenses;
	int _nbPerson;
	string _name;
};

#endif /* GROUP_HPP_ */
