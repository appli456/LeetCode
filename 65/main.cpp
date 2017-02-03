// 65.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Solution.h"

using std::cout;
using std::endl;



int main()
{
	
	Solution *s = new Solution();
	auto test_case = [&](string te_string)
	{
		cout << te_string << ":" << s->isNumber(te_string) << endl;
	};
	test_case("3");
	test_case(" 0.3 ");
	test_case("-.8e-09");
	test_case("9 i");
	test_case("000");
	test_case("1e.90");
	test_case("2e3");
	test_case("e9") ;
	test_case(".1") ;
	test_case("3.") ;
	test_case("J++");
	test_case("3e3.0");
	test_case(".e3");
	test_case("46.e3");
	system("pause");
    return 0;
}

