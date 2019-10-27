/*
 * UI.cpp
 *
 *  Created on: Oct 26, 2019
 *      Author: Tim
 */

#include <iostream>
using namespace std;
#include "UI.h"


UI::UI(){ //EDITTED HERE AGAIN
	game = Game();
}


UI::~UI(){

}

int UI::inputColor()
{

	int icolor = -1;
	do{
		std::cout << "Type '0' for green, '1' for yellow, or '2' for orange\n";
		std::cin >> icolor;
		if (game.colors[icolor] == 0)
		{
			std::cout << "No tiles available  for this color.\n";
		}
	}while ((icolor !=0 && icolor !=1 && icolor!=2) && (game.colors[icolor] == 0));		//initial color choice



//	if (color==0)										//handling "invalid input"
//	{
//		if (game.green == 0)
//		{
//			std::cout << "There are no green tiles available! Do something else.";
//			do{
//				std::cout << "Type '0' for green, '1' for yellow, or '2' for orange";
//				cin >> color;
//			}while (color !=0 || color !=1 || color!=2);
//		}
//	}
//	else if (color==1){
//		if (game.yellow == 0)
//		{
//			std::cout << "There are no yellow tiles available! Do something else.";
//			do{
//				std::cout << "Type '0' for green, '1' for yellow, or '2' for orange";
//				cin >> color;
//			}while (color !=0 || color !=1 || color!=2);
//		}
//	}
//	else if (color==2){
//		if (game.orange == 0)
//		{
//			std::cout << "There are no orange tiles available! Do something else.";
//			do{
//				std::cout << "Type '0' for green, '1' for yellow, or '2' for orange";
//				cin >> color;
//			}while (color !=0 || color !=1 || color!=2);
//		}
//	}

	return icolor;
}

int UI::inputNumber()
{
	int inumber = -1;
		do{
			std::cout << "How many tiles do you want to remove ??\n";
			std::cin >> inumber;
			if (game.colors[color] < inumber)
			{
				std::cout << "u got too much dip on your chip. try that again, bucko.\n";
			}
		}while ((game.colors[color] < inumber));


	return inumber;
}

void UI::display() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < game.colors[i]; j++) {
			switch(i){
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
		std::cout << "\n";
	}
}

void UI::playerInput()
{
	color = inputColor();
	number = inputNumber();

	game.makeMove(color, number); //assumes input is valid. validity checked above.

}


void UI::doEverything()
{
	while(game.colors[0] != 0 ||
		game.colors[1] != 0 ||
		game.colors[2] != 0)
	{
		display();
		playerInput();
	}

	std::cout << "somebody wins.";
}
