/*
 * main.cpp
 *
 *  Created on: Oct 24, 2019
 *      Author: Tim McCarthy & Jarius Thomas
 *
 *
 *      ANSWER TO QUESTION 1 (BONUS)
 *      This game is called nim. It's name was coined by Charles L Bouton in 1901
 *
 */


#include <iostream>
using namespace std;
#include "Game.h"
#include "UI.h"

int main(int argc, char* argv[]){
	UI* aUI = new UI();
	aUI->runTournament(1); // best of 2n+1, where n is input
	return 0;

	//~UI();
}
