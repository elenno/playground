/*
 * JumpGame.cpp
 *
 *  Created on: 2016年3月30日
 *      Author: chenyulin
 */

#include "def.h"


/*记录最大能跳到哪个地方即可*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
    	if (nums.size() == 0)
    		return false;
    	if (nums.size() == 1)
    		return true;
        int max = nums[0];
        for (int i = 1; i < nums.size() - 1; i++)
        {
        	if (max < i)
        		break;
        	if (max < i + nums[i])
        		max = i + nums[i];
        }
        if (max >= nums.size() - 1)
        	return true;
        else
        	return false;
    }
};
