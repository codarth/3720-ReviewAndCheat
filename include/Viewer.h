/*********************************************************************************************
Author: Zachary Nelson
Date: February 1st 2018

This is the Viewer class, which works as the view for the "model view controller" pattern

**********************************************************************************
Contributor: Cody Crawford
Date: March 9 2018

Re-factored and added the game "Cheat"
*********************************************************************************/

#include <iostream>
#include <vector>
#include "Deck.h"
#include "Player.h"
#include "Card.h"

using namespace std;

#ifndef VIEWER_H
#define VIEWER_H

class Viewer{
  public:
   Viewer();
   virtual ~Viewer();

   //Displays the hand of the given player pointer
   virtual void DisplayHand(Player*);

   //Displays the options for go fish
   virtual void DisplayGFOptions();

   //Displays the title screen
   virtual void DisplayTitle();

   //Displays if duplicates are found
   virtual void DuplicatesFound(char);

   //Displays the results
   virtual void DisplayResults(vector<Player*>);

   //Ends a line
   virtual void EndLine();

   //Displays message checking for duplicates
   virtual void CheckingForDupes(int);

   //Displays a turn
   virtual void DisplayTurn(int);

   //Displays a message saying card isnt in your hand
   virtual void CardNotInYourHand();

   //Displays a message saying that a player had a card
   virtual void HadCard(int, int);

   //Displays a message saying that the player did not have the card.
   virtual void NoHadCard(int);

   virtual char GetInput();
   virtual int GetInputInt();
   virtual void DisplayChoice();
   virtual void ErrorMsg();
   virtual void Empty(int);
   virtual void EmptyDeck();
   virtual void PlayerNumber();
  private:


};

#endif
