/*
 * searchInsert.cpp
 *
 *  Created on: 2016年1月23日
 *      Author: chenyulin
 */

#include "def.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0)
        	return 0;

        int low = 0;
        int high = nums.size() - 1;
        int index = nums.size();
        while (low <= high)
        {
        	int mid = (low + high) / 2;
        	if (nums[mid] == target)
        	{
        		index = mid;
        		break;
        	}
        	else if (nums[mid] > target)
        	{
        		index = mid;
        		high = mid - 1;
        	}
        	else
        	{
        		low = mid + 1;
        	}
        }

        return index;
    }
};


