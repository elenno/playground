/*
 * threeSumClosest.h
 *
 *  Created on: 2015年10月31日
 *      Author: chenyulin
 */

#ifndef THREESUMCLOSEST_H_
#define THREESUMCLOSEST_H_

#include "def.h"
// t-(x+y+z) = 0
// t-x-y-z = 0
// t-x-y = z

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	std::vector<int> numbers;
    	sort(nums.begin(), nums.end(), std::less<int>());
    	int dist = 2147483647;
    	int ans = 0;
    	for (int i = 0; i < nums.size(); i++)
    	{
    		for (int j = i + 1; j < nums.size(); j++)
    		{
    			int z = target - nums[i] - nums[j];
    			int low = j + 1;
    			int high = nums.size() - 1;
    			int pos = -1;
    			while (low <= high)
    			{
    				int mid = (low + high) >> 1;
    				if (nums[mid] <= z)
    				{
    					pos = mid;
    					low = mid + 1;
    				}
    				else
    				{
    					high = mid - 1;
    				}
    			}
    			if (pos != -1)
    			{
    				if (z == nums[pos])
    				{
    					return nums[i] + nums[j] + z;
    				}
    				if (z - nums[pos] < dist)
    				{
    				    dist = z - nums[pos];
    				    ans = nums[i] + nums[j] + nums[pos];
    				}
    				if (pos + 1 < nums.size() && nums[pos + 1] - z < dist)
    				{
    					dist = nums[pos + 1] - z;
    					ans = nums[i] + nums[j] + nums[pos + 1];
    				}
    			}
    			else
    			{
    				if (j + 1 < nums.size() && nums[j + 1] - z < dist)
    				{
    					dist = nums[j + 1] - z;
    					ans = nums[i] + nums[j] + nums[j + 1];
    				}
    			}
    		}
    	}
    	cout << "dist:" << dist << "  ans:" << ans << endl;
    	return ans;
    }
};

class BestSolution {
public:
    int abs(int a)
    {
    	if (a < 0)
    		return -a;
    	return a;
    }

    int threeSumClosest(vector<int>& nums, int target) {
    	sort(nums.begin(), nums.end(), std::less<int>());
    	int ans = nums[0] + nums[1] + nums[2];
    	for (int i = 0; i < nums.size() - 1; i++)
    	{
    		int low = 0;
    		int high = nums.size() - 1;
    		while (low < i && i < high)
    		{
    			int temp = nums[low] + nums[i] + nums[high];
    			if (temp == target)
    				return temp;
    			if (abs(temp - target) < abs(ans - target))
    				ans = temp;
    			if (temp < target)
    				low++;
    			else
    				high--;
    		}
    	}
    	cout << "  ans:" << ans << endl;
    	return ans;
    }
};



#endif /* THREESUMCLOSEST_H_ */
