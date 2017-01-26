#pragma once

#ifndef __458__SOLUTION_H__
#define __458__SOLUTION_H__

#include <cmath>
class Solution {
public:
	int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
		float rate = minutesToTest / minutesToDie + 1;
		int pigs = 0;

		while (pow(rate, pigs) < buckets)
		{
			pigs++;
		}

		return pigs;

	}
};
#endif
