//============================================================================
// Name        : main.cpp
// Author      : Yannick
// Version     :
// Copyright   : Your copyright notice
// Description : Tutorial - Application to manage friends expenses - main for google tests
//============================================================================

#include <gtest/gtest.h>

using namespace std;

int main(int argc, char **argv) {

	::testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}
