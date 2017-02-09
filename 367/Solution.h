#pragma once
#ifndef __367__SOLUTION_H__
#define __367__SOLUTION_H__
#include <cmath>
#include <cstdint>

class Solution {
public:
	bool isPerfectSquare(int num) {
		int root = sqrt(num);
		// int root = floor_sqrt(root);
		return root * root == num && num >= 1;
	}
};
#endif