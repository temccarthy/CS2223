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
		if (game.colors[color] == 0)
		{
			std::cout << "No tiles available  for this color.";
		}
	}while ((color !=0 || color !=1 || color!=2) && (game.colors[color] > 0));		//initial color choice



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

	return color;
}

int UI::inputNumber()
{
	int number = -1;
		do{
			std::cout << "How many tiles do you want to remove ??";
			cin >> number;
			if (game.colors[color] < number)
			{
				std::cout << "u got too much dip on your chip. try that again, bucko.";
			}
		}while ((game.colors[color] < number));


	return number;
}

void UI::display()
{

	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<game.colors[i]; j++)
			{
				if(i==0)
				{
					std::cout << "Green";
				}
				if(i==1)
				{
					std::cout << "Y";
				}
				if(i==2)
				{
					std::cout << "O";
				}
			}
	}
}
