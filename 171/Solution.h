#pragma once
#ifndef __171__SOLUTION_H__
#define __171__SOLUTION_H__
#include <string>
using std::string;
class Solution {
public:
	int titleToNumber(string s) {
		int res = 0;
		for (auto it = s.begin(); it != s.end(); ++it)
		{
			// int temp = res;
			res = res * 26 + ((*it) - 0x40);
			// res = ((res << 4) + (res << 3) + (res << 1)) + ((*it) - 0x40);
		}
		return res;
	}
};
#endif