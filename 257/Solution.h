#pragma once
#ifndef __257__SOLUTION_H__
#define __257__SOLUTION_H__
#include <vector>
#include <string>
#include <sstream>
#include "../lib/TreeNode.h"
using std::vector;
using std::string;
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
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string>path;
		if (!root)
		{
			return path;
		}
		preorder_traveral(root, &path, std::to_string(root->val));
		return path;
	}

	void preorder_traveral(TreeNode* node, vector<string>* const path_container, string path)
	{
		if (!node->left && !node->right)
		{
			path_container->push_back(path);
			return;
		}

		if (node->left)
		{
			preorder_traveral(node->left, path_container, path + this->link + std::to_string(node->left->val));
		}
		if (node->right)
		{
			preorder_traveral(node->right, path_container, path + this->link + std::to_string(node->right->val));
		}
	}

private:
	const string link = "->";

};
#endif