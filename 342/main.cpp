// 342.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#define START_NUM 1
#define POWER_NUM 4
bool isPowerOfFour(int num) {
	int temp = START_NUM;
	while(temp >= START_NUM && temp <= num)
	{
		if(num == temp)
		{
			return true;
		}
		temp *= POWER_NUM;
	
	}
	return false;
}

int main()
{
	printf("%d\n", isPowerOfFour(4));
	printf("%d\n", isPowerOfFour(16));
	printf("%d\n", isPowerOfFour(64));
	printf("%d\n", isPowerOfFour(2147483648));
	printf("%d\n", isPowerOfFour(0));
	printf("%d\n", isPowerOfFour(100));
	system("pause");
    return 0;
}

