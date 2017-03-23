#pragma once
#ifndef __16__SOLUTION_H__
#define __16__SOLUTION_H__
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <functional>
using std::vector;
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() <= 3)
		{
			return std::accumulate(nums.begin(), nums.end(), 0);
		}
		int cloest = std::accumulate(nums.begin(), nums.begin() + 3, 0);
		int diff = abs(cloest - target);
		if(cloest == target)
		{
			return cloest;
		}
		std::sort(nums.begin(), nums.end());
		for(int i = 0; i < nums.size() - 2; ++i)
		{
			int start = i + 1;
			int end = nums.size() - 1;
			while(start < end)
			{
				int sum = nums[start] + nums[end] + nums[i];
				int temp_diff = abs(sum - target);
				if(temp_diff < diff)
				{
					diff = temp_diff;
					cloest = sum;
					if (cloest == target)
					{
						return cloest;
					}
				}
				if(sum < target)
				{
					start++;
				}
				else
				{
					end--;
				}
			}
		}

		return cloest;
	}
};
#endif