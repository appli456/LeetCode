#pragma once
#ifndef __69__SOLUTION_H__
#define __69__SOLUTION_H__
#include <cmath>
class Solution {
public:
	int mySqrt(int x) {
		double ans = x;
		const double delta = 0.0001;
		while (fabs(pow(ans, 2) - x) > delta) {
			ans = (ans + x / ans) / 2;
		}
		return ans;

	}
};

#endif
