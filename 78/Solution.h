#pragma once
#ifndef __78__SOLUTION_H__
#define __78__SOLUTION_H__
#include <vector>
#include <string>
#include <cmath>
using std::vector;
using std::string;
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int size = nums.size();
		string mark_str(size, '0');
		vector<vector<int>>subsets;
		int subset_num = pow(2, size);
		for (int i = 0; i < subset_num; ++i)
		{
			vector<int>this_set;
			for(int j = 0; j < size; ++j)
			{
				if (mark_str[j] == '1')
				{
					this_set.push_back(nums[j]);
				}
			}
			subsets.push_back(this_set);
			mark_str = add_binary_str(mark_str);
		}
		return subsets;
	}

	static string add_binary_str(string str)
	{
		int size = str.size();
		int add_num = 1;
		for(int i = size - 1; i >= 0 && add_num; --i)
		{
			if (str[i] == '0')
			{
				str[i] = '1';
				add_num = 0;
			}
			else if (str[i] == '1')
			{
				str[i] = '0';
			}
			else
			{
				break;
			}
		}
		return str;
	}
};
#endif