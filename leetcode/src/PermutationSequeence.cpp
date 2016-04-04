/*
 * PermutationSequeence.cpp
 *
 *  Created on: 2016年4月4日
 *      Author: chenyulin
 */

/*
 * 解法： n个数的总排列数为 n*(n-1)*(n-2)*...*2*1  利用该特点来计算答案。
 *      第k个排列，令tmp等于k/((n-1)*(n-2)...*2*1)+1，则第x个数是第tmp个未使用的数
 *      然后对k求余，n等于n-1,继续计算，以此类推。
 *
 */

#include "def.h"

class Solution {
public:
    string getPermutation(int n, int k) {
    	int val[10] = {0};
    	bool flag[10] = {false};
        int total = 1;
        for (int i = 1; i <= n; i++)
        {
        	total = total * i;
        	val[i] = total;
        	flag[i] = false;
        }
        k = (k - 1) % total;
        string ret;
        int cur = n - 1;
        while(k > 0)
        {
        	int tmp = k / val[cur] + 1;
        	for (int i = 1, k = 0; i <= n; i++)
        	{
        		if (!flag[i])
        		{
        			k++;
        			if (k == tmp)
        			{
        				tmp = i;
        				break;
        			}
        		}
        	}
        	flag[tmp] = true;
        	ret += ('0' + tmp);
        	k = k % val[cur];
        	cur--;
        }
        for (int i = 1; i <= n; i++)
        {
        	if (!flag[i])
        	{
        		ret += ('0' + i);
        	}
        }
        return ret;
    }
};

