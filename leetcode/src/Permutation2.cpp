/*
 * Permutation2.cpp
 *
 *  Created on: 2016年3月13日
 *      Author: chenyulin
 */


#include "def.h"

/* 问题：一组有重复的整型数序列，返回所有的排列，重复的去除
 * 解法：dfs, 控制好重复的整型数不要让其在重复的位置出现
 * 对序列做dfs，而不是位置做dfs， 位置用来选数字， 就能避免重复
 *
 */

class Solution {
public:
	void dfs(vector<vector<int>>& ret, vector<int>& ans, int step, vector<vector<int>>& numsVec, vector<int>& used, int totalNum, int subStep, int curIdx)
	{
		if (step == numsVec.size())
		{
			ret.push_back(ans);
			return;
		}
		if (subStep == numsVec[step].size())
		{
			dfs(ret, ans, step + 1, numsVec, used, totalNum, 0, 0);
			return;
		}

		for (int i = curIdx; i < totalNum; i++)
		{
			if (used[i])
				continue;
			used[i] = 1;
			ans[i] = numsVec[step][subStep];
			dfs(ret, ans, step, numsVec, used, totalNum, subStep + 1, i + 1);
			used[i] = 0;
		}
	}

    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	vector<vector<int>> ret;
    	vector<vector<int>> numsVec;
    	sort(nums.begin(), nums.end());
    	int preIdx = -1;
    	for (int i = 0; i < nums.size(); i++)
    	{
			if (preIdx >= 0 && nums[preIdx] == nums[i])
			{
				numsVec[numsVec.size() - 1].push_back(nums[i]);
			}
    		else
    		{
    			numsVec.push_back(vector<int>());
    			numsVec[numsVec.size() - 1].push_back(nums[i]);
    			preIdx = i;
    		}
    	}
    	vector<int> ans;
    	vector<int> used;
    	ans.resize(nums.size(), 0);
    	used.resize(nums.size(), 0);
    	dfs(ret, ans, 0, numsVec, used, nums.size(), 0, 0);
    	return ret;
    }
};

