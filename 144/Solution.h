#pragma once
#ifndef __144__SOLUTION_H__
#define __144__SOLUTION_H__

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
#include <vector>
#include <stack>
#include "TreeNode.h"
using std::vector;
using std::stack;
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*>traversal_stack;
		vector<int>preorder_traversal;
		if (!root)
		{
			return preorder_traversal;
		}
		// traversal_stack.push(root);
		while (root || !traversal_stack.empty())
		{
			while (root)
			{
				traversal_stack.push(root);
				preorder_traversal.push_back(root->val);
				root = root->left;
			}
			root = traversal_stack.top();
			traversal_stack.pop();
			root = root->right;
		}

		return preorder_traversal;
	}
};
#endif