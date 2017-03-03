#include <iostream>
#include "Solution.h"
using namespace std;
int main(int arg, char** argv[])
{
	Solution *s = new Solution();
	cout << s->findSubstringInWraproundString("abcabcd"); << endl;
	system("pause");
	return 0;
}