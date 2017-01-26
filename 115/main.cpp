// 115.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Solution.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	Solution *s = new Solution();
	cout << s->numDistinct("rabbbit", "rabbit") << endl;
	cout << s->numDistinct("", "a") << endl;
	cout << s->numDistinct("rabbbit", "rabit") << endl;
	cout << s->numDistinct("rabbbittt", "rabit") << endl;
	cout << s->numDistinct("", "") << endl;
	cout << s->numDistinct("a", "") << endl;
	system("pause");
    return 0;
}

