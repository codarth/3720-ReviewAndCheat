/*******************************************************************************************
\Author: Zachary Nelson
\Date February 1st 2018

This is the .cc file for the Card class.

**********************************************************************************
Contributor: Cody Crawford
Date: March 9 2018

Re-factored and added the game "Cheat"
*********************************************************************************/

#include<iostream>
#include"../include/Card.h"

using namespace std;

///Constructs the Card
Card::Card(char v, string s){
   val = v;
   suit = s;
};

///Destructs the card
Card::~Card(){};

///Returns the value of the card
/// \return out the value of the card as a char
char Card::Value(){
   return val;
}

///Returns the suit of the card
/// \return out the suit of the card as a string
string Card::Suit(){
   return suit;
}

///Checks to see if a card is equal to a given char. If it is, return true.
/// \return a boolean value, true if equal, false if not
bool Card::IsEqual(char c){
   if(c == val)
      return true;
   else
      return false;
}
