/*
 * LongestCommonPrefix.h
 *
 *  Created on: 2015年9月20日
 *      Author: chenyulin
 */

#ifndef LONGESTCOMMONPREFIX_H_
#define LONGESTCOMMONPREFIX_H_

#include "def.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if (strs.size() == 0)
    		return "";
    	int min_len = 2147483647;
    	int min_idx = -1;
    	for (int i = 0; i < strs.size(); i++)
    	{
    		if (strs[i].length() < min_len)
    		{
    			min_len = strs[i].length();
    			min_idx = i;
    		}
    	}
    	int len = 0;
    	for (int i = 0; i < min_len; i++)
    	{
    		int j;
    		for (j = 0; j < strs.size(); j++)
    		{
    			if (strs[j][i] != strs[min_idx][i])
    				break;
    		}
    		if (j < strs.size())
    			break;
    		len = i + 1;
    	}
    	string ans = strs[min_idx].substr(0, len);
        cout << "len:" << len << " ans:" << ans << " min_idx:" << min_idx << endl;
    	return ans;

    }
};


#endif /* LONGESTCOMMONPREFIX_H_ */
