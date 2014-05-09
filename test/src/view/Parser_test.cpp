/*
 * Parser_test.cpp
 *
 *  Created on: 9 mai 2014
 *      Author: Yannick
 */

#include <iostream>
#include <string>
#include <vector>

#include <gtest/gtest.h>
#include "../../../src/view/Parser.hpp"

TEST(parser, testArguments) {
	int argc;

	Parser *aParse;

	// test 1
	char *argv[] = {(char *)"program",(char *)"--help"};
	argc = 2;
	aParse = new Parser(argc, argv);
	EXPECT_EQ(0,aParse->parse());

	// test 2
	char *argv2[] = {(char *)"program"};
	argc = 1;
	aParse = new Parser(argc, argv2);
	EXPECT_EQ(0,aParse->parse());

	// test 3
	char *argv3[] = {(char *)"program",(char *)"--file"};
	argc = 2;
	aParse = new Parser(argc, argv3);
	EXPECT_EQ(-2,aParse->parse());

	// test 4
	char *argv4[] = {(char *)"program",(char *)"--file",(char *)"fichier.txt"};
	argc = 3;
	aParse = new Parser(argc, argv4);
	EXPECT_EQ(-1,aParse->parse());

	// test 5
	char *argv5[] = {(char *)"program",(char *)"--file",(char *)"fichier.csv"};
	argc = 3;
	aParse = new Parser(argc, argv5);
	EXPECT_EQ(1,aParse->parse("test"));
}




