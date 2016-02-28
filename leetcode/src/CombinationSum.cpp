/*
 * CombinationSum.cpp
 *
 *  Created on: 2016年1月30日
 *      Author: chenyulin
 */

#include "def.h"

class Solution {
public:
	void dfs(vector<vector<int> >& answer, vector<int>& candidates, int target, int cur, int idx, vector<int>& ans) {
		if (cur == target)
		{
			answer.push_back(ans);
			return;
		}
		for (int i = idx; i < candidates.size(); i++)
		{
			if (cur + candidates[i] <= target) {
				ans.push_back(candidates[i]);
				dfs(answer, candidates, target, cur + candidates[i], i, ans);
				ans.pop_back();
			}
		}
	}

    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > answer, retVec;
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
        dfs(answer, candidates, target, 0, 0, ans);
        for (int i = 0; i < answer.size(); i++)
        {
        	vector<int>& tmp = answer[i];
        	bool hasSame = false;
        	for (int j = 0; j < i; j++)
        	{
        		vector<int>& tmp2 = answer[j];
        		if (tmp.size() != tmp2.size())
        			continue;
        		int k = 0;
        		for (k = 0; k < tmp.size(); k++)
        		{
        			if (tmp[k] != tmp2[k])
        				break;
        		}
        		if (k == tmp.size())
        		{
        			hasSame = true;
        			break;
        		}
        	}
        	if (!hasSame)
        	{
        		retVec.push_back(tmp);
        	}
        }
        return retVec;
    }
};

