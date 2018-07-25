/**********************************************************************
\Author Zachary Nelson
\Date February 10th 2018

This program is designed to test the Deck Class.

**********************************************************************/

#include<iostream>
#include "gtest/gtest.h"
#include"../include/Deck.h"
#include"../include/Card.h"
#include"../include/Player.h"

using namespace std;

#ifndef DECKTEST_H
#define DECKTEST_H

class DeckTest : public testing::Test
{
protected:
DeckTest();
virtual ~DeckTest();

};

#endif

DeckTest::DeckTest(){
}

DeckTest::~DeckTest(){
}

///This function tests the ShuffleDeck function of the Deck class.

TEST_F(DeckTest, ShuffleDeckTest){
   Deck* D;
   D = new Deck();

   D->ShuffleDeck();
   EXPECT_FALSE((D->DrawCard())->Value() ==  (D->DrawCard())->Value());

   delete D;
}


///This function tests the DrawCard function of the Deck class.
TEST_F(DeckTest, TestDrawCard){
   Deck* D;
   D = new Deck();
   EXPECT_NE(D->DrawCard(), nullptr);
   EXPECT_EQ(D->CardsLeft(), 51);
   delete D;
}

