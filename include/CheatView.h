/*****************************************************************************************
Author Cody Crawford
Date March 9, 2018

The View for the game of Cheat

*********************************************************************************/

#ifndef CHEATVIEW_H
#define CHEATVIEW_H

#include "Player.h"

class CheatView
{
public:
	CheatView();
	virtual ~CheatView();

	void Pause();
	int GetNumberOfPlayers();
	std::string GetName(int i);
	void PrintHand(Player* player);
	void YourTurn(Player* player, char exp);
	Card* ChooseCards(Player* player);
	bool AddMore();
	bool CallCheat(Player* player, Player* prev);
	void Busted(Player* player);
	void NotBusted(Player* player, Player* prev);
	bool YesNo(char ans);
	void PlayerHandEmpty(Player* player);
};

#endif // !CHEATVIEW_H

