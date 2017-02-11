#pragma once
#ifndef __334__SOLUTION_H__
#define __334__SOLUTION_H__

#include <vector>
#include <limits>
using std::vector;
using std::numeric_limits;
class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int size = nums.size();
		if(size < 3)
		{
			return false;
		}
		int min = nums.front(),
			max = numeric_limits<int>::max();
		for(auto num: nums)
		{
			if (num <= min)
			{
				min = num;
			}
			else if (num < max)
			{
				max = num;
			}
			else if (num > max)
			{
				return true;
			}
		}
		return false;
	}
};
#endif
