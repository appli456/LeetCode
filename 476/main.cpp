// 476.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Solution.h"
using namespace std;
int main()
{
	Solution *s = new Solution();
	cout << s->findComplement(4) << endl;
	cout << s->findComplement(5) << endl;
	cout << s->findComplement(3) << endl;
	cout << s->findComplement(~(1 << 31)) << endl;
	cout << s->findComplement(1 << 30) << endl;
	cout << s->findComplement(2147483646) << endl;
	system("pause");
    return 0;
}

