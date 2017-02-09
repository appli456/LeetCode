// 231.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Solution.h"
#include <iostream>
using namespace std;
int main()
{
	Solution *s = new Solution();
	cout << s->isPowerOfTwo(1) << endl;
	cout << s->isPowerOfTwo(3) << endl;
	system("pause");
    return 0;
}

