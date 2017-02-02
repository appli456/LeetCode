#pragma once
#ifndef __461__SOLUTION_H__
#define __461__SOLUTION_H__

class Solution {
public:
	int hammingDistance(int x, int y) {
		int xr = x ^ y,
			count = 0;
		while (xr)
		{
			count += xr & 0x1;
			xr = xr >> 0x1;
		}
		return count;

	}
};

#endif