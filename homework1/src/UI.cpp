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

	int color = -1;
	do{
		std::cout << "Type '0' for green, '1' for yellow, or '2' for orange";
		cin >> color;
	}while (color !=0 || color !=1 || color!=2);

	if (color==0)
	{
		if (game.green == 0)
		{
			std::cout << "There are no green tiles available! Do something else.";
			do{
				std::cout << "Type '0' for green, '1' for yellow, or '2' for orange";
				cin >> color;
			}while (color !=0 || color !=1 || color!=2);
		}
	}
	else if (color==1){
		if (game.yellow == 0)
		{
			std::cout << "There are no yellow tiles available! Do something else.";
			do{
				std::cout << "Type '0' for green, '1' for yellow, or '2' for orange";
				cin >> color;
			}while (color !=0 || color !=1 || color!=2);
		}
	}
	else if (color==2){
		if (game.orange == 0)
		{
			std::cout << "There are no orange tiles available! Do something else.";
			do{
				std::cout << "Type '0' for green, '1' for yellow, or '2' for orange";
				cin >> color;
			}while (color !=0 || color !=1 || color!=2);
		}
	}

	return color;
}

