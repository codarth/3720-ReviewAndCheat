/*********************************************************************************
\Author Zachary Nelson
\Date February 1st 2018

This is the .cc file for the Player class.

**********************************************************************************
Contributor: Cody Crawford
Date: March 9 2018

Re-factored and added the game "Cheat"
*********************************************************************************/

#include<iostream>
#include"../include/Deck.h"
#include"../include/Card.h"
#include<vector>
#include"../include/Player.h"
#include"../include/Viewer.h"

using namespace std;

///The Default Constructor for a player
Player::Player(){
   //Initializes the player's score to be 0.
   Score = 0;
}

///The Default Destructor for a player
Player::~Player(){
   //Removes the player's hand
	delete &hand;
}

///Returns the player's hand
/// \return the Vector of Card Pointers which is the player's hand
vector<Card*> Player::GetHand(){
      return hand;
}

///Updates the player's score by the value of i
/// \param In the int you wish to change the players score by
void Player::UpdateScore(const int &i){
   Score = Score + i;
}

///Returns the player's hand size
/// \return The size of the player's hand
size_t Player::HandSize(){
   return hand.size();
}

///Adds the card c to the player's hand
/// \param In the Card pointer which you want to add to the player's hand
void Player::AddCard(Card* c){
   hand.push_back(c);
}

///Searches the player's hand for a card that matches the char c
/// \param In the char to match with the player's hand
/// \return a bool value, true if it is in the players hand, false if not
bool Player::Search(char c){
   for(unsigned int i = 0; i < hand.size(); i++){
      if((hand.at(i)->Value() == c))
	 return true;
   }
   return false;
}


///Removes the card from the player's hand
/// \param In the card value which is to be removed from the player's hand
void Player::RemoveCard(char c){
   for(unsigned int i = 0; i < hand.size(); i++){
      if((hand.at(i)->Value() == c)){
	 hand.erase(hand.begin() + i);
	 break;
      }
   }
}

void Player::RemoveCard(Card* card)
{
	// Get all cards matching the given card
	//std::vector<Card*> cards;
	//size_t i = 0;
	//while(i < hand.size())
	//{
	//	if(hand[i]->Value() == card->Value() && hand[i]->Suit() == card->Suit())
	//	{
	//		Card* c = hand.at(i);
	//		cards.push_back(c);
	//	}
	//	i++;
	//}

	// Remove all the given cards from the plaers hand
	// I did it this way to avoid the error then removing the
	// card from the hand and changing the size of the
	// hand.size int the while loop
	std::vector<Card*> tempHand;
	for(Card* c : hand)
	{
		if(card->Value() != c->Value() || card->Suit() != c->Suit())
		{
			tempHand.push_back(c);
		}
	}
	hand = tempHand;

}

///Checks the player's hand for duplicates. If the player has duplicate cards, remove
///them, and call the viewer function to alert the player. Also update the player's score
///by 1.
char Player::CheckForDuplicates(){

   //Viewer* view;
   //view = new Viewer();

   for(unsigned int i = 0; i < hand.size(); i++){

      for(unsigned int j = 0; j < hand.size(); j++){

	 if(hand[i]->IsEqual(hand[j]->Value()) && i != j){
	    //view->DuplicatesFound(hand[i]->Value());
	    Score++;
	    char returnable = hand[i]->Value();
	    RemoveCard(hand[i]->Value());
	    RemoveCard(hand[j]->Value());
	    return returnable;
	    }
      }
   }
   //If no matches are found, return the character '0'
   return '0';
}

///Returns the player's score
/// \return the players score
int Player::GetScore(){
   return Score;
}

void Player::SortHand()
{
	std::sort(hand.begin(), hand.end(), [](Card* value1, Card* value2)
	{
		return value1->Value() < value2->Value();
	});
}
