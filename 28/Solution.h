#pragma once
#ifndef __28__SOLUTION_H__
#define __28__SOLUTION_H__
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
public:
	int strStr(string haystack, string needle) {
		int hay_len = haystack.length(),
			needle_len = needle.length();
		if (hay_len < needle_len)
		{
			return -1;
		}
		if (!needle_len)
		{
			return 0;
		}
		if (hay_len == needle_len)
		{
			return haystack == needle ? 0 : -1;
		}

		vector<int>mark(hay_len, 0);
		for(int i = 0; i < hay_len - needle_len + 1; ++i)
		{
			for(int j = 0; j < needle_len; ++j)
			{
				if (haystack[i + j] == needle[j])
				{
					if (i + j && j)
					{
						mark[i + j] = mark[i + j - 1] + 1;
					}
					else
					{
						mark[i + j] = 1;
					}
				}
				else
				{
					break;
				}
				if (mark[i + j] == needle_len)
				{
					return i + j - needle_len + 1;
				}
			}
		}
		return -1;
	}
};

#endif