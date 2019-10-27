/*
 * UI.cpp
 *
 *  Created on: Oct 26, 2019
 *      Author: Tim
 */

#include <iostream>
using namespace std;
#include "UI.h"

UI::UI() {
	game = Game();
	number = -1;
	color = -1;
}

UI::~UI() {

}

int UI::inputColor() {

	int icolor = -1;
	do {
		cout << "Type '0' for green, '1' for yellow, or '2' for orange\n";
		cin >> icolor;
		if (game.colors[icolor] == 0) {
			cout << "No tiles available  for this color.\n";
		}
	} while ((icolor != 0 && icolor != 1 && icolor != 2)
			|| (game.colors[icolor] == 0));		//initial color choice
	return icolor;
}

int UI::inputNumber() {
	int inumber = -1;
	do {
		cout << "How many tiles do you want to remove ??\n";
		cin >> inumber;
		if (game.colors[color] < inumber) {
			cout << "u got too much dip on your chip (number invalid). try that again, bucko.\n";
		}
	} while ((game.colors[color] < inumber));

	return inumber;
}

void UI::display() {
	cout << "- - - - - - - - - - - - - -\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < game.colors[i]; j++) {
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

void UI::playerInput() {
	color = inputColor();
	number = inputNumber();

	game.makeMove(color, number); //assumes input is valid. validity checked above.
}

void UI::doEverything() {
	while (game.colors[0] != 0 || game.colors[1] != 0 || game.colors[2] != 0) {
		display();
		playerInput();
		if (game.colors[0] == 0 && game.colors[1] == 0 && game.colors[2] == 0) {
			cout << "Human player wins.\n";
			display();
			break;
		}
		display();
		cout << "Computer's turn - ";
		game.makeComputerMove();
		if (game.colors[0] == 0 && game.colors[1] == 0 && game.colors[2] == 0) {
			cout << "Computer wins\n";
			display();
			break;
		}
	}
	cout << "game over";
}
