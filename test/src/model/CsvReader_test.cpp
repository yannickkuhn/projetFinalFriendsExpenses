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
#include "../../../src/model/CsvReaderOrWriter.hpp"

TEST(csvReader, testLineContent) {
	CsvReaderOrWriter *aCsv = new CsvReaderOrWriter();
	EXPECT_EQ(1,aCsv->testLineContent("Paul;1234;210.50;Righi;Person"));
	EXPECT_EQ(0,aCsv->testLineContent("mauvaise ligne 0000"));
}

TEST(csvReader, testRound) {
	CsvReaderOrWriter *aCsv = new CsvReaderOrWriter();
	float aF = aCsv->round(1.499);
	EXPECT_EQ(1.5, aF);
}
