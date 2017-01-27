#pragma once
#ifndef __354_SOLUTION_H__
#define __354_SOLUTION_H__
#include <vector>
#include <utility>
#include <algorithm>

using std::vector;
using std::pair;
using std::sort;
class Solution {
private:
	static int binary_search(vector<pair<int, int>>* contain, pair<int, int>* target)
	{
		int left = 0,
			right = contain->size() - 1;

		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (contain->at(mid).second < target->second && 
				contain->at(mid).first <= target->first)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}

		return left;
	}
	static void envelopes_quick_sort(vector<pair<int, int>>* envelopes, int start, int end)
	{
		if (start >= end)
		{
			return;
		}
		int first = start,
			last = end;
		pair<int, int>key(envelopes->at(first));

		while (first < last)
		{
			while (first < last &&
				(envelopes->at(last).first > key.first ||
					envelopes->at(last).first == key.first && envelopes->at(last).second <= key.second))
			{
				--last;
			}
			envelopes->at(first) = envelopes->at(last);

			while (first < last &&
				(envelopes->at(first).first < key.first ||
					envelopes->at(first).first == key.first && envelopes->at(first).second >= key.second))
			{
				++first;
			}
			envelopes->at(last) = envelopes->at(first);
		}

		envelopes->at(first) = key;
		envelopes_quick_sort(envelopes, start, first - 1);
		envelopes_quick_sort(envelopes, first + 1, end);
	}
public:
	
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		unsigned size = envelopes.size();
		if (size <= 1)
		{
			return size;
		}
		//sort(envelopes.begin(), envelopes.end(), 
		//	[&](pair<int, int> a, pair<int, int> b)
		//	{
		//	return (a.first < b.first) || 
		//		(a.first == b.first && a.second > b.second);
		//	});
		envelopes_quick_sort(&envelopes, 0, size - 1);
		//for (auto envelope: envelopes)
		//{
		//	std::cout << envelope.first << "," << envelope.second << std::endl;
		//}
		vector<pair<int, int>> dolls;
		for (auto envelope: envelopes)
		{
			if (dolls.size() == 0 ||
				(envelope.first >= dolls.back().first && 
				envelope.second > dolls.back().second))
			{
				dolls.push_back(envelope);
			}
			else
			{
				dolls.at(binary_search(&dolls, &envelope)) = envelope;
			}
		}
		//for (auto envelope: dolls)
		//{
		//	std::cout << envelope.first << "," << envelope.second << std::endl;
		//}

		return dolls.size();
		// return 0;
	}

	
};
#endif
