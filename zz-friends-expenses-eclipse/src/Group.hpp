/*
 * Group.hpp
 *
 *  Created on: Feb 18, 2014
 *      Author: aabou
 */

#ifndef GROUP_HPP_
#define GROUP_HPP_

#include <vector>
#include <string>
#include "Person.hpp"


class Group : public vector<Person> {

public:
    Group();
    virtual ~Group();

    float totalExpenses();
    float expensesPerPerson();

// getters of Group
    const float getExpensePerPerson() const;
    const float getTotalExpenses() const;
    const string& getName() const;

// setters of Group
    void setExpensePerPerson(const float expensePerPerson);
    void setTotalExpenses(const float totalExpenses);
    void setName(const string& name);

private:
	float _expensePerPerson;
	float _totalExpenses;
	string _name;
};

#endif /* GROUP_HPP_ */
