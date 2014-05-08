/*
 * Donor_test.cpp
 *
 *  Created on: 8 mai 2014
 *      Author: Yannick
 */

#include <iostream>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include "../../../src/model/Group.hpp"
#include "../../../src/model/Donor.hpp"

TEST(donor, testPaybackDonor) {
	Group *aG1 = new Group("test");
	Person *aP1 = new Donor("doneur1","6024",20.0,aG1);
	aP1->operatePayback(30.0,1);

	EXPECT_EQ("doneur1",aP1->getName());
	EXPECT_EQ("6024",aP1->getPhoneNumber());
	EXPECT_EQ(20.0,aP1->getExpenses());
	EXPECT_EQ(0,aP1->getPayback());
	EXPECT_EQ("test",aP1->getGroup()->getName());
}




