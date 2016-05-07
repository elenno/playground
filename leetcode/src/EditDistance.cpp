/*
 * EditDistance.cpp
 *
 *  Created on: 2016年5月7日
 *      Author: chenyulin
 */

/*
 * 解法：dp  time:O(n*m) space:O(n*m)
 *     设dp[x][y]为长度x的串1和长度y的串2的最小编辑距离，则
 *     (1)当使用插入操作时，dp[x][y] = min(dp[x-1][y], dp[x][y-1]) + 1
 *     (2)当使用替换操作时，dp[x][y] = dp[x-1][y-1] + (word1(x)==word2(y)?0:1)
 *     比较(1)(2)两者的较小值就是dp[x][y]的最优值
 *     删除操作与插入操作是同样的概念，所以不需要理会
 */

#include "def.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
    	vector<int> tmp;
    	vector<vector<int> > dp;
    	int len1 = word1.length();
    	int len2 = word2.length();
    	int len_max = max(len1, len2);
    	tmp.resize(len_max + 1, 0);
    	dp.resize(len_max + 1, tmp);

    	for (int i = 0; i <= len_max; i++)
    	{
    		dp[i][0] = i;
    		dp[0][i] = i;
    	}
    	for (int i = 0; i < len1; i++)
    	{
    		for (int j = 0; j < len2; j++)
    		{
    			dp[i + 1][j + 1] = min(
    					min(dp[i][j + 1] + 1, dp[i + 1][j] + 1),
    					dp[i][j] + (word1[i] == word2[j] ? 0 : 1)
    				);
    		//	cout << dp[i + 1][j + 1];
    		}
    		//cout << endl;
    	}
    	return dp[len1][len2];
    }
};

