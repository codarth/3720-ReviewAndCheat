/***********************************************************
Author: Zachary Nelson
Date: February 6th 2018

This is the MockViewer class, which is a mock of the Viewer class.
It is used to test the Game class.

************************************************************/

#include<iostream>
#include "gmock/gmock.h"
#include "../include/Player.h"
#include "../include/Viewer.h"

using namespace std;

#ifndef MOCKVIEWER_H
#define MOCKVIEWER_H

class MockViewer: public Viewer {
   public:

   MOCK_METHOD1(DisplayHand, void(Player* p));
   MOCK_METHOD0(DisplayGFOptions, void());
   MOCK_METHOD0(DisplayTitle, void());
   MOCK_METHOD1(DuplicatesFound, void(char c));
   MOCK_METHOD2(DisplayResults, void(Player* p1, Player* p2));

};

#endif
