#pragma once
#ifndef __189__SOLUTION_H__
#define __189__SOLUTION_H__
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int size = nums.size();
		k = k % size;
		if (!k)
		{
			return;
		}
		vector<int>result;
		for(int i = size - k; i < size; ++i)
		{
			result.push_back(nums[i]);
		}
		for(int i = 0; i < size - k; ++i)
		{
			result.push_back(nums[i]);
		}
		nums = result;

		//for(auto it: nums)
		//{
		//	cout << it << '\t';
		//}
		//cout << endl;
	}
};

#endif
