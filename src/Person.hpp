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
    virtual void operatePayback(const float iExpensesPerPerson, const int iIfPresenceDonor);

// getters of Person
    const string& getName() const;
    const string& getPhoneNumber() const;
    const string& getType() const;
    const float getExpenses() const;
    const float getPayback() const;
    const Group* getGroup() const;

// setters of Person
    void setName(const string& name);
    void setPhoneNumber(const string& phoneNumber);
    void setType(const string& type);
    virtual void setExpenses(const float expenses);
    void setPayback(const float payback);

protected:
    float _expenses;
    float _payback;
    string _name;
    string _phoneNumber;
    string _type;
    const Group *_group;
};

#endif /* PERSON_HPP_ */
