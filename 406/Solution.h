#pragma once
#ifndef __406__SOLUTION_H__
#define __406__SOLUTION_H__
#include <vector>
#include <utility>
#include <functional>
#include <list>
#include <algorithm>
using std::vector;
using std::pair;
using std::list;
class Solution {
public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		//std::function<bool(pair<int, int>, pair<int, int>)> check = 
		//	[&](pair<int, int>a, pair<int, int>b)
		//	{
		//		return (a.first < b.first ||
		//			(a.first == b.first &&
		//				a.second >= b.second));
		//	};
		//quick_sort(people, 0, people.size() - 1, check);
		//vector<pair<int, int>> res;
		//for (auto& p : people)
		//	res.insert(res.begin() + p.second, p);
		//return res;

		std::function<bool(pair<int, int>, pair<int, int>)> check =
			[](const pair<int, int>& a, const pair<int, int>& b)
		{
			return (a.first > b.first ||
				(a.first == b.first &&
					a.second < b.second));
		};
		sort(people.begin(), people.end(), check);
		vector<pair<int, int>> res;
		for (auto& p : people)
			res.insert(res.begin() + p.second, p);
		return res;
	}

	//static void quick_sort(vector<pair<int, int>>& container, 
	//	int start, 
	//	int end, 
	//	const std::function<bool(pair<int, int>, pair<int, int>)> &check)
	//{
	//	if(start >= end)
	//	{
	//		return;
	//	}
	//	int left = start;
	//	int right = end;
	//	pair<int, int>key = container[left];
	//	while(left < right)
	//	{
	//		while (left < right && check(container[right], key) || container[right] == key
	//			//(container[right].first < key.first || 
	//			//	(container[right].first == key.first && 
	//			//		container[right].second >= key.second))
	//			) { right--; }
	//		container[left] = container[right];
	//		while (left < right && (!check(container[left], key) || container[left] == key)
	//			//(container[left].first > key.first || 
	//			//	(container[left].first == key.first && 
	//			//		container[left].second <= key.second))
	//			) { left++; }
	//		container[right] = container[left];
	//	}
	//	container[left] = key;
	//	quick_sort(container, 0, left - 1, check);
	//	quick_sort(container, left + 1, end, check);
	//}
};
#endif