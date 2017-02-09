#pragma once
#ifndef __231__SOLUTION_H__
#define __231__SOLUTION_H__
class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0)
		{
			return false;
		}
		for(int i = 1; i != 0; i <<= 1)
		{
			if(!(n^i))
			{
				return true;
			}
		}
		return false;
	}
};

#endif