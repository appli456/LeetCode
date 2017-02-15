#pragma once
#ifndef __476__SOLUTION_H__
#define __476__SOLUTION_H__
#include <vector>
using std::vector;
constexpr int MAX_INT = ~(1 << 31);
class Solution {
public:
	int findComplement(int num) {
		if (num == 0 || num == 1 || num == MAX_INT)
		{
			return 0;
		}
		int count = 0;
		vector<unsigned int>power_of_2;
		for (int i = 0; i < 32; ++i)
		{
			power_of_2.push_back(1 << i);
		}
		int bits = 0;
		for (int i = 0; i < 32; ++i)
		{
			if (num < power_of_2[i])
			{
				bits = i;
				break;
			}
			else if (num == power_of_2[i])
			{
				bits = i + 1;
				break;
			}
		}
		unsigned int sum = (this->sum(&power_of_2, bits) + num);
		return ~sum;
	}
	static unsigned int sum (vector<unsigned int>* container, int end)
	{
		int size = container->size();
		unsigned int sum = 0;
		for (int i = size - 1; i >= end; --i)
		{
			sum += container->at(i);
		}
		return sum;
	}
};

#endif