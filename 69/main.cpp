// 69.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Solution.h"
using namespace std;
int main()
{
	Solution *s = new Solution();
	cout << s->mySqrt(2) << endl;
	cout << s->mySqrt(4) << endl;
	cout << s->mySqrt(100) << endl;
	cout << s->mySqrt(99) << endl;
	system("pause");
    return 0;
}

