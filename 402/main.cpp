// 402.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Solution.h"
using std::cout;
using std::endl;
int main()
{
	Solution *s = new Solution();
	cout << s->removeKdigits("1432219", 3) << endl;
	cout << s->removeKdigits("10200", 1) << endl;
	cout << s->removeKdigits("10", 2) << endl;
	cout << s->removeKdigits("22222222222222222222222222222222222222", 20) << endl;
	system("pause");
    return 0;
}

