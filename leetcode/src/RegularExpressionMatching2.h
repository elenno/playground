/*
 * RegularExpressionMatching2.h
 *
 *  Created on: 2015年9月19日
 *      Author: chenyulin
 */

#ifndef REGULAREXPRESSIONMATCHING2_H_
#define REGULAREXPRESSIONMATCHING2_H_

#include "def.h"
//题解地址：http://blog.csdn.net/feliciafay/article/details/17137377
class Solution
{
public:
	//递归 对于*，可以对多个s中的字符进行匹配
	bool isMatch(string s, string p)
	{
		bool ret = isMatch_(0, 0, s, p);
		cout << "s:" << s << "  p:" << p << " isMatch:" << ret << endl;
		return ret;
	}

	bool isMatch_(int idxS, int idxP, string& s, string& p)
	{

		if (idxS >= s.length() && idxP >= p.length())
		{
			return true;
		}
		if (idxS >= s.length())
		{
			if (idxP + 1 < p.length() && p[idxP + 1] == '*')
			{
				isMatch_(idxS, idxP + 2, s, p);
			}
			else
			{
				return false;
			}
		}
		if (idxP >= p.length())
		{
			return false;
		}

		if (idxP + 1 < p.length() && p[idxP + 1] == '*')
		{
			int tmpS = idxS;
			while (idxS < s.length() && (s[idxS] == p[idxP] || p[idxP] == '.'))
			{
				if (isMatch_(idxS + 1, idxP + 2, s, p))
				{
					return true;
				}
				idxS++;
			}
			return isMatch_(tmpS, idxP + 2, s, p); //如果全部都不匹配，则x*不匹配任何s中的字符
		}
		else
		{
			return ((s[idxS] == p[idxP] || p[idxP] == '.')
					&& isMatch_(idxS + 1, idxP + 1, s, p));
		}
		return false;
	}
};
#endif /* REGULAREXPRESSIONMATCHING2_H_ */
