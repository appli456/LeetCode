// 482.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Solution.h"
#include <string>
using std::cout;
using std::endl;
using std::string;

void test_case (string S, int K, Solution* s)
{
	cout << '(' << S << ',' << K << '):' << s->licenseKeyFormatting(S, K) << endl;
}

int main()
{
	Solution *s = new Solution();


	system("pause");
    return 0;
}

