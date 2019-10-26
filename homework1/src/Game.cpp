/*
 * Game.cpp
 *
 *  Created on: Oct 26, 2019
 *      Author: Tim
 */

#include <iostream>
using namespace std;
#include "Game.h"

Game::Game(){ //EDITTED HERE AGAIN
	green = 3;
	yellow = 5;
	orange = 7;
}

Game::~Game(){

}

void Game::makeMove(int color, int numTake){
	switch (color){
	case 0:
		green-=numTake;//check no neg
		break;
	case 1:
		yellow-=numTake;
		break;
	case 2:
		orange-=numTake;
		break;
	default:
		std::cout << "invalid color choice\n";//check this
	}
}

void Game::makeRandomMove(){

}
void Game::makeCorrectMove(){

}
