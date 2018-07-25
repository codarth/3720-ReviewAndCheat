/*************************************************************************
\Author Zachary Nelson
\Date February 1st 2018

This is the Deck class, which defines a Deck as a vector of Cards.

**********************************************************************************
Contributor: Cody Crawford
Date: March 9 2018

Re-factored and added the game "Cheat"
*********************************************************************************/

#include<iostream>
#include "Card.h"
#include<vector>
#include"Builder.h"

using namespace std;

#ifndef Deck_H
#define Deck_H

class Deck{

  public:
   Deck();
   virtual ~Deck();
   virtual Card* DrawCard();
   virtual void ShuffleDeck();
   virtual int CardsLeft();

  private:
   vector<Card*> Cards;
   Builder* buildCards;

};

#endif
