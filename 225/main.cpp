// 225.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "MyStack.h"
using namespace std;
int main()
{
	MyStack *m = new MyStack();
	cout << m->empty() << endl;
	m->push(4);
	m->push(5);
	m->push(44);
	// cout << m->top() << endl;
	m->pop();
	// cout << m->top() << endl;
	// m->push(11);
	// cout << m->top() << endl;
	m->pop();
	// cout << m->top() << endl;
	m->pop();
	// m->pop();
	cout << m->empty() << endl;
	system("pause");
    return 0;
}

