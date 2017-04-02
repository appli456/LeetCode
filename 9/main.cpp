// 9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

bool isPalindrome(int x) {
	if(x < 0)
	{
		return false;
	}
	int sum = 0;
	int temp = x;
	while(temp >= 10)
	{
		sum = sum * 10 + temp % 10;
		temp /= 10;
	}
	return sum == x / 10 && temp == x % 10;
}

int main()
{
    return 0;
}

