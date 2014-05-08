/*
 * LineReader_test.cpp
 *
 *  Created on: 08 mai 2014
 *      Author: Yannick
 */

#include <iostream>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include "../../../src/controller/LineReader.hpp"

TEST(lineReader, testWordCount) {
	LineReader *aLn = new LineReader("test;test1;test2");
	EXPECT_EQ(3,aLn->wordCount());
	aLn->setText("test;test1;test2;test3;test4");
	EXPECT_EQ(5,aLn->wordCount());
}

TEST(lineReader, testSplitWord) {
	LineReader *aLn = new LineReader("test;test1;test2");
	vector<string> aChaine;
	aChaine = aLn->splitWord(";");
	EXPECT_EQ("test",aChaine.at(0));
	EXPECT_EQ("test1",aChaine.at(1));
	EXPECT_EQ("test2",aChaine.at(2));
}
