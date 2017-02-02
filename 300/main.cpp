// 300.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Solution.h"

using std::endl;
using std::cout;

int main()
{
	Solution *s = new Solution();

	cout << s->lengthOfLIS(vector<int>({ 10, 9, 2, 5, 3, 7, 101, 18 })) << endl;
	system("pause");
    return 0;
}

