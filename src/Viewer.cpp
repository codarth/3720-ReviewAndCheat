/************************************************************************************
\Author Zachary Nelson
\Date February 1st 2018

This is the .cc file for the Viewer class, which functions as a viewer. It essentially outputs everything onto the screen.

**********************************************************************************
Contributor: Cody Crawford
Date: March 9 2018

Re-factored and added the game "Cheat"
*********************************************************************************/

#include <iostream>
#include <vector>
#include "../include/Deck.h"
#include "../include/Player.h"
#include "../include/Card.h"
#include "../include/Viewer.h"

using namespace std;

///Constructor, though nothing needs to be built
Viewer::Viewer(){

}

///A default Destructor
Viewer::~Viewer(){

}

///This function returns a user input for a char
char Viewer::GetInput(){
   char in;
   cin >> in;
   return in;
}


///This function returns a user input for an int
int Viewer::GetInputInt(){
   int in;
   cin >> in;
   return in;
}

/// Displays "Which user would you like to ask?"
void Viewer::DisplayChoice(){
   cout << "Which player would you like to ask?" << endl;
}

///Displays an "invalid choice" error message
void Viewer::ErrorMsg(){
   cout << "Invalid Option." << endl;
}

///Displays when a player's hand is empty, or if the deck is empty
void Viewer::Empty(int i){
   cout << "Player " << i << "'s hand is empty. Tallying score!" << endl;
}

///Displays when the deck is empty
void Viewer::EmptyDeck(){
   cout << "There are no more cards in the deck! Tallying score!" << endl;
}

///Displays message asking how many players
void Viewer::PlayerNumber(){
   cout << "How many players? (2-5)" << endl;
}

///Displays the Title screen of the game
void Viewer::DisplayTitle(){
   cout << endl;
   cout << "                      Card Games                        " << endl;
   cout << "                        -------                         " << endl;
   cout << endl;
   cout << "Enter the number of the game you want to play:" << endl;
   cout << "1. Go Fish" << endl;
   cout << "2. Cheat" << endl;
}

///This function is just here to display the next line. It is only defined
///In order to use the Viewer class as much as possible.
void Viewer::EndLine(){

   cout << endl;

}

///This function is used to display a message while searching for duplicate cards.
/// \param[in] in the i for the player which you are checking.
void Viewer::CheckingForDupes(int i){
   cout << "Checking for Duplicate Cards in Player " << i << "'s Hand..." << endl;
}

///This function is used to display the current turn of a player
/// \param[in] in the i which is the number of the player whos turn it is
void Viewer::DisplayTurn(int i){
   cout << "---------------------------" << endl;
   cout << "Player " << i << "'s Turn: " << endl;
   cout << "Your Hand: " << endl;
}

///This function is used to display a message which tells the user that the card is not
///In their hand.
void Viewer::CardNotInYourHand(){
   cout << "That card isnt in your hand! Try again." << endl;
}

///This Function is used to display a message telling you that the other player had a card.
/// \param[in] in the i which is the player playing.
/// \param[in] in the j which is the opposing player.
void Viewer::HadCard(int i, int j){
   cout << "Player " << j << " had the card! +1 to Player " << i << "'s score!" << endl;
}

///This function is used to display a message telling you that they did not have the card.
/// \param[IN] in the i which is the player who did not have the card
void Viewer::NoHadCard(int i){
   cout << "Player " << i << " did not have the card. Go Fish!!" << endl;
}

///Displays the options for GoFish
void Viewer::DisplayGFOptions(){
   cout << "Which card would you like to ask for?" << endl;
}

///Displays the hand of the player given
/// \param[IN] In the player for which to display the hand for
void Viewer::DisplayHand(Player* p){
   vector<Card*> v;
   v = p->GetHand();
   for(int i = 0; i <= p->HandSize()-1; i++){
      cout << (v.at(i))->Value() << " ";
   }
   cout << endl;
}

///Displays the results of the game, by inputting two players, it compares the scores and determines who wins.
/// \param[IN] in the player 1 and player 2;
void Viewer::DisplayResults(vector<Player*> players){
   int win = 0;
   for(int i = 0; i < players.size(); i++){
      cout << "Player " << i+1 << "'s score is: " << players[i]->GetScore() << endl;
      if(players[i]->GetScore() >= win)
	 win = i+1;
   }
   cout << "Player " << win << " is the winner!" << endl;
}


///Displays if a player has two duplicate cards in their hand.
/// \param[IN] in the character which was found.
void Viewer::DuplicatesFound(char c){
   cout << "Duplicate cards (" << c << ") were found! +1 to your score!" << endl;

}
