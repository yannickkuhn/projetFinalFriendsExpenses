/*
 * Person.hpp
 *
 *  Created on: Feb 18, 2014
 *      Author: Yannick
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
    Person(const string iName, const string& iPhoneNumber, const float iExpenses);
    Person(const string iName, const string& iPhoneNumber, const float iExpenses, const Group *iGroup);


    virtual ~Person();
    virtual void operatePayback(const float iExpensesPerPerson, const int iIfPresenceDonor);

// getters of Person
    const string& getName() const;
    const string& getPhoneNumber() const;
    const float getExpenses() const;
    const float getPayback() const;
    const Group* getGroup() const;
    virtual const string getType() const;

// setters of Person
    void setName(const string& iName);
    void setPhoneNumber(const string& iPhoneNumber);
    virtual void setExpenses(const float iExpenses);
    void setPayback(const float iPayback);

protected:
    float _expenses;
    float _payback;
    string _name;
    string _phoneNumber;
    const Group *_group;
};

#endif /* PERSON_HPP_ */
