/*
 * FirstMisingPositive.cpp
 *
 *  Created on: 2016年1月31日
 *      Author: chenyulin
 */

#include "def.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int MAXN = 10007;
    	bool hash[MAXN];
    	memset(hash, false, sizeof(hash));
    	for (int i = 0; i < nums.size(); i++)
    	{
    		if (nums[i] <= 0 || nums[i] >= MAXN)
    			continue;
    		hash[nums[i]] = true;
    	}
    	int i = 0;
    	for (i = 1; i < MAXN; i++)
    	{
    		if (!hash[i])
    			break;
    	}
    	return i;
    }
};
