/*
 * ReverseInteger.h
 *
 *  Created on: 2015年9月4日
 *      Author: chenyulin
 */

#ifndef REVERSEINTEGER_H_
#define REVERSEINTEGER_H_

#include <iostream>
using namespace std;

class Solution {
public:
	static const int MAX_INT = 2147483647;
    int reverse(int x) {
        int t = 0;
        bool isNegative = false;
        if (x < 0)
        {
        	x = -x;
        	isNegative = true;
        }
    	while (x != 0)
    	{
    		int tmp = x % 10;
    		if ((MAX_INT - tmp) / 10 < t)
    			return 0;
    		t = t * 10 + tmp;
    		x /= 10;
    		cout << "t:" << t << " x:" << x << "tmp:" << tmp << endl;
    	}
        if (isNegative)
        	t = -t;
    	cout << "----------t:" << t << endl;
    	return t;
    }
};



#endif /* REVERSEINTEGER_H_ */
