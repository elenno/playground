/*
 * countAndSay.cpp
 *
 *  Created on: 2016年1月30日
 *      Author: chenyulin
 */

#include "def.h"

class Solution {
public:
	string getCountStr(int x)
	{
		string ret = "";
		while (x != 0)
		{
			ret += (char)('0' + (x % 10));
			x /= 10;
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}

    string countAndSay(int n) {
        string s = "1";
        string ret = s;
        for (int i = 1; i < n; i++)
        {
        	ret = "";
        	int j = 0;
        	int pre = -1;
        	int count = 0;
        	while (j < s.length())
        	{
        		if (pre == -1)
        		{
        			count = 1;
        			pre = j;
        		}
        		else if (s[pre] == s[j])
        		{
        			++count;
        		}
        		else
        		{
        			ret += getCountStr(count);
        			ret += s[pre];
        			count = 1;
        			pre = j;
        		}
        		j++;
        	}
        	if (count != 0)
        	        	{
        	        	    ret += getCountStr(count);
        	        	    ret += s[pre];
        	        	}
        	s = ret;
        }
        return ret;
    }
};


