/*
 * kmp.cpp
 *
 *  Created on: 2015年12月5日
 *      Author: chenyulin
 */

#include "def.h"

class Solution {
public:
	void getBackTrackArray(std::vector<int>& array, string& s)
	{
		array.clear();
		array.resize(s.length() + 1);
		if (s == "")
			return;
		array[1] = 0;
		int j = 0;
		for (int i = 2; i <= s.length(); i++)
		{
			while (j > 0 && s.at(i - 1) != s.at(j))
			{
				j = array[j];
			}
			if (s.at(i - 1) == s.at(j))
			{
				j = j + 1;
			}
			array[i] = j;
		}
	}

    int strStr(string haystack, string needle) {
        //return haystack.find(needle);
    	if (haystack.length() < needle.length())
    		return -1;
    	if (needle == "")
    		return 0;
    	std::vector<int> bta;
    	getBackTrackArray(bta, needle);

    	int j = 0;
    	for (int i = 0; i < haystack.length(); i++)
    	{
    		while (j > 0 && haystack.at(i) != needle.at(j))
    		{
    			j = bta[j];
    		}
    		if (haystack.at(i) == needle.at(j))
    		{
    			j = j + 1;
    			if (j == needle.length())
    			{
    				return i - j + 1;
    			}
    		}
    	}
    	return -1;
    }
};


