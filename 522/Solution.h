#pragma once
#ifndef __522__SOLUTION_H__
#define __522__SOLUTION_H__
#include <vector>
#include <string>
#include <unordered_map>
#include<algorithm>
using std::vector;
using std::string;
using std::unordered_map;
class Solution {
public:
	int findLUSlength(vector<string>& strs) {
		std::sort(strs.begin(), strs.end(), [&](string a, string b)
		{
			return a.size() > b.size() || (a.size() == b.size() && a < b);
		});
		unordered_map<string, int>str_map;
		for(size_t i = 0; i < strs.size(); ++i)
		{
			str_map[strs[i]]++;
		}
		for(size_t i = 0; i < strs.size(); ++i)
		{
			if(str_map[strs[i]] == 1)
			{
				int j = 0;
				for(; j < i; ++j)
				{
					if(has_subsequence(strs[i], strs[j]))
					{
						break;
					}
				}
				if(j == i)
				{
					return strs[i].size();
				}
			}
		}
		return -1;
	}

private:
	static bool has_subsequence(string &a, string &b)
	{
		if(a.size() > b.size())
		{
			return false;
		}

		int i = 0;
		for(int j = 0; i < a.size() && j < b.size(); ++j)
		{
			if(a[i] == b[j])
			{
				i++;
			}
		}

		return i == a.size();
	}
};
#endif