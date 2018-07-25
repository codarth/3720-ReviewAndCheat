/*************************************************************
Author: Zachary Nelson
Date: February 6th 2018

This is the test program to test the Game class. It uses
mock objects for Viewer, Player, Deck, and Card.

**************************************************************/

#include<iostream>
#include"gtest/gtest.h"
#include"gmock/gmock.h"
#include"../include/Game.h"
#include"./MockPlayer.cpp"
#include"./MockViewer.cpp"
#include"./MockCard.cpp"
#include"./MockDeck.cpp"
#include<vector>
#include<fstream>

using namespace std;

#ifndef GAMETEST_H
#define GAMETEST_H

class GameTest : public testing::Test
{
protected:

   GameTest();
   virtual ~GameTest();
};

#endif

GameTest::GameTest(){
    }

GameTest::~GameTest(){
}


using ::testing::AtLeast;
using ::testing::_;

TEST_F(GameTest, DefaultConstructor){
   Game* g = new Game();
   ASSERT_NE(g, nullptr);
   delete g;
}

using ::testing::NiceMock;
using ::testing::Return;

///This function is designed to test an invalid game selection. It should exit the game.
TEST_F(GameTest, InvalidGame){
   Game* g = new Game();
   MockPlayer* p1;
   MockPlayer* p2;
   MockDeck* deck;
   MockViewer* view;

   p1 = new MockPlayer();
   p2 = new MockPlayer();
   deck = new MockDeck();
   view = new MockViewer();

   cout << "Please enter a 2 when the program pauses: " << endl;

   EXPECT_CALL(*view, DisplayTitle());
   g->playGame(p1, p2, deck, view, cin);

   delete g;
   delete p1;
   delete p2;
   delete deck;
   delete view;
}


TEST_F(GameTest, P1PicksCardInP2sHandANDP2picksCardInP1sHand){

   Game* g = new Game();
   NiceMock<MockPlayer>* p1;
   p1 = new NiceMock<MockPlayer>();
   NiceMock<MockPlayer>* p2;
   p2 = new NiceMock<MockPlayer>();
   NiceMock<MockDeck>* deck;
   deck = new NiceMock<MockDeck>();
   NiceMock<MockViewer>* view;
   view = new NiceMock<MockViewer>();

   //Display Title called
   EXPECT_CALL(*view, DisplayTitle())
      .Times(AtLeast(1));

   //ShuffleDeck called
   EXPECT_CALL(*deck, ShuffleDeck());

   //Adding 5 cards to player hands called
   EXPECT_CALL(*p1, AddCard(_))
      .Times(AtLeast(5));

   EXPECT_CALL(*p2, AddCard(_))
      .Times(AtLeast(5));

   EXPECT_CALL(*deck, DrawCard())
      .Times(AtLeast(10));

   //Checking for Duplicates
   EXPECT_CALL(*p1, CheckForDuplicates())
      .Times(AtLeast(1));
   EXPECT_CALL(*p2, CheckForDuplicates())
      .Times(AtLeast(1));

   //Player 1's hand is Displayed
   EXPECT_CALL(*view, DisplayHand(p1))
      .Times(AtLeast(1));

   //Options for player 1's hand are displayed
   EXPECT_CALL(*view, DisplayGFOptions())
      .Times(AtLeast(2));

        //Testing to make sure that it wont do anything when you pick a card not in yoru hand
        ON_CALL(*p1, Search(_))
           .WillByDefault(Return(false));

	EXPECT_CALL(*p1, Search(_))
	   .WillOnce(Return(false))
	   .WillOnce(Return(true))
	   .WillOnce(Return(true));

	//EXPECT_CALL(*view, CardNotInHand());

	//If the card is in the player 2's hand
	ON_CALL(*p2, Search(_))
	   .WillByDefault(Return(true));

	EXPECT_CALL(*p1, RemoveCard(_))
	   .Times(AtLeast(1));
	EXPECT_CALL(*p2, RemoveCard(_))
	   .Times(AtLeast(1));

	//EXPECT_CALL(*view, PlayerHasCard());

	//Since we want the game to keep going to test Player 2's turn, we'll set each hand and the deck size to 5.
	ON_CALL(*p1, HandSize())
	   .WillByDefault(Return(10));

	EXPECT_CALL(*p1, HandSize())
	   .WillOnce(Return(10))
	   .WillOnce(Return(0))
	   .WillOnce(Return(0));

	ON_CALL(*deck, CardsLeft())
	   .WillByDefault(Return(10));

	ON_CALL(*p2, HandSize())
	   .WillByDefault(Return(10));

	//Now for Player 2's turn
	//EXPECT_CALL(*view, PlayerTurn(_));

	EXPECT_CALL(*view, DisplayHand(p2));

	//Testing to make sure that it wont do anything when you pick a card not in yoru hand
        ON_CALL(*p2, Search(_))
           .WillByDefault(Return(false));

	//EXPECT_CALL(*view, CardNotInHand());

	//Now to test if the card Is in the player hand
	ON_CALL(*p2, Search(_))
	   .WillByDefault(Return(true));

	//EXPECT_CALL(*view, PlayerHasCard();

	EXPECT_CALL(*view, DisplayResults(_,_));

	cout << "Each time the program pauses, please enter a 1" << endl;

	g->playGame(p1, p2, deck, view, cin);

   delete p1;
   delete p2;
   delete deck;
   delete view;
   delete g;
}

TEST_F(GameTest, P1PicksCardNotInP2sHand){


   Game* g = new Game();
   NiceMock<MockPlayer>* p1;
   p1 = new NiceMock<MockPlayer>();
   NiceMock<MockPlayer>* p2;
   p2 = new NiceMock<MockPlayer>();
   NiceMock<MockDeck>* deck;
   deck = new NiceMock<MockDeck>();
   NiceMock<MockViewer>* view;
   view = new NiceMock<MockViewer>();
   //ifstream in;

   //Display Title called
   EXPECT_CALL(*view, DisplayTitle())
      .Times(AtLeast(1));

   //in.open("TestingData.dat");
   //cin = in;

   //ShuffleDeck called
   EXPECT_CALL(*deck, ShuffleDeck());

   //Adding 5 cards to player hands called
   EXPECT_CALL(*p1, AddCard(_))
      .Times(AtLeast(5));

   EXPECT_CALL(*p2, AddCard(_))
      .Times(AtLeast(5));

   EXPECT_CALL(*deck, DrawCard())
      .Times(AtLeast(10));

   //Checking for Duplicates
   EXPECT_CALL(*p1, CheckForDuplicates())
      .Times(AtLeast(1));
   EXPECT_CALL(*p2, CheckForDuplicates())
      .Times(AtLeast(1));

   //Player 1's hand is Displayed
   EXPECT_CALL(*view, DisplayHand(p1))
      .Times(AtLeast(1));

   //Options for player 1's hand are displayed
   EXPECT_CALL(*view, DisplayGFOptions());

        //Testing to make sure that it wont do anything when you pick a card not in yoru hand
        ON_CALL(*p1, Search(_))
           .WillByDefault(Return(false));

	//EXPECT_CALL(*view, CardNotInHand());

	//Now to test if the card Is in the player hand
	ON_CALL(*p1, Search(_))
	   .WillByDefault(Return(true));

	//If the card is Not in the player 2's hand
	ON_CALL(*p2, Search(_))
	   .WillByDefault(Return(false));

	//EXPECT_CALL(*view, PlayerDoesntHaveCard());

	//Both Player's hands should be empty for this part of the test.

	ON_CALL(*p1, HandSize())
	   .WillByDefault(Return(0));

	ON_CALL(*p2, HandSize())
	   .WillByDefault(Return(0));

	ON_CALL(*deck, CardsLeft())
	   .WillByDefault(Return(0));

	EXPECT_CALL(*view, DisplayResults(_,_));

	cout << "Each time the program pauses, please enter a 1." << endl;

	g->playGame(p1, p2, deck, view, cin);

   delete p1;
   delete p2;
   delete deck;
   delete view;
   delete g;
}



