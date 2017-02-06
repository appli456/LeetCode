#pragma once
#ifndef __132__SOLUTION_H__
#define __132__SOLUTION_H__
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
	int minCut(string s) {
		int size = s.size();
		vector<vector<bool>> palin(size, vector<bool>(size, false));
		vector<int> result(size + 1, -1);
		for(int i = 0; i < size; ++i)
		{
			palin[i][i] = true;
		}

		for(int i = size - 1; i >= 0; --i)
		{
			result[i] = result[i + 1] + 1;
			for(int j = i + 1; j < size; ++j)
			{
				if (s[i] == s[j])
				{
					if (j == i + 1 || palin[i + 1][j - 1])
					{
						palin[i][j] = true;
						if (j == size - 1)
						{
							result[i] = 0;
						}
						else if(result[i] > result[j + 1] + 1)
						{
							result[i] = result[j + 1] + 1;
						}
					}
				}
			}
		}
		return result[0];
	}
};
#endif
