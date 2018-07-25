/************************************************
Author Zachary Nelson
Date: February 6th 2018

This is the main program to test

*************************************************/

#include<iostream>
#include "gtest/gtest.h"

using namespace std;

int main(int argc, char* argv[])
{
   testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
