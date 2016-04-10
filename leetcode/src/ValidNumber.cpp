/*
 * ValidNumber.cpp
 *
 *  Created on: 2016年4月9日
 *      Author: chenyulin
 */

#include "def.h"

class Solution
{
public:
	bool checkValidCharater(const string& s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			cout << 's[i]:' << s[i] << endl;
			if ((s[i] < '0' || s[i] > '9') && s[i] != 'e' && s[i] != '.'
					&& s[i] != ' ' && s[i] != '+' && s[i] != '-')
				return false;
		}
		return true;
	}

	int findFirstNumber(const string& s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
				return i;
		}
		return std::string::npos;
	}

	int findLastNumber(const string& s)
	{
		for (int i = s.length() - 1; i >= 0; i--)
		{
			if (s[i] >= '0' && s[i] <= '9')
				return i;
		}
		return std::string::npos;
	}

	bool checkSpaceBetweenTwoNumber(const string& s, int begin, int end)
	{
		for (int i = begin + 1; i < end; i++)
		{
			if (s[i] == ' ')
				return true;
		}
		return false;
	}

	bool validPlusMinusCount(const string& s)
	{
		int p = 0;
		int m = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '+')
				p++;
			else if (s[i] == '-')
				m++;
		}
		return p > 2 || m > 2;
	}

	bool isNumber(string s)
	{
		int firstNumber = findFirstNumber(s);
		int lastNumber = findLastNumber(s);
		if (firstNumber == std::string::npos)
			return false;
		int space = s.find_first_of(' ');
		int temp = s.find_first_not_of(' ');
		int temp2 = s.find_last_not_of(' ');
		if (validPlusMinusCount(s))
			return false;
		if (checkSpaceBetweenTwoNumber(s, temp, temp2))
			return false;
		int dotpos = s.find('.');
		if (dotpos != std::string::npos)
		{
			if (s.find_first_of('.') != s.find_last_of('.'))
				return false;
		}
		int epos = s.find('e');
		if (epos != std::string::npos)
		{
			if (s.find_first_of('e') != s.find_last_of('e'))
				return false;
			if (firstNumber == lastNumber)
				return false;
			if (epos < firstNumber || epos > lastNumber)
				return false;
			if (dotpos > epos)
				return false;
		}
		int ppos = s.find('+');
		if (ppos != std::string::npos)
		{
			int lppos = s.find_last_of('+');
			if (lppos != ppos)
			{
				if (!(lppos == epos + 1))
					return false;
			}
			int ppos = s.find('+');
			if (ppos > firstNumber)
			{
				if (epos == std::string::npos)
					return false;
				if (ppos > lastNumber)
					return false;
				if (ppos != epos + 1)
					return false;
			}
			if (std::string::npos != dotpos && dotpos < ppos)
			{
				if (!(epos != std::string::npos && epos > dotpos
						&& ppos == epos + 1))
					return false;
			}
		}
		int mpos = s.find('-');
		if (mpos != std::string::npos)
		{
			int lmpos = s.find_last_of('-');
			if (lmpos != mpos)
			{
				if (!(lmpos == epos + 1))
					return false;
			}
			if (mpos > firstNumber)
			{
				if (epos == std::string::npos)
					return false;
				if (mpos > lastNumber)
					return false;
				if (mpos != epos + 1)
					return false;
			}
			if (ppos != std::string::npos)
			{
				if (!(ppos < mpos && mpos == epos + 1
						|| mpos < ppos && ppos == epos + 1))
					return false;
			}
			if (mpos > dotpos && dotpos != std::string::npos)
			{
				if (!(epos != std::string::npos && epos > dotpos
						&& mpos == epos + 1))
					return false;
			}
		}
		if (!checkValidCharater(s))
			return false;
		return true;
	}
};

