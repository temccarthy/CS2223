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
 * Question 2:
 * ******Lucas is known for***********
 *
 */

#include <iostream>
using namespace std;
#include "main.h"
#include <time.h>

int main(int argc, char* argv[]){
	LucasTiming(30);
	return 0;
}

long Lucas(int n){
	if (n==0) {
		return 2;
	} else if (n==1) {
		return 8;
	}
	return 4*Lucas(n-1) - 3*Lucas(n-2);
}

void LucasTiming(int n){
	int num;
	clock_t start, end;
	double diff;
	for (int i = 0; i < n; i++){
		start = clock();
		num = Lucas(i);
		end = clock();
		diff = ((float) end-start)/CLOCKS_PER_SEC;
		cout << i << " - " << num << " took " << diff << " seconds to calculate\n";
	}

}
