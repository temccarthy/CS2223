/*
 * Game.cpp
 *
 *  Created on: Oct 26, 2019
 *      Author: Tim
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdbool>
using namespace std;
#include "Game.h"


Game::Game(){
	colors = {3,5,7};
}

Game::~Game(){
}

void Game::makeMove(int colorIndex, int numTake){
	colors[colorIndex] -= numTake;
}

void Game::makeRandomMove(){
	srand(time(NULL));
	int index = -1;
	bool done = true;
	while (!done){
		index = rand()%3;
		if (colors[index] != 0){
			int numLeft = colors[index];
			int numTake =
			makeMove(index, numTake);
			done = true;
		}
	}



}

void Game::makeComputerMove(){
	int sum = findNimSum();
	int index;
	if (sum==0){
		index = -1;
	} else {

	}
	/*
	 *int sum = finsnimsum()
	 *int index = determinemove(sum)
	 *if index == -1{
	 * random
	 *}else {
	 * makemove(index, sum)
	 *}
	 *
	 *
	 *def:
	 *if sum == 0 {
	 *  return -1       //for random move
	 *  }
	 *else {
	 *for(.......)
	 *for(.......) {
	 *  if (num sum XOR  value[i] == nim sum)
	 *  	{return i
	 *  }
	 *  return -1     // if the for loop doesnt return a valid move, return -1 for a random move
	 *enddef
	 *
	 */
}

int Game::findNimSum(){
	return orange^yellow^green;
}
