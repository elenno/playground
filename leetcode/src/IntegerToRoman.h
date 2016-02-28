/*
 * IntegerToRoman.h
 *
 *  Created on: 2015年9月20日
 *      Author: chenyulin
 */

#ifndef INTEGERTOROMAN_H_
#define INTEGERTOROMAN_H_

#include "def.h"

class Solution
{
public:
	string intToRoman(int num)
	{
		int old = num;
		string ret;
		if (num >= 1000)
		{
			int tmp = num / 1000;
			num %= 1000;
			for (int i = 0; i < tmp; i++)
			{
				ret += "M";
			}
		}
		if (num >= 100)
		{
			int tmp = num / 100;
			num %= 100;
			if (tmp == 9)
			{
				ret += "CM";
			}
			else if (tmp == 4)
			{
				ret += "CD";
			}
			else if (tmp >= 5)
			{
				ret += "D";
				for (int i = 5; i < tmp; i++)
				{
					ret += "C";
				}
			}
			else
			{
				for (int i = 0; i < tmp; i++)
				{
					ret += "C";
				}
			}
		}
		if (num >= 10)
		{
			int tmp = num / 10;
			num %= 10;
			if (tmp == 9)
			{
				ret += "XC";
			}
			else if (tmp == 4)
			{
				ret += "XL";
			}
			else if (tmp >= 5)
			{
				ret += "L";
				for (int i = 5; i < tmp; i++)
				{
					ret += "X";
				}
			}
			else
			{
				for (int i = 0; i < tmp; i++)
				{
					ret += "X";
				}
			}
		}
		if (num >= 1)
		{
			int tmp = num;
			if (tmp == 9)
			{
				ret += "IX";
			}
			else if (tmp == 4)
			{
				ret += "IV";
			}
			else if (tmp >= 5)
			{
				ret += "V";
				for (int i = 5; i < tmp; i++)
				{
					ret += "I";
				}
			}
			else
			{
				for (int i = 0; i < tmp; i++)
				{
					ret += "I";
				}
			}
		}
		cout << "num:" << old << "  roman:" << ret << endl;
		return ret;
	}
};

#endif /* INTEGERTOROMAN_H_ */
