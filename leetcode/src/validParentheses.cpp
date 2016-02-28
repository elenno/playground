/*
 * validParentheses.cpp
 *
 *  Created on: 2015年11月14日
 *      Author: chenyulin
 */

#include "def.h"

class Solution {
public:
    bool isValid(string s) {
    	stack<char> st;
    	for (int i = 0; i < s.length(); i++)
    	{
    		const char tmp = s[i];
    		if (tmp == '(' || tmp == '{' || tmp == '[')
    		{
    			st.push(tmp);
    		}
    		else
    		{
    			if (st.empty())
    			{
    				return false;
    			}
    			char foo = st.top();
    			st.pop();
    			if (!(tmp == ')' && foo == '(' || tmp == '}' && foo == '{'
    					|| tmp == ']' && foo == '['))
    			{
    				return false;
    			}
    		}
    	}
    	if (!st.empty())
    	{
    		return false;
    	}
    	return true;
    }
};



