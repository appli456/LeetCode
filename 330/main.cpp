// 330.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Solution.h"
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
	Solution *s = new Solution();

	// cout << s->minPatches(vector<int>({ 1, 3 }), 6) << endl;
	// cout << s->minPatches(vector<int>({ 1, 5, 10 }), 20) << endl;
	// cout << s->minPatches(vector<int>({ 1, 2, 2 }), 5) << endl;
	cout << s->minPatches(vector<int>({ 1,2,31,33}), 2147483647) << endl;
	system("pause");
    return 0;
}

