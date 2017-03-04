#pragma once
#ifndef __148__SOUTION_H__
#define __148__SOUTION_H__
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include "../lib/ListNode.h"
#include <vector>
using std::vector;
class Solution {
public:
	ListNode* sortList(ListNode* head) 
	{	
		if (!head || !head->next)
		{
			return head;
		}
		ListNode* left = head;
		ListNode* right = get_middle(head);
		left = sortList(left);
		right = sortList(right);

		return merge(left, right);
	}
private:
	static ListNode* get_middle(ListNode* head)
	{
		ListNode* tail = head->next;
		ListNode* middle = head->next;
		ListNode* prev = head;
		int i = 0;
		while(tail)
		{
			tail = tail->next;
			if(i % 2)
			{
				prev = middle;
				middle = middle->next;
			}
			++i;
		}
		prev->next = nullptr;
		return middle;
	}
	static ListNode* merge(ListNode* left, ListNode* right)
	{
		ListNode* head = nullptr;
		if(left->val < right->val)
		{
			head = left;
			left = left->next;
		}
		else
		{
			head = right;
			right = right->next;
		}
		ListNode* tail = head;
		while(left && right)
		{
			if(left->val <= right->val)
			{
				tail->next = left;
				left = left->next;
			}
			else
			{
				tail->next = right;
				right = right->next;
			}
			tail = tail->next;
			tail->next = nullptr;
		}

		if(left)
		{
			tail->next = left;
		}
		if(right)
		{
			tail->next = right;
		}

		return head;
	}
	
};

#endif
