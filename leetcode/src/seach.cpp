/*
 * seach.cpp
 *
 *  Created on: 2016年1月17日
 *      Author: chenyulin
 */

#include "def.h"

class Solution {
public:
	int binary_search(vector<int>& nums, int target, int low, int high)
	{
		cout << "target:" << target << " low:" << low << "  high:" << high << endl;
		int res = -1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (nums[mid] == target)
			{
				res = mid;
				break;
			}
			else if (nums[mid] > target)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		return res;
	}

    int search(vector<int>& nums, int target) {
    	if (nums.size() == 0)
    		return -1;
    	int high = nums.size() - 1;
    	int low = 0;
    	int last = nums[high];
    	int pivot = -1;
    	while (low <= high)
    	{
    		int mid = (low + high) / 2;
    		if (nums[mid] >= last)
    		{
    			pivot = mid;
    			low = mid + 1;
    		}
    		else
    		{
    			high = mid - 1;
    		}
    	}
    	int res = -1;
    	if (target > last)
    	{
    		res = binary_search(nums, target, 0, pivot);
    	}
    	else
    	{
    		res = binary_search(nums, target, pivot + 1, nums.size() - 1);
    	}
    	return res;
    }
};

