/****************************************************************
\Author Zachary Nelson
\Date February 10th 2018

This is a test program to test the Player Class.

***************************************************************/

#include<iostream>
#include"gtest/gtest.h"
#include"../include/Player.h"
#include"../include/Card.h"

using namespace std;

#ifndef PLAYERTEST_H
#define PLAYERTEST_H

class PlayerTest : public testing::Test
{
protected:

   PlayerTest();
   virtual ~PlayerTest();
   Player *p;

};

#endif

///Default constructor
PlayerTest::PlayerTest(){
   p = new Player();
}

///Default destrtuctor
PlayerTest::~PlayerTest(){
   delete p;
}

///This function tests that the constructor works
TEST_F(PlayerTest, DefaultConstructor){
   EXPECT_EQ(p->GetScore(), 0);
}

///This function tests all of the hand functions of the Player
TEST_F(PlayerTest, HandFunctions){
   Card* C;
   C = new Card('X', "Heart");
   p->AddCard(C);
   EXPECT_EQ(p->HandSize(), 1);
   EXPECT_EQ(p->GetHand()[0], C);

   EXPECT_EQ(p->Search(C->Value()), true);

   p->RemoveCard(C->Value());
   EXPECT_EQ(p->HandSize(), 0);

   delete C;
}

///This function tests the CheckForDuplicates function.
TEST_F(PlayerTest, TestDuplicates){
      Card* C;
      C = new Card('X', "Heart");
      Card* C2;
      C2 = new Card('X', "Spade");

      p->AddCard(C);
      p->AddCard(C2);

      EXPECT_EQ(p->HandSize(), 2);

      p->CheckForDuplicates();

      EXPECT_EQ(p->HandSize(), 0);

      delete C;
      delete C2;
   }

///This function tests teh UpdateScore and the GetScore functions of the Player class.
TEST_F(PlayerTest, UpdateScoreTestAndGetScoreTest){
   EXPECT_EQ(p->GetScore(), 0);
   p->UpdateScore(1);
   EXPECT_EQ(p->GetScore(), 1);
}


