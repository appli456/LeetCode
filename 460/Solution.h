#pragma once
#ifndef __460__SOLUTION_H__
#define __460__SOLUTION_H__
#include <unordered_map>
#include <list>
#include <iostream>
// #include <unordered_set>
#include <utility>

using std::unordered_map;
using std::list;
using std::pair;

class LFUCache {
public:
	LFUCache(int capacity)
		:capacity(capacity)
	{
		
	}

	int get(int key) 
	{
		auto got = value_map.find(key);
		if (got == value_map.end())
		{
			return -1;
		}
		// unsigned int frequency();

		freq_map[value_map[key].second].erase(iterator_map[key]);
		value_map[key].second++;
		freq_map[value_map[key].second].push_back(key);
		iterator_map[key] = --freq_map[value_map[key].second].end();

		if (freq_map[min_freq].size() == 0)
		{
			min_freq++;
		}

		return value_map[key].first;

	}

	void put(int key, int value) 
	{
		if (capacity > 0)
		{
			if (get(key) != -1)
			{
				value_map[key].first = value;
				return;
			}
			int size = value_map.size();
			if (size >= capacity)
			{
				value_map.erase(freq_map[min_freq].front());
				iterator_map.erase(freq_map[min_freq].front());
				freq_map[min_freq].pop_front();
			}

			min_freq = 0;
			freq_map[min_freq].push_back(key);
			value_map[key] = { value, 0 };
			iterator_map[key] = --freq_map[min_freq].end();
		}
	}

private:
	int capacity;
	int min_freq;
	unordered_map<int, pair<int, unsigned int>>value_map;
	unordered_map<int, list<int>::iterator>iterator_map;
	unordered_map<unsigned int, list<int>>freq_map;
	
};

/**
* Your LFUCache object will be instantiated and called as such:
* LFUCache obj = new LFUCache(capacity);
* int param_1 = obj.get(key);
* obj.put(key,value);
*/
#endif