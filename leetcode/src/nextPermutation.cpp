/*
 * nextPermutation.cpp
 *
 *  Created on: 2016年1月2日
 *      Author: chenyulin
 */

#include "def.h"


class Solution {
public:

    void nextPermutation(vector<int>& nums) {
    	bool foundAnswer = false;
    	for (int i = nums.size() - 2; i >= 0; i--)
    	{
    		if (nums[i] < nums[i + 1])
    		{
    			//找到大于nums[i]的最小数的位置
    			int minPos = i + 1;
    			for (int j = i + 2; j < nums.size(); j++)
    			{
    				if (nums[i] < nums[j] && nums[j] <= nums[minPos])
    				{
    					minPos = j;
    				}
    			}
    			//交换位置
    			int tmp = nums[i];
    			nums[i] = nums[minPos];
    			nums[minPos] = tmp;

    			//反转剩余部分  reverse
    			reverse(nums.begin() + i + 1, nums.end());

    			foundAnswer = true;
    			break;
    		}
    	}
    	if (!foundAnswer)
    	{
    		reverse(nums.begin(), nums.end());
    	}
    	for (int i = 0; i < nums.size(); i++)
    	{
    		cout << nums[i] << " ";
    	}
    	cout << endl;
    }
};
