/*
 * searchRange.cpp
 *
 *  Created on: 2016年1月23日
 *      Author: chenyulin
 */

#include "def.h"

class Solution
{
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		vector<int> ans;
		ans.push_back(-1);
		ans.push_back(-1);
		if (nums.size() == 0)
			return ans;

		int low = 0;
		int high = nums.size() - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (nums[mid] < target)
			{
				low = mid + 1;
			}
			else if (nums[mid] == target)
			{
				ans[0] = mid;
				high = mid - 1;
			}
			else
			{
				high = mid - 1;
			}
		}

		low = 0;
		high = nums.size() - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (nums[mid] < target)
			{
				low = mid + 1;
			}
			else if (nums[mid] == target)
			{
				ans[1] = mid;
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
		return ans;
	}
};

