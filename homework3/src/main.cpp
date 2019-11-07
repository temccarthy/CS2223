/*
 * main.cpp
 *
 *  Created on: Nov 7, 2019
 *      Author: Tim McCarthy and Jarius Thomas
 */
#include <iostream>
#include <bool.h>
using namespace std;
int main(int argc, char* argv[]){

	char[256] str1 = "hannah";
	char[256] str2 = "baseball";

	cout << "Is hannah a palindrome?" << palindromecheck(str1);
	cout << "Is baseball a palindrome?" << palindromecheck(str2);
	return 0;
}

bool palindromecheck(char[] str){
	bool done = false;
	int i = -1;
	while (!done)
	{
		i++;
		if(!char[i])  //equals zero
		{
			done = true;
		}
	}

	int halfLength = i/2;

	for(int x = 0; x<halfLength; x++)
	{
		if(char[x] != char[i-x])
			return false;
	}

	return true;

}

// int easyinversioncount()

// int fastinversioncount()

// void BRGC(int n) (printout)
