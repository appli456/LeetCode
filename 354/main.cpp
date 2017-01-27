// 354.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Solution.h"
using std::cout;
using std::endl;

int main()
{
	Solution* s = new Solution();
	
	cout << s->maxEnvelopes(vector<pair<int, int>>({{5, 4}, {6, 4}, {6, 7}, {2, 3}})) << endl;
	cout << s->maxEnvelopes(vector<pair<int, int>>({{1, 3}, {3, 5}, {6, 7}, {6, 8}, {8, 4}, {9, 5}})) << endl;
	cout << s->maxEnvelopes(vector < pair<int, int>>({ { 1, 1 }, { 1, 1 }, { 1, 1 } })) << endl;
	cout << s->maxEnvelopes(vector<pair<int, int>>({{30, 50}, {12, 2}, {3, 4}, {12, 15}})) << endl;
	system("pause");
    return 0;
}

