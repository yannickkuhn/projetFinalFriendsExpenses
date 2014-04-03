/*
 * Person.hpp
 *
 *  Created on: Feb 18, 2014
 *      Author: aabou
 */

#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <string>
using namespace std;

class Group;	// forward declaration (eviter les inclusions circulaires)

class Person {

public:
    Person();
    Person(const Group *iGroup);
    virtual ~Person();
    void operatePayback(const float iExpensesPerPerson);

// getters of Person
    const string& getName() const;
    const string& getPhoneNumber() const;
    const float getExpenses() const;
    const float getPayback() const;
    const Group* getGroup() const;

// setters of Person
    void setName(const string& name);
    void setPhoneNumber(const string& phoneNumber);
    void setExpenses(const float expenses);
    void setPayback(const float payback);

private:
    string _name;
    string _phoneNumber;
    float _expenses;
    float _payback;
    const Group *_group;
};

#endif /* PERSON_HPP_ */
