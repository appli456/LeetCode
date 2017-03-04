#include <iostream>
#include "Solution.h"
#include "../lib/ListNode.h"
using namespace std;


void print(ListNode* head)
{
	while (head)
	{
		cout << head->val << '\t';
		head = head->next;
	};
	cout << endl;
}

ListNode* create(initializer_list<int> list)
{
	ListNode* head = nullptr;
	ListNode* temp = nullptr;
	if (!list.size())
	{
		return head;
	}
	for (auto it: list)
	{
		if (!head)
		{
			head = new ListNode(it);
		}
		else if (!(head->next))
		{
			temp = new ListNode(it);
			head->next = temp;
		}
		else
		{
			ListNode* tail = new ListNode(it);
			temp->next = tail;
			temp = temp->next;
		}
	}

	return head;
}


int main()
{
	Solution *s = new Solution();
	print(s->sortList(create({ 2, 3, 5, 1 })));
	print(s->sortList(create({})));
	system("pause");
	return 0;
}