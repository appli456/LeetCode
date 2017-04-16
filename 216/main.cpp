// 216.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Solution.h"

void print(vector<vector<int>>container)
{
	for(int i = 0; i < container.size(); ++i)
	{
		for(int j = 0; j < container[i].size(); ++j)
		{
			std::cout << container[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	Solution *s = new Solution();
	print(s->combinationSum3(2, 18));
	print(s->combinationSum3(3, 9));
	system("pause");
    return 0;
}

