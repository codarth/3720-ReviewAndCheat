/*****************************************************************************************
Author Cody Crawford
Date March 9, 2018

The View for the game of Cheat

*********************************************************************************/

#include "../include/CheatView.h"
#include <iostream>


CheatView::CheatView()
{
}


CheatView::~CheatView()
{
}

void CheatView::Pause()
{
	char pause;
	std::cout << "Press any key to continue. ";
	std::cin.ignore();
	std::cin.get(pause);
}

int CheatView::GetNumberOfPlayers()
{
	int num;
	std::cout << ("How many players will there be? ");
	std::cin >> num;

	// Atleast 2 players
	while(num < 3)
	{
		std::cout << "There must be at least three players for this game.\nHow many players? ";
		std::cin >> num;
	}

	return num;
}

std::string CheatView::GetName(int i)
{
	std::string name;
	std::cout << "Enter a name for player #" << i << ": ";
	std::cin >> name;
	return name;
}

void CheatView::PrintHand(Player * player)
{
	for(Card* c : player->GetHand())
	{
		std::cout << c->Value() << " of " << c->Suit() << "\n";
	}
}

void CheatView::YourTurn(Player * player, char exp)
{
	std::cout << player->GetName() << ", it is your turn.\n";
	std::cout << "Your hand:\n";
	PrintHand(player);

	std::cout << "The current expected card(s): " << exp << "\n";
}

Card* CheatView::ChooseCards(Player* player)
{
	Card* card;
	char v;
	std::string s;
	bool invalid = true;
	
	while(invalid)
	{
		std::cout << "Choose a card to play (value and suit): ";
		std::cin >> v >> s;

		for(Card* c : player->GetHand())
		{
			if(c->Value() == v && c->Suit() == s)
			{
				card = c;
				return card;
			}
		}

		std::cout << "You do not have that Card.\n";
	}
	return nullptr;
}

bool CheatView::AddMore()
{
	bool more;
	char ans;
	//bool valid = false;

//	while(!valid)
//	{
		std::cout << "Add more cards to play (y, n)? ";
		std::cin >> ans;
		more = YesNo(ans);
	//	if(ans == 'y')
	//	{
	//		more = true;
	//		valid = true;
	//	}
	//	else if(ans == 'n')
	//	{
	//		more = false;
	//		valid = true;
	//	}
	//	else
	//	{
	//		std::cout << "Invalid responce.\n";
	//	}
	//}
	return more;
}

bool CheatView::CallCheat(Player* player, Player* prev)
{
	bool callCheat;
//	bool valid = false;
	char ans;
	std::cout << player->GetName() << ", Would you like to call \'Cheat\' on the " << prev->GetName() << "? (y, n) ";
	std::cin >> ans;

	callCheat = YesNo(ans);
	//if(ans == 'y')
	//{
	//	callCheat = true;
	//	valid = true;
	//}
	//else if(ans == 'n')
	//{
	//	callCheat = false;
	//	valid = true;
	//}
	//else
	//{
	//	std::cout << "Invalid responce.\n";
	//}
	//}
	return callCheat;
}

void CheatView::Busted(Player * player)
{
	std::cout << player->GetName() << " You have been caught cheating. You pick up the Play Pile! \n";
}

void CheatView::NotBusted(Player * player, Player* prev)
{
	std::cout << player->GetName() << ", You must take the Play Pile, " << prev->GetName() << " did not Cheat!\n";
}

bool CheatView::YesNo(char ans)
{
	bool valid = false;
	bool b;
	while(!valid)
	{
		if(ans == 'y' || ans == 'Y')
		{
			b = true;
			valid = true;
		}
		else if(ans == 'n' || ans == 'N')
		{
			b = false;
			valid = true;
		}
		else
		{
			std::cout << "Invalid responce, \'y\' or \'n\' only.\n";
			std::cin >> ans;
		}
	}
	return b;
}

void CheatView::PlayerHandEmpty(Player * player)
{
	std::cout << "\n\nCongratulations " << player->GetName() << ", Your hand is empty. YOU WIN!\n\n";
}
