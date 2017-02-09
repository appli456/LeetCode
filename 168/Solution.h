#pragma once
#ifndef __168__SOLUTION_H__
#define __168__SOLUTION_H__
#include <string>
#include <algorithm>
using std::string;
class Solution 
{
public:
	string convertToTitle(int n) {
		string result;
		while (n)
		{
			result.push_back(static_cast<char>((n - 1) % 26 + 0x41));
			n = (n - 1) / 26;
		}
		//int size = result.size();
		//for (int i = 0, j = size - 1; i < j; ++i, --j)
		//{
		//	std::swap(result[i], result[j]);
		//};
		std::reverse(result.begin(), result.end());
		return result;
	}
};

#endif