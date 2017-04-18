#pragma once
#ifndef __404__SOLUTION_H__
#define __404__SOLUTION_H__
#include "../lib/TreeNode.h"
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if(!root)
		{
			return 0;
		}

		int sum = 0;
		
		sum += traval(root->left, true);
		sum += traval(root->right, false);

		return sum;
	}

	int traval(TreeNode *root, bool is_left)
	{
		int sum = 0;
		if(!root)
		{
			return 0;
		}
		if(is_left && !root->left && !root->right)
		{
			sum += root->val;
		}
		sum += traval(root->left, true);
		sum += traval(root->right, false);
		return sum;
	}
};
#endif
