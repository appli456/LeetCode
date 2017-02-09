#pragma once
#ifndef __330__SOLUTION_H__
#define __330__SOLUTION_H__
#include <vector>

class Solution {
public:
	int minPatches(std::vector<int>& nums, int n) {
		int count = 0;
		int size = nums.size();
		for (unsigned sum = 1, i = 0; sum <= n;)
		{
			if (i < size && nums[i] <= sum)
			{
				sum += nums[i];
				i++;
			}
			else
			{
				sum <<= 1;
				++count;
			}
		}
		return count;
	}
};
#endif