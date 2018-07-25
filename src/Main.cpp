/*********************************************************************************
Author: Zachary Nelson
Date: Feb 1st 2018

This is the main file for the "GoFish assignment. All it does is run the game.

**********************************************************************************
Contributor: Cody Crawford
Date: March 9 2018

Re-factored and added the game "Cheat"
*********************************************************************************/

#include<iostream>
#include"../include/Game.h"
#include"../include/Player.h"
#include"../include/Viewer.h"
#include"../include/Deck.h"

using namespace std;

int main(){

   Game* game;
   game = new Game();
   game->playGame();

   //delete game;

   return 0;
}
