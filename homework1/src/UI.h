/*
 * UI.h
 *
 *  Created on: Oct 26, 2019
 *      Author: Tim
 */

#ifndef UI_H_
#define UI_H_
#include "Game.h"

class UI{
public:
	UI();
	virtual ~UI();
	int number, color;
	void displayBoard();
	int playerTurn();
	int computerTurn();
	int runGame();
	void runTournament(int n);
private:
	Game* game;
	int inputColor();
	int inputNumber();
	bool inputValid(int color, int number);
	int playerWins, computerWins;
};

#endif /* UI_H_ */
