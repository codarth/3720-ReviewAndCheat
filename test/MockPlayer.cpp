/************************************************************
Author: Zachary Nelson
Date: February 6th 2018

This is the MockPlayer class, which is a mock of the Player class.
This is used to test the Game class.

****************************************************************/

#include<iostream>
#include<vector>
#include "gmock/gmock.h"
#include "../include/Card.h"
#include "../include/Player.h"

using namespace std;

#ifndef MOCKPLAYER_H
#define MOCKPLAYER_H

class MockPlayer: public Player {
  public:

   MOCK_METHOD0(GetHand, vector<Card*>());
   MOCK_METHOD1(UpdateScore, void(const int *i));
   MOCK_METHOD0(HandSize, int());
   MOCK_METHOD1(AddCard, void(Card* c));
   MOCK_METHOD1(Search, bool(char ch));
   MOCK_METHOD1(RemoveCard, void(char ch2));
   MOCK_METHOD0(CheckForDuplicates, char());
   MOCK_METHOD0(GetScore, int());

};

#endif
