/*
 * LongestCommonSubstring.h
 *
 *  Created on: 2015年8月30日
 *      Author: chenyulin
 */

#ifndef LONGESTCOMMONSUBSTRING_H_
#define LONGESTCOMMONSUBSTRING_H_
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
    	if (s.length() == 0 || s.length() == 1)
    		return s;
        //use longest common substring to do it
    	string t = s;
        std::reverse(t.begin(), t.end());
        int pa[1005][2];
        memset(pa, 0, sizeof(pa));
        int idx = 0;
        int len = 0;
        int start = 0, end = 0;
        for (int i = 0, k = 1; i < s.length(); ++i, k^=1)
        {
        	for (int j = 0; j < t.length(); ++j)
        	{
        		if (s[i] == t[j])
        		{
        		    pa[j + 1][k] = pa[j][k^1] + 1;
        		    if (pa[j + 1][k] > len)
        		    {
        		    	idx = j;
        		    	len = pa[j + 1][k];
        		    	start = j - len + 1;
        		    	end = j;
        		    }
        		}
        		else
        			pa[j + 1][k] = 0;
        		cout << pa[j + 1][k] << " ";

        	}
        	cout << endl;
        }
        string ret = t.substr(start, len);
        cout << "s:" << s << "  ret:" << ret << "  idx:" << idx << "  len:" << len << endl;
        cout << "start:" << start << " end:" << end << endl;
        return ret;
    }
};



#endif /* LONGESTCOMMONSUBSTRING_H_ */
