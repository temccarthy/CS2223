/*
 * main.cpp
 *
 *  Created on: Oct 24, 2019
 *      Author: Tim McCarthy & Jarius Thomas
 */


#include <iostream>
using namespace std;
#include "Game.h"
#include "UI.h"

int main(int argc, char* argv[]){
	UI* aUI = new UI();
	aUI->doEverything();
	return 0;

	//~UI();
}
