/******************************************************************************************************
Author: Zachary Nelson
Date February 1st 2018

This is the Card class, which defines a Card as a value and a suit.
**********************************************************************************
Contributor: Cody Crawford
Date: March 9 2018

Re-factored and added the game "Cheat"
*********************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

#ifndef Card_H
#define Card_H

class Card{
  public:
   Card(char, string);
   virtual ~Card();
   virtual char Value();
   virtual string Suit();
   virtual bool IsEqual(char);

  private:
   char val;
   string suit;

};

#endif
