/*
 * UniquePath.cpp
 *
 *  Created on: 2016年4月4日
 *      Author: chenyulin
 */

/*
 * dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
 *
 *
 */

#include "def.h"

class Solution {
public:
    int uniquePaths(int m, int n) {
    	if (m == 0 || n == 0)
    		return 0;
        vector<vector<int> > dp;
        vector<int> tmp;
        tmp.resize(n, 0);
        dp.resize(m, tmp);
        for (int i = 0; i < m; i++)
        {
        	dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++)
        {
        	dp[0][i] = 1;
        }
        for (int i = 1; i < m; i++)
        {
        	for (int j = 1; j < n; j++)
        	{
        		dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        	}
        }
        return dp[m - 1][n - 1];
    }
};
