#pragma once
#ifndef __216__SOLUTION_H__
#define __216__SOLUTION_H__
#include <vector>
using std::vector;
class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>>result;
		double check_num = static_cast<double>(n) / k;
		for(int i = 1; i <= check_num; ++i)
		{
			vector<int>container;
			container.push_back(i);
			helper(container, 2, k, n - i, i, result);
			container.pop_back();
		}

		return result;
	}

	static bool helper(vector<int>& container, int floor, int k, int capacity, int front, vector<vector<int>>& result)
	{
		if(floor > k && capacity != 0)
		{
			return false;
		}
		if(floor - 1 == k && capacity == 0)
		{
			if (check(container))
			{
				result.push_back(container);
				container.pop_back();
			}
			// vector<int>temp(container);
			return true;
		}
		for(int i = capacity; i > front; --i)
		{
			container.push_back(i);
			if (helper(container, floor + 1, k, capacity - i, i, result))
			{
				break;
			}
			container.pop_back();
		}
		return false;
	}

	static bool check(const vector<int>& container)
	{
		for(auto it = container.begin(); it != container.end(); ++it)
		{
			if(*it > 9 || *it < 1)
			{
				return false;
			}
		}
		return true;
	}
};
#endif
