// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
class Solution {
public:
	int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
		float rate = minutesToTest / minutesToDie + 1;
		int pigs = 0;

		while (pow(rate, pigs) < buckets)
		{
			pigs++;
		}

		return pigs;

	}
};

int main()
{
	Solution* s = new Solution();
	std::cout << (*s).poorPigs(1000, 15, 60) << std::endl;
    return 0;
}

