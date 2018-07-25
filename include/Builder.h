/***************************************************************************************************************
Author: Zachary Nelson
Date: February 1st 2018

This is the Builder class, which builds the entire deck based off of a hard coded function.

**********************************************************************************
Contributor: Cody Crawford
Date: March 9 2018

Re-factored and added the game "Cheat"
*********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include "Card.h"

using namespace std;

#ifndef Builder_H
#define Builder_H

class Builder{
public:
   Builder();
   ~Builder();
   //Spawns a deck
   vector<Card*> SpawnDeck();

private:
   vector<Card*> cards;

};

#endif

