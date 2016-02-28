/*
 * longestValidParentheses.cpp
 *
 *  Created on: 2016年1月10日
 *      Author: chenyulin
 */

#include "def.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s == "" || s.length() == 0)
            return 0;
        std::vector<int> dp;
        std::vector<int> ans;
        dp.resize(s.length(), 0);
        ans.resize(s.length(), 0);
        std::stack<int> st;
        int pre_right = -1;
        int max = 0;
        for (int i = 0; i < s.length(); i++)
        {
        	if (s[i] == '(')
        	{
        		st.push(i);
        		if (pre_right == -1)
        			dp[i] = 0;
        		else
        			dp[i] = dp[pre_right];
        	}
        	else
        	{
        		if (!st.empty())
        		{
        			int idx = st.top();
        			st.pop();
        			if (pre_right == -1)
        				dp[i] = 2;
        			else
        				dp[i] = dp[pre_right] + 2;
        			if (idx > 0)
        				ans[i] = ans[idx - 1] + dp[i] - dp[idx - 1];
        			else
        				ans[i] = dp[i];
        			if (max < ans[i])
        				max = ans[i];
        		}
        		else
        		{
        			if (i > 0)
        				dp[i] = dp[i - 1];
        			else
        				dp[i] = 0;
        		}
        		pre_right = i;
        	}
        	//cout << "dp[" << i << "]:" << dp[i] << "  ans[" << i << "]:" << ans[i] << endl;
        }
        return max;
    }
};


