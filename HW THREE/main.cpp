/*
 * main.cpp
 *
 *  Created on: Nov 7, 2019
 *      Author: Tim McCarthy and Jarius Thomas
 */
#include <iostream>
#include <stdbool.h>
#include "main.h"
using namespace std;


bool palindromecheck(char str[]){
	bool done = false;
	int i = -1;
	while (!done)
	{
		i++;
		if(!str[i])  //equals zero
		{
			done = true;
		}
	}

	int halfLength = i/2;
	//cout<< "\n" << i <<"\n";			//output length

	for(int x = 0; x<halfLength; x++)
	{
		if(str[x] != str[i-x-1])
			return false;
	}

	return true;

}


int main(int argc, char* argv[]){

	char str1[256]  = "hannah";
	char str2[256]  = "baseball";

	cout << "Is hannah a palindrome?" << palindromecheck(str1) <<"\n";
	cout << "Is baseball a palindrome?" << palindromecheck(str2) << "\n";

	int array[5] ={1,2,5,4,3};

	cout<< easyinversioncount(array, 5) << " inversions.\n";
	return 0;
}

int easyinversioncount(int arr[], int size)
{
	int counter = 0;

	for(int i = 0; i < size; i++){
		for(int j = i+1; j<size; j++){
			if(arr[i] > arr[j])
				counter++;
		}
	}

	return counter;
}

int fastinversioncount()
{
return 42069;
}

void BRGC(int n){

}
