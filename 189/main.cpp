// 189.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Solution.h"

int main()
{
	Solution *s = new Solution();
	s->rotate(vector<int>({ 1,2,3,4,5,6,7 }), 7);
	system("pause");
    return 0;
}

