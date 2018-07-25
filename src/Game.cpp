/**********************************************************************
\Author Zachary Nelson
\Date February 1st 2018

This is the .cc file for the Game class.

**********************************************************************************
Contributor: Cody Crawford
Date: March 9 2018

Re-factored and added the game "Cheat"
*********************************************************************************/

#include<iostream>
#include<vector>
#include "../include/Deck.h"
#include "../include/Player.h"
#include "../include/Viewer.h"
#include "../include/Card.h"
#include "../include/Game.h"
#include "../include/CheatGame.h"

using namespace std;

Game::Game(){
}

Game::~Game(){
}

///This function is used to Play the game
void Game::playGame(){

   char decision;
   Player* p1;
   Player* p2;
   Player* p3;
   Player* p4;
   Player* p5;
   Deck* deck;
   Viewer* view;

   p1 = new Player();
   p2 = new Player();
   p3 = new Player();
   p4 = new Player();
   p5 = new Player();
   vector<Player*> PlayerList;
   PlayerList.push_back(p1);
   PlayerList.push_back(p2);
   PlayerList.push_back(p3);
   PlayerList.push_back(p4);
   PlayerList.push_back(p5);
   deck = new Deck();
   view = new Viewer();
   int playerNumber;
   int playerChoice;
   bool checkEmpty = true;

   view->DisplayTitle();
   decision = view->GetInput();

   //Player chooses the "GoFish option"
   if(decision == '1'){

   //Shuffles the deck
      deck->ShuffleDeck();

      view->PlayerNumber();
      do{
	 playerNumber = view->GetInputInt();

	 if(playerNumber < 2 || playerNumber > 5)
	    cout << "Invalid number of players. Try again." << endl;
      }while(playerNumber < 2 || playerNumber > 5);


   //This for loop adds 5 cards to each player's hand.
      for(int i = 0; i < playerNumber; i++){

	 for(int j = 0; j < 5; j++){
	    PlayerList[i]->AddCard(deck->DrawCard());
	 }
      }

      char valueFound;
      for(int i = 0; i < playerNumber; i++){
	 view->CheckingForDupes(i+1);
	 valueFound = PlayerList[i]->CheckForDuplicates();
	 if(valueFound != '0'){
	    view->DuplicatesFound(valueFound);
	 }
      }


      //Clears the cin just in case
      cin.clear();
      do{

	 for(int i = 0; i < playerNumber; i++){
	    view->DisplayTurn(i+1);

	    //Displays player 1's hand
	    view->DisplayHand(PlayerList[i]);

	    //Displays the options
	    view->DisplayGFOptions();

	    //This loop repeats if the player chooses a card which is not in their hand.
	    do{
	       decision = view->GetInput();

	       //Search hand to verify that the decision is actually in the player's hand
	       if(PlayerList[i]->Search(decision) == false)
		  view->CardNotInYourHand();
	    }while(PlayerList[i]->Search(decision) == false);

	    view->DisplayChoice();
	    //This loop asks the player which player they wish to ask
	    do{
	       playerChoice = view->GetInputInt();

	       if(playerChoice > playerNumber || playerChoice < 1 || playerChoice == i+1)
		  view->ErrorMsg();
	    }while(playerChoice > playerNumber || playerChoice < 1 || playerChoice == i+1);

	    if(PlayerList[playerChoice-1]->Search(decision) == true){
	       view->HadCard(i+1, playerChoice);
	       view->EndLine();

	       //Increases Player 1's score by 1
	       PlayerList[i]->UpdateScore(1);

	       //Removes the requested card from both player's hands
	       PlayerList[i]->RemoveCard(decision);
	       PlayerList[playerChoice-1]->RemoveCard(decision);

	    }
	    else{
	       view->NoHadCard(playerChoice);
	       view->EndLine();

	       //Player 1 draws a card
	       PlayerList[i]->AddCard(deck->DrawCard());

	       //Check for duplicate!
	       view->CheckingForDupes(i+1);
	       valueFound = PlayerList[i]->CheckForDuplicates();
	       if(valueFound != '0'){
		  view->DuplicatesFound(valueFound);
	       }

	    }


	 //Clears the cin
	 cin.clear();


	 //If either player hand is empty, or the deck is empty, break the loop.
	 for(int j = 0; j < playerNumber; j++){
	    if(PlayerList[j]->HandSize()-1 <= 0)
	       checkEmpty = false;
	    if(deck->CardsLeft() <= 0)
	       checkEmpty = false;
	 }
	 }

	 /*
	 for(int j = 0; j < playerNumber; j++){
	    if(PlayerList[j]->HandSize() == 0)
	       break;
	       }
	 */
      }while(checkEmpty == true &&(deck->CardsLeft() > 0));

      //If either player's hand is empty, or the deck is empty, end the game.
      for(int i = 0; i < PlayerList.size(); i++){
	 if(PlayerList[i]->HandSize() <= 0)
	    view->Empty(i);
      }
      if(deck->CardsLeft() <= 0){
	 view->EmptyDeck();
      }

      view->DisplayResults(PlayerList);
   }
   else if(2){
	   CheatGame* cheat;
	   cheat = new CheatGame;
	   cheat->Begin();
	   cheat->Play();
   }
   else
   {
	   view->ErrorMsg();
   }


   //delete p1;
   //delete p2;
   //delete p3;
   //delete p4;
   //delete p5;
   //delete view;
   //delete deck;
}

