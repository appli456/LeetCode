#pragma once
#ifndef __57__SOLUTION_H__
#define __57__SOLUTION_H__
#include <vector>
#include "../lib/Interval.h"
#include <algorithm>
using std::vector;
class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval>result;
		auto it = intervals.begin();
		for(; it != intervals.end(); ++it)
		{
			// find end
			if(newInterval.end < (*it).start)
			{
				break;
			}
			// cannot overlap
			else if(newInterval.start > (*it).end)
			{
				result.push_back(*it);
			}
			else
			{
				newInterval.start = std::min(newInterval.start, it->start);
				newInterval.end = std::max(newInterval.end, it->end);
			}
		}

		result.push_back(newInterval);
		for(; it != intervals.end(); ++it)
		{
			result.push_back(*it);
		}

		return result;
	}
};
#endif