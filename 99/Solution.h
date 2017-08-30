#pragma once
#ifndef __99__SOLUTION_H__
#define __99__SOLUTION_H__
#include "../lib/TreeNode.h"
#include <cstdint>
#include <stack>

class Solution {
public:
	Solution():first(nullptr), second(nullptr), prev(nullptr), count(0){}
	void recoverTree(TreeNode* root) 
	{
		// inorder_travel(root);
		// std::swap(first->val, second->val);
		std::stack<TreeNode* > node_stack;
		TreeNode* pointer = root;
		while(!node_stack.empty() || pointer)
		{
			if(pointer)
			{
				node_stack.push(pointer);
				pointer = pointer->left;
			}
			else
			{
				pointer = node_stack.top();
				if(visit(pointer))
				{
					break;
				}
				// visit(pointer);
				pointer = pointer->right;
				node_stack.pop();
			}
		}
		if (first && second) 
		{
			std::swap(first->val, second->val);
		}
	}

	bool visit(TreeNode *node)
	{
		if(!node)
		{
			return false;
		}
		if(prev)
		{
			if (first == nullptr && node->val <= prev->val)
			{
				first = prev;
			}
			if (first != nullptr && node->val <= prev->val)
			{
				second = node;
				count++;
			}
		}
		prev = node;
		return count == 2; 
	    // 二次改变second值，说明不是相邻节点顺序颠倒
	}

private:
	TreeNode* first;
	TreeNode* second;
	TreeNode* prev;
	int count;
};
#endif
