#ifndef __384__SOLUTION_H__
#define __384__SOLUTION_H__
#include<vector>
#include <algorithm>
using std::vector;
using std::swap;
class Solution {
public:
	Solution(vector<int> nums):origin(nums), shuffle_container(nums) {

	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return origin;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		for (int i = shuffle_container.size() - 1; i >= 0; --i)
			swap(shuffle_container[i], shuffle_container[rand() % (i + 1)]);
		return shuffle_container;
	}

private:
	vector<int>origin;
	vector<int>shuffle_container;
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(nums);
* vector<int> param_1 = obj.reset();
* vector<int> param_2 = obj.shuffle();
*/
#endif