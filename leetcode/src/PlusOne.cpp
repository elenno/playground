/*
 * PlusOne.cpp
 *
 *  Created on: 2016年4月10日
 *      Author: chenyulin
 */

#include "def.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    	if (digits.size() == 0)
    		return digits;
    	int idx = digits.size() - 1;
    	int tmp = 1;
    	while (1)
    	{
    		if (idx == -1)
    		{
    			digits.push_back(0);
    			for (int i = 0; i < digits.size() - 1; i++)
    			{
    				digits[i + 1] = digits[i];
    			}
    			digits[0] = 1;
    			break;
    		}
    		digits[idx] += tmp;
    		if (digits[idx] >= 10)
    		{
    			tmp = digits[idx] / 10;
    			digits[idx] = digits[idx] % 10;
    			idx--;
    		}
    		else
    		{
    			break;
    		}
    	}
    	return digits;
    }
};
