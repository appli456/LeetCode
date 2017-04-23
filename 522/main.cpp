// 522.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Solution.h"

int main()
{
	Solution *s = new Solution();
	s->findLUSlength(vector<string>({ "aba", "cec" }));
	system("pause");
    return 0;
}

