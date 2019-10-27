/*
 * Game.cpp
 *
 *  Created on: Oct 26, 2019
 *      Author: Tim
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdbool.h>
using namespace std;
#include "Game.h"


Game::Game(){
	colors[0] = 3;
	colors[1] = 5;
	colors[2] = 7;
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
	int numTake = -1;

	while (!done){
		index = rand()%3;
		if (colors[index] != 0){
			int numLeft = colors[index];
			numTake = rand()%(numLeft-1)+1;
			makeMove(index, numTake);
			done = true;
		}
	}
	cout << "random move: removing " << numTake << " from " << index << "\n";
}

void Game::makeComputerMove(){
	int sum = findNimSum();
	int index=-1;
	if (sum==0){
		index = -1;
	} else {
		for (int i = 0; i<3; i++){
			if (sum^colors[i == sum]){
				index = i;
			}
		}
	}

	if (index == -1){
		makeRandomMove();
	} else {
		makeMove(index, sum);
		cout << "removing " << sum << " from " << index << "\n";
	}
}

int Game::findNimSum(){
	cout << "nim sum is " << colors[0] <<"^"<< colors[1] <<"^"<< colors[2] <<"\n";
	return colors[0]^colors[1]^colors[2];
}
