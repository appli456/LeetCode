#pragma once
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
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*>traversal_stack;
		vector<int>postorder_traversal;
		if (!root)
		{
			return postorder_traversal;
		}
		traversal(root->left, postorder_traversal);
		traversal(root->right, postorder_traversal);
		postorder_traversal.push_back(root->val);
		return postorder_traversal;
	}

	void traversal(TreeNode* node, vector<int>& postorder_traversal)
	{
		if (!node)
		{
			return;
		}

		traversal(node->left, postorder_traversal);
		traversal(node->right, postorder_traversal);
		postorder_traversal.push_back(node->val);
	}
};