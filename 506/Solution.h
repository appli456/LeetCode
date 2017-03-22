#pragma once
#ifndef __506__SOLUTION_H__
#define __506__SOLUTION_H__
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
using std::vector;
using std::string;
using std::pair;
class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		vector<pair<int, int>>index_vector(nums.size(), {0, 0});
		vector<string>result(nums.size(), "");
		for(int i = 0; i < nums.size(); ++i)
		{
			index_vector.at(i) = {nums[i], i};
		}
		std::sort(index_vector.begin(), 
			index_vector.end(), 
			[&](pair<int, int>a, pair<int, int>b)
		{
			return a.first > b.first;
		});
		for(int i = 0; i < index_vector.size(); ++i)
		{
			if (i == 0)
			{
				result[index_vector[i].second] = gold;
			}
			else if (i == 1)
			{
				result[index_vector[i].second] = silver;
			}
			else if (i == 2)
			{
				result[index_vector[i].second] = bronze;
			}
			else 
			{
				result[index_vector[i].second] = std::to_string(i + 1);
			}
		}

		return result;
	}

private:
	const string gold = "Gold Medal";
	const string silver = "Silver Medal";
	const string bronze = "Bronze Medal";
};
#endif