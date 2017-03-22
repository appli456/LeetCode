#pragma once
#ifndef __8__SOLUTION_H__
#define __8__SOLUTION_H__
#include <string>
#include <climits>
using std::string;
class Solution {
public:
	int myAtoi(string str) {
		int64_t result = 0;
		bool if_negative = false;
		str.erase(0, str.find_first_not_of(" "));
		str.erase(str.find_last_not_of(" ") + 1);
		for(int i = 0; i < str.length(); ++i)
		{
			if (i == 0 && str[i] == '-')
			{
				if_negative = true;
			}
			else if (str[i] >= '0' && str[i] <= '9')
			{
				result = result * 10 + str[i] - '0';
			}
			else if (str[i] == '+' && i == 0)
			{
				continue;
			}
			else
			{
				break;
				// return result;
			}

			if (result > INT_MAX)
			{
				return if_negative ? -INT_MAX-1 : INT_MAX;
			}
		}
		
		return if_negative ? -result : result;
	}
};
#endif
