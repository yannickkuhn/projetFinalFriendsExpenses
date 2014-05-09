/*
 * Person_test.cpp
 *
 *  Created on: 8 mai 2014
 *      Author: Yannick
 */

#include <iostream>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include "../../../src/model/Group.hpp"
#include "../../../src/model/Person.hpp"

TEST(person, testPaybackPerson) {
	Group *aG1 = new Group("test");
	Person *aP1 = new Person("person1","6024",30.0,aG1);
	Person *aP2 = new Person("person2","6025",20.0,aG1);
	aG1->push_back(aP1);
	aG1->push_back(aP2);
	aP1->operatePayback(25.0,0);
	aP2->operatePayback(25.0,0);

	EXPECT_EQ("person1",aP1->getName());
	EXPECT_EQ("6024",aP1->getPhoneNumber());
	EXPECT_EQ(30.0,aP1->getExpenses());
	EXPECT_EQ(5.0,aP1->getPayback());
	EXPECT_EQ("Person",aP1->getType());
	EXPECT_EQ("test",aP1->getGroup()->getName());
}




