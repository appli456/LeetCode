#pragma once
#ifndef __257__TREENODE_H__
#define __257__TREENODE_H__
#include <cstddef>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
#endif