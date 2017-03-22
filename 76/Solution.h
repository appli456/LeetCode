#pragma once
#ifndef __76__SOLUTION_H__
#define __76__SOLUTION_H__
#include <string>
#include <map>
// using namespace std;
using std::string;
using std::map;
class Solution {
public:
	string minWindow(string s, string t) {
		// string result{""};
		if(s.length() <= 0 || t.length() <= 0)
		{
			return "";
		}
		map<char, int>digit_map;
		init_digit_map(digit_map);
		for(auto c : t)
		{
			digit_map[c]++;
		}

		int tail(s.size() + 1),
			head(0),
			ans_head(0),
			tot = t.size();
		for(int i = 0; i < s.size(); ++i)
		{
			int tp = static_cast<int>(s[i]);
			if(digit_map[s[i]] > 0)
			{
				--tot;
			}
			digit_map[s[i]]--;
			while(!tot)
			{
				if (tail > i - head + 1)
					tail = i - head + 1, ans_head = head;
				// move s[head]
				if (digit_map[s[head]] == 0) tot++;
				digit_map[s[head]]++;
				head++;
			}

		}

		if (tail > s.size()) return "";
		return s.substr(ans_head, tail);
	}

private:
	static void init_digit_map(map<char, int>& digit_map)
	{
		for(int i = 0; i < 26; ++i)
		{
			digit_map[i + 'A'] = 0;
			digit_map[i + 'a'] = 0;
		}
	}
};
#endif
