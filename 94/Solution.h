#pragma once
#ifndef __94__SOLUTION_H__
#define __94__SOLUTION_H__

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
#include "../lib/TreeNode.h"
using std::vector;
using std::stack;
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*>traversal_stack;
		vector<int>inorder_traversal;
		if (!root)
		{
			return inorder_traversal;
		}
		// traversal_stack.push(root);
		while (root || !traversal_stack.empty())
		{
			while (root)
			{
				traversal_stack.push(root);
				root = root->left;
			}
			root = traversal_stack.top();
			traversal_stack.pop();
			inorder_traversal.push_back(root->val);
			root = root->right;
		}

		return inorder_traversal;
	}
};
#endif