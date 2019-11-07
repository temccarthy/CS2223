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
 * R(n) = 3^(n+1)-1
 * The order of growth is O(3^n)
 *
 *
 * Question 2:
 * Lucas invented the Tower of Hanoi puzzle and the Dot and Boxes game
 *
 * Question 3:
 * The ratio between current and previous calculations is about 1.61, or the golden ratio
 * The order of growth is about O(1.61^n)
 *
 * Question 4:
 * The sum 66 can be created with the greatest number of combinations (1364)
 *
 * 66 is interesting because it's the magic number times 2
 * also execute order 66
 */

#include <iostream>
using namespace std;
#include "main.h"
#include <time.h>

int main(int argc, char* argv[]){
	cout << "Calculating the 30th Lucas Number: " << Lucas(30) << "\n\n";


	cout << "Calculating Lucas Times: \n";
	LucasTiming(45);
	cout << "\n\n";


	cout << "Calculating all 4-element combos whose sum is 33: " << countCombos(33, 4) << "\n\n";

	cout << "Calculating all element combos whose sum is 33: " << countCombosGivenSum(33) << "\n\n";

	cout << "Calculating all combos for given sums: \n";

	for (int i = 0; i< 133; i++){
		int total = countCombosGivenSum(i);
		cout << "for sum " << i << ", there are " << total << " combos\n";
	}
	return 0;
}

long Lucas(int n){
	if (n==0) {
		return 2;
	} else if (n==1) {
		return 1;
	}
	return Lucas(n-1) + Lucas(n-2);
}

void LucasTiming(int n){
	int num;
	clock_t start, end;
	double diff;
	double lastTime=0;
	for (int i = 0; i < n; i++){
		start = clock();
		num = Lucas(i);
		end = clock();
		diff = ((float) end-start)/CLOCKS_PER_SEC;
		cout << i << " - " << num << ", took " << diff << " seconds to calculate, ratio to last is ";
		if (i!=0){
			cout << diff/lastTime << "\n";
			lastTime = diff;
		} else {
			cout << "\n";
		}
		fflush(stdout);
	}
	cout << "done\n";
}

int countCombos(int sum, int nElements){
	int squareArray[16] = {1, 14, 14, 4, 11, 7, 6, 9, 8, 10, 10, 5, 13, 2, 3, 15};
	int accum = 0;

	int i;
	for (i = 0; i < 65536; i++){ // extremely brute force
		int count = 0;

		int tempI = i;
		while (tempI){
			count += tempI & 1;
			tempI = tempI>>1;
		}

		if (count == nElements){
			int sumAccum = 0;

			tempI = i;
			int innerCount = 0;
			while (tempI){
				if (tempI & 1){
					sumAccum += squareArray[innerCount];
					//cout << squareArray[innerCount] << " ";
				}
				tempI = tempI>>1;
				innerCount++;
			}
			//cout << "\n";

			if (sumAccum == sum){
				accum++;
			}
		}

	}
	return accum;
}

int countCombosGivenSum(int sum){
	int accum = 0;
	for (int j = 0; j<=16; j++){
		int totalCombos = countCombos(sum, j);
		accum += totalCombos;
		//cout << "for combinations of "<< j <<" elements, there are " << totalCombos << " that add to " << sum << "\n";
	}
	return accum;
}
