#pragma once
#ifndef __199__SOLUTION_H__
#define __199__SOLUTION_H__
#include  <vector>
#include "../lib/TreeNode.h"
using std::vector;
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int>result;
		if(!root)
		{
			return result;
		}
		result.push_back(root->val);
		visit_right_side(root->right, 2, result);
		visit_right_side(root->left, 2, result);
		return result;
	}

private:
	static void visit_right_side(TreeNode *node, int level, vector<int>& container)
	{
		if(!node)
		{
			return;
		}
		if (level > container.size()) 
		{
			container.push_back(node->val);
		}
		visit_right_side(node->right, level + 1, container);
		visit_right_side(node->left, level + 1, container);
	}
};
#endif
