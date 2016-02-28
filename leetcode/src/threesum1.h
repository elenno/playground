/*
 * threesum1.h
 *
 *  Created on: 2015年10月24日
 *      Author: chenyulin
 */

#ifndef THREESUM1_H_
#define THREESUM1_H_

#include "def.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int> > retVec;
    		if (nums.size() < 3)
    			return retVec;
    		sort(nums.begin(), nums.end(), std::less<int>());
    	for (int i = 0; i < nums.size(); i++)
    	{
    		int& a = nums[i];
    		if (i > 0 && a == nums[i - 1])
    			continue;
    		for (int j = i + 1; j < nums.size(); j++)
    		{
    			int& b = nums[j];
    			if (j > i + 1 && b == nums[j - 1])
    				continue;
    			int target = -(a + b);
    			if (target < a || target < b)
    				continue;
    			int low = j + 1;
    			int high = nums.size() - 1;
    			int pos = -1;
    			while (low <= high)
    			{
    				int mid = (low + high) / 2;
    				int& t = nums[mid];
    				if (target == t)
    				{
    					pos = mid;
    					break;
    				}
    				else if (target < t)
    				{
    					high = mid - 1;
    				}
    				else
    				{
    					low = mid + 1;
    				}
    			}
    			if (pos == -1)
    				continue;
    			vector<int> tmp;
    			tmp.push_back(a);
    			tmp.push_back(b);
    			tmp.push_back(nums[pos]);
    			retVec.push_back(tmp);
    		}
    	}
    	return retVec;
    }
};



#endif /* THREESUM1_H_ */
