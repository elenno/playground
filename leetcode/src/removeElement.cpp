/*
 * removeElement.cpp
 *
 *  Created on: 2015年12月5日
 *      Author: chenyulin
 */

#include "def.h"

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); )
        {
        	if (*it == val)
        		it = nums.erase(it);
        	else
        		++it;
        }
        return nums.size();
    }
};


