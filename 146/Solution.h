#pragma once
#ifndef __146__SOLUTION_H__
#define __146__SOLUTION_H__
#include <list>
#include <utility>
#include <unordered_map>
using std::unordered_map;
using std::list;
using std::pair;

class LRUCache {
public:
	LRUCache(int capacity):capacity(capacity) 
	{

	}

	int get(int key) 
	{
		auto it = cache.find(key);
		if (it == cache.end())
		{
			return -1;
		}
		renew_used(it);

		return cache[key].first;
	}

	void put(int key, int value) 
	{
		if (!capacity)
		{
			return;
		}

		auto it = cache.find(key);
		if (it != cache.end())
		{
			renew_used(it);
			
		}
		else 
		{

			int size = cache.size();
			if (size >= capacity)
			{
				cache.erase(used.back());
				used.pop_back();
			}
			used.push_front(key);
		}
		cache[key] = { value, used.begin() };
	}

private:
	int capacity;
	unordered_map<int, pair<int, list<int>::iterator>>cache;
	list<int>used;

	void renew_used(unordered_map<int, pair<int, list<int>::iterator>>::iterator it)
	{
		used.erase(it->second.second);
		used.push_front(it->first);
		it->second.second = used.begin();
	}
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache obj = new LRUCache(capacity);
* int param_1 = obj.get(key);
* obj.put(key,value);
*/
#endif