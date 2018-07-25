/************************************************
\Author Zachary Nelson
\Date February 10th 2018

This is a program used to test the Builder Class

*************************************************/

#include<iostream>
#include<vector>
#include"gtest/gtest.h"
#include"../include/Builder.h"
#include"../include/Card.h"

using namespace std;

#ifndef BUILDERTEST_H
#define BUILDERTEST_H

class BuilderTest: public testing::Test{
  protected:
   BuilderTest();
   ~BuilderTest();

};

#endif

BuilderTest::BuilderTest(){
}

BuilderTest::~BuilderTest(){
}

///This function is used to test the SpawnDeck function of the Builder class.
TEST_F(BuilderTest, TestingSpawnDeck){
   Builder* B;
   B = new Builder();
   vector<Card*> Cards;
   Cards = B->SpawnDeck();

   EXPECT_EQ(Cards[1]->Value(), 'A');

   delete B;
}
