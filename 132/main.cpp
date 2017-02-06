// 132.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Solution.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
	Solution *s = new Solution();
	cout << s->minCut("fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi") << endl;
	system("pause");
    return 0;
}

