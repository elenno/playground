/*
 * LongestPalindromic.h
 *
 *  Created on: 2015年8月30日
 *      Author: chenyulin
 */

#ifndef LONGESTPALINDROMIC_H_
#define LONGESTPALINDROMIC_H_
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
    	if (s.length() == 0 || s.length() == 1)
    		return s;
    	int len = 1;
    	int idx = 0;
    	const char* ss = s.data();
    	int pa[1005][1005];
    	memset(pa, 0, sizeof(pa));
    	for (int i = 0; i < s.size(); ++i)
    	{
    		for (int j = 0; j < 2; ++j)
    		{
    			pa[i][j] = 1;
    		}
    	}
    	for (int i = 0; i < s.size() - 1; ++i)
    	{
    		if (ss[i] == ss[i + 1])
    		{
    			pa[i][2] = 1;
    			len = 2;
    			idx = i;
    		}
    	}

    	for (int i = 3; i <= s.length(); ++i)
    	{
    		for (int j = 0; j + i - 1 < s.length(); ++j)
    		{
    			if (pa[j + 1][i - 2] != 1)
    			{
    				continue;
    			}
    			if (ss[j] != ss[j + i - 1])
    			{
    				continue;
    			}
    			pa[j][i] = 1;
    			len = i;
    			idx = j;
    		}
    	}



//    	for (int i = 2; i <= s.length(); i++)
//    	{
//    	    for (int j = 0; j + i - 1 < s.length(); j++)
//    	    {
//    	    	bool isPalindromic = true;
//    	    	for (int k = j, l = j + i - 1; k < l; k++, l--)
//    	    	{
//    	    		if (ss[k] != ss[l])
//    	    		{
//    	    			isPalindromic = false;
//    	    			break;
//    	    		}
//    	    	}
//    	    	if (isPalindromic)
//    	    	{
//    	    		len = i;
//    	    		idx = j;
//    	    	}
//    	    }
//    	}
    	string ret = s.substr(idx, len);
    	cout << "s:" << s << "  ret:" << ret << "  idx:" << idx << "  len:" << len << endl;
    	return ret;
    }
};



#endif /* LONGESTPALINDROMIC_H_ */
