#pragma once
#ifndef __477__SOLUTION_H__
#define __477__SOLUTION_H__
#define START 1
#include <vector>
using std::vector;
class Solution {
public:
	int totalHammingDistance(vector<int>& nums) {
		if(nums.size() < 2)
		{
			return 0;
		}
		int distance = 0;
		for (int k = 0; k < 32; ++k) 
		{
			int bit_distance = 0;
			for (int i = 0; i < nums.size(); ++i)
			{
				bit_distance += (nums[i] >> k) & 1;
			}
			distance += bit_distance * (nums.size() - bit_distance);
		}
		return distance;
	}
};

#endif