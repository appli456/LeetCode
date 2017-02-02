#pragma once
#ifndef __396__SOLUTION_H__
#define __396__SOLUTION_H__
#include <vector>
#include <cmath>
#include <algorithm>

using std::vector;
class Solution {
public:
	int maxRotateFunction(vector<int>& A) {
		int size = A.size();
		if (!size)
		{
			return 0;
		}

		int sum = 0,
			pre = 0;
		// initial data
		for (int i = 0; i < size; ++i)
		{
			sum += A[i];
			pre += i * A[i];
		}

		int max = pre;

		for (int i = size - 1; i > 0; --i)
		{
			pre += (sum - size * A[i]);
			max = pre > max ? pre : max;
		}
		return max;
	}
};
#endif
