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
	cout << '(' << S << ',' << K << "):" << s->licenseKeyFormatting(S, K) << endl;
}

int main()
{
	Solution *s = new Solution();
	test_case("2-4A0r7-4k", 4, s);
	test_case("2-4A0r7-4k", 3, s);
	test_case("--a-a-a-a--", 2, s);
	system("pause");
    return 0;
}

