// 396.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Solution.h"

using std::cout;
using std::endl;
int main()
{
	Solution *s = new Solution();
	cout << s->maxRotateFunction(vector<int>({ 4, 3, 2, 6 })) << endl;
	system("pause");
    return 0;
}

