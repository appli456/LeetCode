#pragma once
#ifndef __300_SOLUTION_H__
#define __300_SOLUTION_H__
#include <vector>
using std::vector;

class Solution {
private:
	static int binary_search(vector<int>* contain, int target)
	{
		int left = 0,
			right = contain->size() - 1;

		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (contain->at(mid) < target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}

		return left;
	}
public:
	int lengthOfLIS(vector<int>& nums) {
		unsigned size = nums.size();
		if (size <= 1)
		{
			return size;
		}
		vector <int> result;

		for (auto num: nums)
		{
			if (result.size() == 0 || 
				num > result.back())
			{
				result.push_back(num);
			}
			else
			{
				result.at(binary_search(&result, num)) = num;
			}
		}
		return result.size();
	}
};
#endif