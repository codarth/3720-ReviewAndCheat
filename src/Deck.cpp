/***********************************************************************************************************
\Author Zachary Nelson
\Date February 1st 2018

This is the .cc file for the Deck class.

**********************************************************************************
Contributor: Cody Crawford
Date: March 9 2018

Re-factored and added the game "Cheat"
*********************************************************************************/

#include<iostream>
#include"../include/Card.h"
#include"../include/Builder.h"
#include<vector>
#include"../include/Deck.h"
#include<algorithm>
#include <time.h>

using namespace std;

///Creates a new builder which then builds the deck.
Deck::Deck(){
   buildCards = new Builder();
   Cards = buildCards->SpawnDeck();
}

///Deletes the builder
Deck::~Deck(){
   delete buildCards;
}

///Draws a card from the deck, and as such removes it from the vector of cards.
/// \return returns the drawn card
Card* Deck::DrawCard(){
   Card* toDraw; //new Card('X', "0");
   toDraw = Cards.at(Cards.size()-1);
   Cards.pop_back();
   return toDraw;
}

///Shuffles the deck
void Deck::ShuffleDeck(){
   // Garbage shuffle, psudo-shuffle
	//random_shuffle(Cards.begin(), Cards.end());

	//Create 6 different piles
	std::vector<Card*> p1;
	std::vector<Card*> p2;
	std::vector<Card*> p3;
	std::vector<Card*> p4;
	std::vector<Card*> p5;
	std::vector<Card*> p6;

	// Counter
	int i = 0;

	// Deal Cards to the 6 piles
	for(Card* c : Cards)
	{
		switch(i)
		{
			case 0:
			{
				p1.push_back(c); i++; break;
			}
			case 1:
			{
				p2.push_back(c); i++; break;
			}
			case 2:
			{
				p3.push_back(c); i++; break;
			}
			case 3:
			{
				p4.push_back(c); i++; break;
			}
			case 4:
			{
				p5.push_back(c); i++; break;
			}
			case 5:
			{
				p6.push_back(c); i = 0; break;
			}
			default:
				i = 0;
		}
	}

	// Clear the deck
	Cards.erase(Cards.begin(), Cards.end());

	// Take a random card from the 6 piles and add it to the deck
	while(!p1.empty() || !p2.empty() || !p3.empty() || !p4.empty() || !p5.empty() || !p6.empty())
	{
		if(!p1.empty())
		{
			int c = (rand() + time(0)) % p1.size();
			Cards.push_back(p1[c]);
			p1.erase(p1.begin() + c);
		}
		if(!p2.empty())
		{
			int c = (rand() + time(0)) % p2.size();
			Cards.push_back(p2[c]);
			p2.erase(p2.begin() + c);
		}
		if(!p3.empty())
		{
			int c = (rand() + time(0)) % p3.size();
			Cards.push_back(p3[c]);
			p3.erase(p3.begin() + c);
		}
		if(!p4.empty())
		{
			int c = (rand() + time(0)) % p4.size();
			Cards.push_back(p4[c]);
			p4.erase(p4.begin() + c);
		}
		if(!p5.empty())
		{
			int c = (rand() + time(0)) % p5.size();
			Cards.push_back(p5[c]);
			p5.erase(p5.begin() + c);
		}
		if(!p6.empty())
		{
			int c = (rand() + time(0)) % p6.size();
			Cards.push_back(p6[c]);
			p6.erase(p6.begin() + c);
		}
	}
}

///Returns and int with the amount of cards left in the deck.
/// \return the amount of cards left as an int
int Deck::CardsLeft(){
   return Cards.size();
}

