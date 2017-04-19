#pragma once
#ifndef __81__SOLUTION_H__
#define __81__SOLUTION_H__
#include <vector>
using std::vector;
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if(!nums.size())
		{
			return false;
		}
		int left = 0;
		int right = nums.size() - 1;
		while(left < right)
		{
			int mid = (left + right) / 2;
			if(nums[mid] == target)
			{
				return true;
			}
			if (nums[mid] > nums[right])
			{
				if(nums[mid] > target && nums[left] <= target)
				{
					right = mid;
				}
				else
				{
					left = mid + 1;
				}
			}
			else if(nums[mid] < nums[right])
			{
				if(nums[mid] < target && nums[right] >= target)
				{
					left = mid + 1;
				}
				else
				{
					right = mid;
				}
			}
			else
			{
				right--;
			}
		}

		return nums[left] == target;
	}
};
#endif