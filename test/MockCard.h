/*************************************************************
Author: Zachary Nelson
Date: February 6th 2018

This is a mock of the Card class, used to test the Game class.

*************************************************************/

#include<iostream>
#include "gmock/gmock.h" //Brings in google Mock

using namespace std;

class Mockcard : public Card {
  public:

   MOCK_METHOD0(Value, char());
   MOCK_METHOD0(Suit, string());
   MOCK_METHOD1(IsEqual, bool(char c));

};

