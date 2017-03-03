#pragma once
#ifndef __467__SOLUTION_H__
#define __467__SOLUTION_H__
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
	int findSubstringInWraproundString(string p) {
		vector<int>key_map(26, 0); // 以某字母结尾的子串数
		int result = 0,
			len = 0; // 子串长

		for (int i = 0; i < p.length(); ++i)
		{
			int cursor = p[i] - 'a';
			if (i > 0 && p[i - 1] != (cursor + 25) % 26 + 'a')
			{
				len = 0;
			}
			++len;
			if (len > key_map[cursor])
			{
				result = result + len - key_map[cursor];
				key_map[cursor] = len;
			}
		}

		return result;
	}
};

#endif
