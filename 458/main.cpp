// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Solution.h"
int main()
{
	Solution* s = new Solution();
	std::cout << (*s).poorPigs(1000, 15, 60) << std::endl;
    return 0;
}

