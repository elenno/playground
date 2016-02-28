/*
 * RomanToInt.h
 *
 *  Created on: 2015年9月20日
 *      Author: chenyulin
 */

#ifndef ROMANTOINT_H_
#define ROMANTOINT_H_

#include "def.h"

class Solution
{
public:
	int romanToInt(string s)
	{
		//Ⅰ（1）、X（10）、C（100）、M（1000）、V（5）、L（50）、D（500）
		int ret = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'M')
			{
				ret += 1000;
			}
			else if (s[i] == 'C')
			{
				if (i + 1 < s.length() && s[i + 1] == 'M')
				{
					ret += 900;
					i++;
				}
				else if (i + 1 < s.length() && s[i + 1] == 'D')
				{
					ret += 400;
					i++;
				}
				else
				{
					ret += 100;
				}
			}
			else if (s[i] == 'X')
			{
				if (i + 1 < s.length() && s[i + 1] == 'C')
				{
					ret += 90;
					i++;
				}
				else if (i + 1 < s.length() && s[i + 1] == 'L')
				{
					ret += 40;
					i++;
				}
				else
				{
					ret += 10;
				}
			}
			else if (s[i] == 'I')
			{
				if (i + 1 < s.length() && s[i + 1] == 'X')
				{
					ret += 9;
					i++;
				}
				else if (i + 1 < s.length() && s[i + 1] == 'V')
				{
					ret += 4;
					i++;
				}
				else
				{
					ret += 1;
				}
			}
			else if (s[i] == 'D')
			{
				ret += 500;
			}
			else if (s[i] == 'L')
			{
				ret += 50;
			}
			else if (s[i] == 'V')
			{
				ret += 5;
			}
		}
		cout << "roman:" << s << "  num:" << ret << endl;
		return ret;
	}
};

#endif /* ROMANTOINT_H_ */
