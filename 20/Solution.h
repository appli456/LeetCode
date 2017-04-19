#pragma once
#ifndef __20__SOLUTION_H__
#define __20__SOLUTION_H__
#include <string>
#include <stack>
using std::string;
using std::stack;
class Solution {
public:
	bool isValid(string s) {
		stack<char>str_stack;
		for(auto it = s.begin(); it != s.end(); ++it)
		{
			if(*it == '}' || *it == ')' || *it == ']')
			{
				if(str_stack.empty())
				{
					return false;
				}
				char c = str_stack.top();
				str_stack.pop();
				if(!((*it == '}' && c == '{') || 
					(*it == ')' && c == '(') || 
					(*it == ']' && c == '[')))
				{
					return false;
				}
			}
			else
			{	
				str_stack.push(*it);
			}
		}
		return str_stack.empty();
	}
};
#endif