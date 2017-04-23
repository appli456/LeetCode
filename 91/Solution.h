#pragma once
#ifndef __91__SOLUTION_H__
#define __91__SOLUTION_H__
#include <string>
#include <cmath>
using std::string;
class Solution {
public:
	int numDecodings(string s) {
		if(!s.length() || s.front() == '0')
		{
			return 0;
		}
		
		int r1 = 1, r2 = 1;
		for(int i = 1; i < s.length(); ++i)
		{
			if(s[i] == '0')
			{
				r1 = 0;
			}
			if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6'))
			{
				r1 = r1 + r2;
				r2 = r1 - r2;
			}
			else
			{
				r2 = r1;
			}
		}
		return r1;
	}
};
#endif