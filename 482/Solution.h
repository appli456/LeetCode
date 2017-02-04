#pragma once
#ifndef __482__SOLUTION_H__
#define __482__SOLUTION_H__
#include <string>

using std::string;


class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		string result;
		int len = S.length();
		int flag = -1;
		for (int i = len - 1; i >= 0; --i)
		{
			if (S[i] != '-')
			{
				flag++;
				if (!(flag % K) && flag != 0)
				{
					result = "-" + result;
				}
				
				result = static_cast<char>(toupper(S[i])) + result;
			}
		}

		return result;
	}
};

#endif