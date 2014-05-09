/*
 * Group_test.cpp
 *
 *  Created on: 9 mai 2014
 *      Author: Yannick
 */

#include <iostream>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include "../../../src/model/Group.hpp"
#include "../../../src/model/Person.hpp"
#include "../../../src/model/Donor.hpp"

TEST(donor, testPaybackGroup) {
	Group *aG1 = new Group("test");
	Person *aP1 = new Donor("doneur1","6024",20.0,aG1);
	Person *aP2 = new Person("person1","6025",50.0,aG1);
	Person *aP3 = new Person("person2","6026",20.0,aG1);
	aG1->push_back(aP1);
	aG1->push_back(aP2);
	aG1->push_back(aP3);
	aG1->calculExpensesPerPerson();
	aG1->calculNbOfExpensesPerson();

	EXPECT_EQ("test",aP1->getGroup()->getName());
	EXPECT_EQ("test",aP2->getGroup()->getName());
	EXPECT_EQ("test",aP3->getGroup()->getName());
	EXPECT_EQ(2,aG1->getNbPerson());
	EXPECT_EQ(50.0,aG1->getTotalExpenses());
	EXPECT_EQ(25.0,aG1->getExpensePerPerson());
	EXPECT_EQ(1,aG1->ifOfNotPresenceDonor());
}




