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

	// test 6
	char *argv6[] = {(char *)"program",(char *)"--file",(char *)"fichier.csv",(char *)"--name",(char *)"toto"};
	argc = 5;
	aParse = new Parser(argc, argv6);
	EXPECT_EQ(-3,aParse->parse("test"));

	// test 7
	char *argv7[] = {(char *)"program",(char *)"--file",(char *)"fichier.csv",(char *)"--name",(char *)"--phone",(char *)"--expense",(char *)"--group"};
	argc = 7;
	aParse = new Parser(argc, argv7);
	EXPECT_EQ(-4,aParse->parse("test"));

	// test 8
	char *argv8[] = {(char *)"program",
					 (char *)"--file",(char *)"fichier.csv",
					 (char *)"--name",(char *)"yaya",
					 (char *)"--phone",(char *)"6050",
					 (char *)"--expense",(char *)"60",
					 (char *)"--group",(char *)"toto"};
	argc = 11;
	aParse = new Parser(argc, argv8);
	EXPECT_EQ(1,aParse->parse("test"));
}




