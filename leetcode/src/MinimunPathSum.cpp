/*
 * MinimunPathSum.cpp
 *
 *  Created on: 2016年4月9日
 *      Author: chenyulin
 */

#include "def.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	if (grid.size() == 0)
    		return 0;
    	if (grid[0].size() == 0)
    		return 0;
    	int m = grid.size();
    	int n = grid[0].size();
    	vector<vector<int> > dp;
    	vector<int> tmp;
    	tmp.resize(n, 0);
    	dp.resize(m, tmp);

    	for (int i = 0; i < grid.size(); i++)
    	{
    		for (int j = 0; j < grid[i].size(); j++)
    		{
    			if (i == 0 && j == 0)
    			{
    				dp[i][j] = grid[i][j];
    			}
    			else if (i == 0)
    				dp[i][j] = dp[i][j - 1] + grid[i][j];
    			else if (j == 0)
    				dp[i][j] = dp[i - 1][j] + grid[i][j];
    			else
    				dp[i][j] = std::min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
    		}
    	}

    	return dp[m - 1][n - 1];
    }
};

