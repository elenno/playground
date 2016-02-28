/*
 * removeDuplicate.cpp
 *
 *  Created on: 2015年12月5日
 *      Author: chenyulin
 */

#include "def.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::map<int, int> hash;
        int idx = 0;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); )
        {
        	if (hash.find(*it) == hash.end())
        	{
        		hash.insert(std::map<int, int>::value_type(*it, idx));
        		idx++;
        		++it;
        	}
        	else
        	{
        		it = nums.erase(it);
        	}
        }
        return nums.size();
    }
};


