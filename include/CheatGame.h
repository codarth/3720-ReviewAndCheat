/*****************************************************************************************
Author Cody Crawford
Date March 9, 2018

Game of Cheat

*********************************************************************************/

#ifndef CHEATGAME_H
#define CHEATGAME_H

#include <vector>
#include "Player.h"
#include "Deck.h"
#include "CheatView.h"
#include "Builder.h"

class CheatGame
{
public:
	CheatGame();
	virtual ~CheatGame();

	void Begin();
	void Play();
	void WhatCards();
	void SetCurrentPlayer();
	void CheckCheat();
	void MoveCards(Player * player);
	void NextExpected();


private:
	std::vector<Player*> players;
	Player* currentPlayer;
	Deck* deck;
	CheatView* view;
	std::vector<Card*> playPile;
	std::vector<Card*> toPlay;
	Player* previousPlayer;
	bool keepPlaying;
	int numberOfPlayers;
	char currentExpected;
};

#endif