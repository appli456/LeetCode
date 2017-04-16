#pragma once
#ifndef __142__SOLUTION_H__
#define __142__SOLUTION_H__
#include "../lib/ListNode.h"
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (!head) {
			return nullptr;
		}
		ListNode* slow = head;
		ListNode* fast = head;
		do
		{
			slow = slow->next;
			fast = fast->next;
			if (fast)
			{
				fast = fast->next;
				if (!fast) {
					return nullptr;
				}
			}
			else
			{
				return nullptr;
			}
		} while (slow != fast);

		slow = head;
		while (slow != fast) {
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
};
#endif
