/*****************************************************************************************
Author Cody Crawford
Date March 9, 2018

Game of Cheat

*********************************************************************************/

#include "../include/CheatGame.h"



CheatGame::CheatGame()
{
	deck = new Deck();
	view = new CheatView();
	previousPlayer = nullptr;
	keepPlaying = true;
	currentPlayer = nullptr;
	numberOfPlayers = 0;
	currentExpected = 'A';
}


CheatGame::~CheatGame()
{
	delete deck;
	delete view;
	for(Player* p : players)
	{
		delete p;
	}
	for(Card* c : playPile)
	{
		delete c;
	}
}

void CheatGame::Begin()
{
	//Shuffle 3 time to be sure, real cards get shuffled more the once
	deck->ShuffleDeck();
	deck->ShuffleDeck();
	deck->ShuffleDeck();


	numberOfPlayers = view->GetNumberOfPlayers();

	for(int i = 0; i < numberOfPlayers; i++)
	{
		players.push_back(new Player());
		players[i]->SetName(view->GetName(i));
	}

	currentPlayer = players[0];

	while(deck->CardsLeft() != 0)
	{
		currentPlayer->AddCard(deck->DrawCard());
		SetCurrentPlayer();
	}

	// Set player 0 to start
	currentPlayer = players[0];

	//// DEBUG
	//for(Player* p : players)
	//{
	//	for(Card* c : p->GetHand())
	//		std::cout << c->Value() << " of " << c->Suit() << ", ";
	//	std::cout << "\n";
	//}

	//view->Pause();
	////
}

void CheatGame::Play()
{
	while(keepPlaying)
	{
		currentPlayer->SortHand();
		view->YourTurn(currentPlayer, currentExpected);

		WhatCards();
		previousPlayer = currentPlayer;
		SetCurrentPlayer();


		CheckCheat();

		NextExpected();

		for(Player* p : players)
		{
			if(p->HandSize() == 0)
			{
				view->PlayerHandEmpty(p);
				keepPlaying = false;
			}
		}

	}
	view->Pause();
}

void CheatGame::WhatCards()
{
	bool done = false;
	while(!done)
	{
		Card* addCard = view->ChooseCards(currentPlayer);
		toPlay.push_back(addCard);
		currentPlayer->RemoveCard(addCard);
		done = !view->AddMore();
	}
}

void CheatGame::SetCurrentPlayer()
{
	if(currentPlayer == players[players.size() - 1])
	{
		currentPlayer = players[0];
		return;
	}
	else
	{
		for(size_t p = 0; p < players.size(); p++)
		{
			if(players[p] == currentPlayer)
			{
				currentPlayer = players[p + 1];
				return;
			}
		}
	}
}

void CheatGame::CheckCheat()
{
	//// DEBUG
	//std::cout << "PlayPile:\n";
	//for(Card* c : playPile)
	//{
	//	std::cout << c->Value() << " of " << c->Suit() << ", ";
	//}
	//std::cout << "\ntoPlay:\n";
	//for(Card* c : toPlay)
	//{
	//	std::cout << c->Value() << " of " << c->Suit() << ", ";
	//}
	//std::cout << "\n";
	////

	// Cheat Called?
	bool callCheat = view->CallCheat(currentPlayer, previousPlayer);
	bool cheater = false;

	// Yes, cheat called
	if(callCheat)
	{
		for(Card* c : toPlay) // Check cards for cheating
		{
			if(c->Value() != currentExpected) // Did they cheat?
			{
				cheater = true; // Yes
				break;
			}
			else
			{
				cheater = false; // No
			}
		}

		if(cheater) // Busted for Cheating
		{
			view->Busted(previousPlayer);
			MoveCards(previousPlayer);
		}
		else // Called cheat on player and failed
		{
			view->NotBusted(currentPlayer, previousPlayer);
			MoveCards(currentPlayer);
		}
	}
	else
	{
		for(Card* c : toPlay)
		{
			playPile.push_back(c);
		}
		toPlay.erase(toPlay.begin(), toPlay.end());
	}
}

void CheatGame::MoveCards(Player* player){
	while(!playPile.empty()) // Add play pile to cheat callers hand
	{
		player->AddCard(playPile.back());
		playPile.pop_back();
	}

	while(!toPlay.empty())
	{
		player->AddCard(toPlay.back());
		toPlay.pop_back();
	}
}


void CheatGame::NextExpected()
{
	switch(currentExpected)
	{
		case 'A':
			currentExpected = '2';
			break;
		case '2':
			currentExpected = '3';
			break;
		case '3':
			currentExpected = '4';
			break;
		case '4':
			currentExpected = '5';
			break;
		case '5':
			currentExpected = '6';
			break;
		case '6':
			currentExpected = '7';
			break;
		case '7':
			currentExpected = '8';
			break;
		case '8':
			currentExpected = '9';
			break;
		case '9':
			currentExpected = 'X';
			break;
		case 'X':
			currentExpected = 'J';
			break;
		case 'J':
			currentExpected = 'Q';
			break;
		case 'Q':
			currentExpected = 'K';
			break;
		case 'K':
			currentExpected = 'A';
			break;
		default:
			break;
	}
}
