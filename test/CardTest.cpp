/**************************************************************************
\Author Zachary Nelson
\Date February 10th 2018

This is a test program to test the Card Class.

****************************************************************************/

#include<iostream>
#include"gtest/gtest.h"
#include"../include/Card.h"

using namespace std;

#ifndef CARD_H
#define CARD_H

class CardTest : public testing::Test
{
protected:
   CardTest();
   virtual ~CardTest();
   Card* C;

};

#endif

CardTest::CardTest(){
   C = new Card('X', "Heart");
}

CardTest::~CardTest(){
   delete C;
}

///This function tests the Value function of the Card class.
TEST_F(CardTest, TestValue){
   EXPECT_EQ(C->Value(), 'X');
}

///This function tests the Suit function of the Card class.
TEST_F(CardTest, TestSuit){
   EXPECT_EQ(C->Suit(), "Heart");
}

///This Function tests the IsEqual function of the Card Class.
TEST_F(CardTest, TestEqual){
   EXPECT_EQ(C->IsEqual('X'), true);
   EXPECT_EQ(C->IsEqual('A'), false);

}
