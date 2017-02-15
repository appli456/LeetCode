// 407.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Solution.h"
using namespace std;

vector<vector<int>>generate_list(initializer_list<initializer_list<int>> list)
{
	vector<vector<int>>v_p;
	for(auto it: list)
	{
		vector<int> container(it);
		v_p.push_back(container);
	}
	return v_p;
}

int main()
{
	Solution *s = new Solution();
	vector<vector<int>>container;
	cout << s->trapRainWater(generate_list({
		{1,4,3,1,3,2},
		{3,2,1,3,2,4}, 
		{2,3,3,2,3,1 }})) << endl;
	system("pause");
    return 0;
}

