/*
 * ZigZagConversion.h
 *
 *  Created on: 2015年9月4日
 *      Author: chenyulin
 */

#ifndef ZIGZAGCONVERSION_H_
#define ZIGZAGCONVERSION_H_

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
    	if (s.length() == 1 || numRows == 0 || numRows == 1)
    	{
    		return s;
    	}

    	string ret;
    	int count = 2 * numRows - 2;
    	cout << "length: " << s.length() << " count: " << count << endl;
    	for (int i = 0; i < numRows; i++)
    	{
    		for (int j = 0; j + i < s.length(); j += count)
    		{
    			cout << s[j + i];
    			ret += s[j + i];
    			if (i != 0 && i != numRows - 1 && j + count - i < s.length())
    			{
    				cout << s[j + count - i];
    				ret += s[j + count - i];
    			}
    		}
    	}
    	cout << endl;
    	return ret;
    }
};


#endif /* ZIGZAGCONVERSION_H_ */
