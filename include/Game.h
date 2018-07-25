/*****************************************************************
Author: Zachary Nelson
Date: February 1st 2018

This is the Game class. It works as a controller class for the
main program. It carries out the majority of the program, calling functions
from other various classes.

*********************************************************************************/

#include<iostream>
#include<vector>
#include "Deck.h"
#include "Player.h"
#include "Viewer.h"
#include "Card.h"

using namespace std;

#ifndef GAME_H
#define GAME_H

class Game{
  public:
   Game();
   ~Game();
   void playGame();

  private:
};

#endif
