/*
 * generateParenthsis.cpp
 *
 *  Created on: 2015年11月14日
 *      Author: chenyulin
 */

#include "def.h"


class Solution {
public:

	void dfs(stack<char>& st, string ans, int step, int n, vector<string>& ansVec)
	{
		if (step == n)
		{
			if (st.empty())
				ansVec.push_back(ans);
			return;
		}
		st.push('(');
		dfs(st, ans + "(", step + 1, n, ansVec);
		st.pop();

		if (!st.empty())
		{
			st.pop();
			dfs(st, ans + ")", step + 1, n, ansVec);
			st.push('(');
		}
	}

    vector<string> generateParenthesis(int n) {
        string tmp;
        stack<char> st;
        vector<string> ansVec;
        dfs(st, tmp, 0, n * 2, ansVec);
        return ansVec;
    }
};
