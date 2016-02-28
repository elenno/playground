/*
 * PalindromeNumber.h
 *
 *  Created on: 2015年9月5日
 *      Author: chenyulin
 */

#ifndef PALINDROMENUMBER_H_
#define PALINDROMENUMBER_H_

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }
        else if (x < 10)
        {
        	return true;
        }
        int ten = 1;
        int tmp = x;
        while (tmp >= 10)
        {
            tmp /= 10;
            ten *= 10;
        }
        int div = 1;
        while (ten > div)
        {
        	//cout << "left:" << x / ten % 10 << " right:" << x % (div * 10) / div << endl;
        	if (x / ten % 10 != x % (div * 10) / div)
        		return false;
        	ten /= 10;
        	div *= 10;
        }
        //cout << "true:" << s << endl;
        return true;
    }
};


#endif /* PALINDROMENUMBER_H_ */
