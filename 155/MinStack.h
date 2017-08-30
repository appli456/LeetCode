#pragma once
#include <stack>
#include <algorithm>

using std::stack;
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int number) {
        serial_stack.push(number);
        if (min_stack.empty())
        {
            min_stack.push(number);
        }
        else
        {
            min_stack.push(std::min(number, min_stack.top()));
        }
    }

    void pop() {
        serial_stack.pop();
        min_stack.pop();
    }

    int top() {
        return serial_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }

private:
    std::stack<int>serial_stack;
    std::stack<int>min_stack;
};