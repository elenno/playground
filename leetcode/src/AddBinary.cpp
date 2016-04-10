/*
 * AddBinary.cpp
 *
 *  Created on: 2016年4月10日
 *      Author: chenyulin
 */

#include "def.h"


class Solution {
public:
    string addBinary(string a, string b) {
    	reverse(a.begin(), a.end());
    	reverse(b.begin(), b.end());
    	string ret;
    	int idx = 0;
    	int tmp = 0;
    	while (idx < a.length() || idx < b.length())
    	{
    		char aa = idx < a.length() ? a[idx] : '0';
    		char bb = idx < b.length() ? b[idx] : '0';
    		int t = aa - '0' + bb - '0' + tmp;
    		if (t >= 2)
    		{
    			tmp = 1;
    			t = t % 2;
    		}
    		else
    		{
    			tmp = 0;
    		}
    		ret += (char)('0' + t);
    		idx++;
    	}
    	if (tmp != 0)
    		ret += '1';
    	reverse(ret.begin(), ret.end());
    	return ret;
    }
};
