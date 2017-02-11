// 334.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Solution.h"
#include <iostream>
using namespace std;
int main()
{
	Solution *s = new Solution();
	cout << s->increasingTriplet(vector<int>({ 2,4,-2,-3 })) << endl;
	system("pause");
    return 0;
}

