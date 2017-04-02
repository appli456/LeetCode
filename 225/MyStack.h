#pragma once
#ifndef __225__MYSTACK_H__
#define __225__MYSTACK_H__
#include <memory>
#include <queue>
using std::queue;
class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {
		flag = true;
	}

	/** Push element x onto stack. */
	void push(int x) {
		if(flag)
		{
			first_container.push(x);
		}
		else 
		{
			second_container.push(x);
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int num;
		if (flag)
		{
			num = delete_back_element(second_container, first_container);
			clear_queue(first_container);
		}
		else
		{
			num = delete_back_element(first_container, second_container);
			clear_queue(second_container);
		}
		flag = !flag;
		return num;
	}

	/** Get the top element. */
	int top() {
		if (flag) 
		{
			return first_container.back();
		}
		return second_container.back();
	}

	/** Returns whether the stack is empty. */
	bool empty() const
	{
		// std::cout << first_container.size() << second_container.size() << std::endl;
		return first_container.empty() && second_container.empty();
	}
private:
	static void clear_queue(queue<int> &container)
	{
		while(!container.empty())
		{
			container.pop();
		}
	}

	static int delete_back_element(queue<int>& container, queue<int>& delete_container)
	{
		while(delete_container.size() > 1)
		{
			container.push(delete_container.front());
			delete_container.pop();
		}
		return delete_container.back();
	}
	bool flag;
	queue<int>first_container;
	queue<int>second_container;
};

/**
* Your MyStack object will be instantiated and called as such:
* MyStack obj = new MyStack();
* obj.push(x);
* int param_2 = obj.pop();
* int param_3 = obj.top();
* bool param_4 = obj.empty();
*/
#endif
