/***********************************************************
Author: Zachary Nelson
Date: February 6th 2018

This is the MockDeck class, which is a mock of the Deck class.
This is used to test the Game class.

*************************************************************/

#include<iostream>
#include "gmock/gmock.h"

using namespace std;

class MockDeck : public Deck {
  public:

   MOCK_METHOD0(DrawCard, Card*());
   MOCK_METHOD0(ShuffleDeck, void());
   MOCK_METHOD0(CardsLeft, int());

};
