// 168.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Solution.h"
using namespace std;
int main()
{
	Solution *s = new Solution();
	
	cout << s->convertToTitle(27) << endl;
	cout << s->convertToTitle(28) << endl;
	system("pause");
    return 0;
}

