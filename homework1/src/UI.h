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
private:
	Game game;
	int inputColor();
	int inputNumber();
	void display();
	bool inputValid(int color, int number);
};

#endif /* UI_H_ */
