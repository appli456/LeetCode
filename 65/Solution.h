#pragma once
#ifndef __65__SOLUTION_H__
#define __65__SOLUTION_H__
#include <string>
#include <sstream>
// #include <regex>
using std::string;
using std::stringstream;
// using std::regex;

enum class NUMBER_STATUS
{
	START,
	NUMBER,
	DOT,
	CHARACTER, // + or -
	E, // e
	// SPACE,
	ERROR
};

class Solution {

private:
	static string& trim(string &s)
	{
		if (s.empty())
		{
			return s;
		}

		s.erase(0, s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
		return s;
	}

	static NUMBER_STATUS get_status(char c)
	{
		if (c >= '0' && c <= '9')
		{
			return NUMBER_STATUS::NUMBER;
		}
		else if (c == '.')
		{
			return NUMBER_STATUS::DOT;
		}
		else if (c == '-' || c == '+')
		{
			return NUMBER_STATUS::CHARACTER;
		}
		else if (c == 'e')
		{
			return NUMBER_STATUS::E;
		}
		//else if (c == ' ')
		//{
		//	return NUMBER_STATUS::SPACE;
		//}
		return NUMBER_STATUS::ERROR;
	}

	static bool check_status(NUMBER_STATUS last_status, NUMBER_STATUS status)
	{
		if (status == NUMBER_STATUS::ERROR || last_status == NUMBER_STATUS::ERROR)
		{
			return false;
		} 
		else if (status == NUMBER_STATUS::E && last_status == NUMBER_STATUS::START) // START E
		{
			return false;
		}
		else if (last_status == NUMBER_STATUS::NUMBER && status == NUMBER_STATUS::CHARACTER) // NUMBER + CHARACTER
		{
			return false;
		}
		else if (last_status == NUMBER_STATUS::DOT && 
			(status == NUMBER_STATUS::CHARACTER || status == NUMBER_STATUS::DOT))
		{
			return false;
		}
		else if (last_status == NUMBER_STATUS::CHARACTER && 
			(status == NUMBER_STATUS::E || status == NUMBER_STATUS::CHARACTER))
		{
			return false;
		}
		else if (last_status == NUMBER_STATUS::E && 
			(status == NUMBER_STATUS::DOT || status == NUMBER_STATUS::E))
		{
			return false;
		}
		return true;
	}

public:
	bool isNumber(string s) {
		s = trim(s);
		int length = s.length();
		if (!length)
		{
			return false;
		}
		
		// regex number_regex("^( +)?(-|\\+)?(((\\d+)\\.?)|(\\.\\d+))(\\d+)?(e(-|\\+)?\\d+)?( +)?$");
		// return regex_match(s, number_regex);
		NUMBER_STATUS status(NUMBER_STATUS::START);
		NUMBER_STATUS last_status;
		bool if_dot(false), // check dot 
							// 1. 0 or 1 
							// 2. not just dot 
		if_e(false),
		if_number(false); // check number

		// status machine
		for (int i = 0; i < length; ++i)
		{
			last_status = status;
			status = get_status(s[i]);
			if (check_status(last_status, status))
			{
				if (status == NUMBER_STATUS::DOT)
				{
					// DOT behind e
					if (if_e)
					{
						return false;
					}
					if (!if_dot) 
					{
						if_dot = !if_dot;
					}
					// 2 or more dot
					else
					{
						return false;
					}
				}
				// got number
				else if (status == NUMBER_STATUS::NUMBER)
				{
					if_number = true;
				}
				// double e
				else if (status == NUMBER_STATUS::E)
				{
					if (last_status == NUMBER_STATUS::DOT && i == 1)
					{
						return false;
					}
					if (!if_e)
					{
						if_e = !if_e;
					}
					else
					{
						return false;
					}
				}
			}
			else
			{
				return false;
			}
		}

		if (!if_number || status == NUMBER_STATUS::ERROR)
		{
			return false;
		}
		else if (status == NUMBER_STATUS::E)
		{
			return false;
		}
		else if (status == NUMBER_STATUS::CHARACTER)
		{
			return false;
		}
		return true;
	}
};
#endif