#pragma once
#ifndef __402__SOLUTION_H__
#define __402__SOLUTION_H__
#include <string>
using std::string;
class Solution {
public:
	string removeKdigits(string num, int k) {
		if(num.length() <= k)
		{
			return "0";
		}
		if(k == 0)
		{
			return num;
		}
		string result(num.length() - k, '0');
		size_t j = 0;
		for(int i = 0; i < num.length() && j < result.length(); ++i)
		{
			if (k > 0) {
				int top = 0;
				int min_index = i;
				while (top + i < num.length() && top < k + 1 && num[min_index] != '0')
				{
					if (num[top + i] < num[min_index])
					{
						min_index = top + i;
					}
					++top;
				}
				k -= min_index - i;
				i = min_index;
				result[j] = num[min_index];
				++j;
			} 
			else
			{
				result[j] = num[i];
				++j;
			}
		}
		j = 0;
		while(result[j] == '0')
		{
			++j;
		}

		return j >= result.length() ? "0" : result.substr(j);
	}
};
#endif