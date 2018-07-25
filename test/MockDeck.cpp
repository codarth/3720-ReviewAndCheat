/***********************************************************
Author: Zachary Nelson
Date: February 6th 2018

This is the MockDeck class, which is a mock of the Deck class.
This is used to test the Game class.

*************************************************************/

#include<iostream>
#include "gmock/gmock.h"
#include "../include/Card.h"
#include "../include/Deck.h"
#include "MockCard.cpp"

using namespace std;

#ifndef MOCKDECK_H
#define MOCKDECK_H

class MockDeck: public Deck {
  public:

   MOCK_METHOD0(DrawCard, MockCard*());
   MOCK_METHOD0(ShuffleDeck, void());
   MOCK_METHOD0(CardsLeft, int());

};

#endif
