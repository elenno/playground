/*
 * Atoi.h
 *
 *  Created on: 2015年9月5日
 *      Author: chenyulin
 */

#ifndef ATOI_H_
#define ATOI_H_

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
    	static const unsigned int MAX_INT = 2147483647;
    	static const unsigned int MAX_INT_X = MAX_INT + 1;
    	unsigned int ret = 0;
    	bool isNegative = false;
    	bool isSigned = false;
    	bool hasDigit = false;
    	int result = 0;
    	for (int i = 0; i < str.length(); i++)
    	{
    		if (str[i] >= '0' && str[i] <= '9')
    		{
    			if ((MAX_INT_X - (str[i] - '0')) / 10 < ret)
    			{
    				ret = MAX_INT_X;
    				break;
    			}
    			hasDigit = true;
    			ret = ret * 10 + (str[i] - '0');
    		}
    		else if ((str[i] == '-' || str[i] == '+') && !isSigned && !hasDigit)
    		{
    			isSigned = true;
    			if (str[i] == '-')
    			{
    				isNegative = !isNegative;
    			}
    		}
    		else if (str[i] == ' ' && && !isSigned && !hasDigit)
    		{
    			continue;
    		}
    		else
    		{
    			break;
    		}
    	}
    	cout << "ret: " << ret << endl;
    	if (isNegative)
    	{
    		if (ret >= MAX_INT_X)
    			result = -1 * (int)(MAX_INT) - 1;
    		else
    			result = -1 * (int)ret;
    	}
    	else if (!isNegative)
    	{
    		if (ret >= MAX_INT)
    			result = MAX_INT;
    		else
    			result = ret;
    	}
    	cout << "result: " << result << endl;
    	return result;
    }
};



#endif /* ATOI_H_ */
