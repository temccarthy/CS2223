/*
 * main.cpp
 *
 *  Created on: Oct 24, 2019
 *      Author: Tim
 */


#include <iostream>
using namespace std;
#include "Game.h"
#include "UI.h"


int main(int argc, char* argv[]){
	UI* aUI = new UI();
	aUI->display();
	//~UI();
}
