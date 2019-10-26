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
	void display();
	void playerInput();
private:
	Game game;
	int inputColor();
	int inputNumber();
	bool inputValid(int color, int number);
};

#endif /* UI_H_ */
