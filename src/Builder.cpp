/**************************************************************************************************************
\Author: Zachary Nelson
\Date: February 1st 2018

This is the .cc file for the builder class.

**********************************************************************************
Contributor: Cody Crawford
Date: March 9 2018

Re-factored and added the game "Cheat"
*********************************************************************************/

#include"../include/Builder.h"

using namespace std;

Builder::Builder(){
};

//Deletes all the cards.
Builder::~Builder(){
};


///Creates all of the cards based on hard coding.
/// \return A vector of Card pointers with all of the spawned cards
vector<Card*> Builder::SpawnDeck(){
	    // Face values
	    char faces[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K'};
	    // Suits
	    string suits[] = {"C","D","H","S"};

    for(char f : faces){
        for(std::string s : suits){
            cards.push_back(new Card(f, s));
        }
    }

   return cards;
}
