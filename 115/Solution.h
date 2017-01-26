#pragma once
#ifndef __115_SOLUTION_H__
#define __115_SOLUTION_H__
#include <string>
#include <vector>
using std::string;
using std::vector;
class Solution {
public:
	int numDistinct(string s, string t) {
		size_t s_len = s.length(),
			t_len = t.length();
		if (s_len < t_len)
		{
			return 0;
		}

		// initial dynamic matrix
		vector<vector<size_t>>matrix(t_len + 1, vector<size_t>(s_len + 1, 0));
		matrix[0][0] = 1;
		for (size_t i = 1; i < s_len + 1; ++i)
		{
			matrix[0][i] = 1;
		}
		for (size_t i = 1; i < t_len + 1; ++i)
		{
			matrix[i][0] = 0;
		}

		for (size_t i = 1; i < t_len + 1; ++i)
		{
			for (size_t j = 1; j < s_len + 1; ++j)
			{
				// copy data from previous column in the same row
				matrix[i][j] = matrix[i][j - 1];

				// equal character 
				if (s[j - 1] == t[i - 1])
				{
					// add number from previous in diagonal
					matrix[i][j] = matrix[i][j] + matrix[i - 1][j - 1];
				}
			}
		}

		return matrix[t_len][s_len];

	}
};
#endif
