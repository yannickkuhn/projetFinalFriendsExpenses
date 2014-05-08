/*
 * CsvReader_test.cpp
 *
 *  Created on: 8 mai 2014
 *      Author: Yannick
 */

#include <iostream>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include "../../../src/model/CsvReader.hpp"

TEST(csvReader, testLineContent) {
	CsvReader *aCsv = new CsvReader();
	EXPECT_EQ(1,aCsv->testLineContent("Paul;1234;210.50;Righi;Person"));
	EXPECT_EQ(0,aCsv->testLineContent("mauvaise ligne 0000"));
}

TEST(csvReader, testRound) {
	CsvReader *aCsv = new CsvReader();
	float aF = aCsv->round(1.499);
	EXPECT_EQ(1.5, aF);
}
