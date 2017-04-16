#pragma once
#ifndef __141__SOLUTION_H__
#define __141__SOLUTION_H__
#include "../lib/ListNode.h"
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (!head) {
			return false;
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
					return false;
				}
			}
			else
			{
				return false;
			}
		} while (slow != fast);
		return true;
	}
};
#endif
