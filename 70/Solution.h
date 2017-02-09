#pragma once
#ifndef __70__SOLUTION_H__
#define __70__SOLUTION_H__
class Solution {
public:
	int climbStairs(int n) {
		return fiboncci(n);
	}

	static unsigned int fiboncci(unsigned int number) {
		unsigned int init_matrix[2][2] = { 0, 1, 1, 1 };
		unsigned int result_matrix[2][2] = { 0, 1, 1, 1 };
		auto matrix_calculate = [&]()
		{
			unsigned int temp_matrix[2][2] = { 0 };
			for (unsigned int i = 0; i < 2; ++i)
			{
				for (unsigned int j = 0; j < 2; ++j)
				{
					unsigned int temp = 0;

					for (unsigned int k = 0; k < 2; ++k)
					{
						temp += result_matrix[i][k] * init_matrix[k][j];
					}
					temp_matrix[i][j] = temp;
				}
			}
			for (unsigned int i = 0; i < 2; ++i)
			{
				for (unsigned int j = 0; j < 2; ++j)
				{
					result_matrix[i][j] = temp_matrix[i][j];
				}
			}

		};

		if (number == 1)
		{
			return 1;
		}

		for (unsigned int i = 0; i < number - 1; ++i)
		{
			matrix_calculate();
		}
		return result_matrix[1][1];
	}
};
#endif