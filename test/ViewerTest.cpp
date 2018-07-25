/**********************************************************
\Author Zachary Nelson
\Date February 10th 2018

This is a program used to test the Viewer Class.

***********************************************************/

#include<iostream>
#include"gtest/gtest.h"
#include<vector>
#include"../include/Viewer.h"
#include"../include/Player.h"
#include"../include/Card.h"

using namespace std;

#ifndef VIEWERTEST_H
#define VIEWERTEST_H

class ViewerTest: public testing::Test{

protected:
   ViewerTest();
   ~ViewerTest();

};

#endif

ViewerTest::ViewerTest(){
}

ViewerTest::~ViewerTest(){
}

///This Function is designed to test all of the Viewer functions
TEST_F(ViewerTest, TestDisplayTitle){

   Viewer* V;
   V = new Viewer();
   Player* p;
   p = new Player();
   V->DisplayTitle();

   V->EndLine();
   V->CheckingForDupes(1);
   V->DisplayTurn(1);
   V->CardNotInYourHand();
   V->HadCard(1, 2);
   V->NoHadCard(2);
   V->DisplayGFOptions();
   V->DisplayHand(p);
   V->DisplayResults(p, p);
   V->DuplicatesFound('x');


   delete V;
   delete p;
}


