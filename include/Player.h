/*****************************************************************************************
Author Zachary Nelson
Date February 1st 2018

This is the Player class, which contains all of the player functions.

**********************************************************************************
Contributor: Cody Crawford
Date: March 9 2018

Re-factored and added the game "Cheat"
*********************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include"Deck.h"
#include"Card.h"
#include<vector>
#include <algorithm>

using namespace std;

class Player{

  public:
   Player();
   virtual ~Player();

   //Returns the player's hand as a vector of Card pointers.
   virtual vector<Card*> GetHand();

   void SetName(std::string n) { name = n; };
   std::string GetName() { return name; };

   //Update the player's score by i
   virtual void UpdateScore(const int &i);

   //Returns the size of the hand
   virtual size_t HandSize();

   //Adds a card to the player's hand
   virtual void AddCard(Card*);

   //Searches the player's hand for a char with the value char
   virtual bool Search(char);

   //Removes a card from the player's hand
   virtual void RemoveCard(char);

   void RemoveCard(Card * card);

   //Checks the player's hand for duplicate cards.
   virtual char CheckForDuplicates();

   //Returns the player's score
   virtual int GetScore();

   void SortHand();

  private:
   vector<Card*> hand;
   std::string name;
   int Score;
};

#endif
