/*
 * UI.cpp
 *
 *  Created on: Oct 26, 2019
 *      Author: Tim
 */

#include <iostream>
#include <time.h>
using namespace std;
#include "UI.h"

UI::UI() {
	game = new Game();
	number = -1;
	color = -1;

	playerWins = 0;
	computerWins = 0;
}

UI::~UI() {

}

int UI::inputColor() {

	int icolor = -1;
	do {
		cout << "Type '0' for green, '1' for yellow, or '2' for orange: ";
		cin >> icolor;
		if (game->colors[icolor] == 0) {
			cout << "No tiles available  for this color.\n";
		}
	} while ((icolor != 0 && icolor != 1 && icolor != 2)
			|| (game->colors[icolor] == 0));		//initial color choice
	return icolor;
}

int UI::inputNumber() {
	int inumber = -1;
	bool valid = false;

	while (!valid) {
		cout << "Tiles to remove from that color: ";
		cin >> inumber;
		if (inumber > game->colors[color] || inumber <= 0) {
			cout << "u got too much dip on your chip (number invalid). try that again, bucko.\n";
		} else {
			valid = true;
		}
	}

	return inumber;
}

void UI::displayBoard() {
	cout << "- - - - - - - - - - - - - -\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < game->colors[i]; j++) {
			switch (i) {
			case 0:
				cout << "G";
				break;
			case 1:
				cout << "Y";
				break;
			case 2:
				cout << "O";
				break;
			default:
				cout << "you literally can't get here";
			}
		}
		cout << "\n";
	}
	cout << "- - - - - - - - - - - - - -\n";
}

int UI::playerTurn() {
	displayBoard();

	color = inputColor();
	number = inputNumber();
	int ret = -1;

	game->makeMove(color, number); //assumes input is valid. validity checked above.
	if (!(game->colors[0] == 0 && game->colors[1] == 0 && game->colors[2] == 0)){
		ret = computerTurn();
	} else {
		ret = 0;
	}
	return ret;
}

int UI::computerTurn() {
	displayBoard();
	game->makeComputerMove();
	int ret = -1;

	if (!(game->colors[0] == 0 && game->colors[1] == 0 && game->colors[2] == 0)){
		ret =playerTurn();
	} else {
		ret = 1;
	}
	return ret;
}


int UI::runGame() {
	game = new Game();
	int winner = -1;
	srand(time(NULL));
	int turn = rand()%2;
	if (turn){
		cout << "player goes first\n";
		winner = playerTurn();
	} else {
		cout << "computer goes first\n";
		winner = computerTurn();
	}

	if (winner){
		cout << "Computer wins\n";
	} else {
		cout << "Human player wins.\n";
	}

	return winner;
}

void UI::runTournament(int n){
	while(playerWins < n+1 &&
			computerWins < n+1)
	{
		int winner = runGame();
		if (winner==0)
		{
			playerWins++;
		}
		else if (winner==1)
		{
			computerWins++;
		}
		cout << "game over, starting new game\n";
	}

	if(playerWins > computerWins)
	{
		cout<<"HUMAN WINS TOURNAMENT\n";
	}
	else if(playerWins < computerWins)
	{
		cout<<"COMPUTER WINS TOURNAMENT\n";
	}

	cout<<"SCORE:\n";
	cout<<"HUMAN: " << playerWins << "\n";
	cout<<"CPU: " << computerWins << "\n";
}
