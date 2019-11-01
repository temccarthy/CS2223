/*
 * main.cpp
 *
 *  Created on: Nov 1, 2019
 *      Author: Tim McCarthy and Jarius Thomas
 * Question 1:
 * R(n) = 4R(n−1)−3R(n−2)
 * R(0) = 2
 * R(1) = 8
 * R(2) = 26
 * R(3) = 80
 * R(4) = 242
 *
 * R(n) = 3^n-1
 *
 */

#include <iostream>
using namespace std;
#include "main.h"

int main(int argc, char* argv[]){
	cout << Lucas(25);

	return 0;
}

int Lucas(int n){
	if (n==0) {
		return 2;
	} else if (n==1) {
		return 1;
	}
	return Lucas(n-1) + Lucas(n-2);
}
