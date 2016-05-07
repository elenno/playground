/*
 * SimplifyPath.cpp
 *
 *  Created on: 2016年5月7日
 *      Author: chenyulin
 */

/*
 * 解法： 模拟跳出文件夹即可， 注意 连续'.'的数量大于2时被当做文件夹处理，不需要跳出
 */

#include "def.h"

class Solution {
public:
	string jumpOut(string ans, int dotCount) {
		while (dotCount > 0)
		{
			dotCount--;
			int tmp = ans.find_last_of('/');
			if (tmp != string::npos)
			{
				ans = ans.substr(0, tmp);
				if (ans == "")
					ans = "/";
			}
		}
		return ans;
	}

    string simplifyPath(string path) {
    	string ans;
    	if (path == "")
    		return ans;
    	int idx = 0;
    	int preSlash = -1;
    	int preDot = -1;
    	int preAlpha = -1;
    	bool isJumpOut = false;
    	int dotCount = 0;
    	while (idx < path.length())
    	{
    		if (path[idx] != '/' && path[idx] != '.')
    		{
    			ans += path[idx];
    			preAlpha = idx;
    			dotCount = 0;
    		}
    		else if (path[idx] == '.')
    		{
    			ans += path[idx];
    		    dotCount++;
    			preDot = idx;
    		}
    		else
    		{
    			if (preAlpha <= preSlash && dotCount > 0 && dotCount < 3)
    			{
    				ans = jumpOut(ans, dotCount);
    			}

    			preDot = -1;
    			preAlpha = -1;
    			isJumpOut = false;
    			if (ans[ans.length() - 1] != '/')
    				ans += '/';

    			preSlash = idx;
    			dotCount = 0;
    		}
    		cout << ans << "  idx:" << idx << endl;
    		idx++;
    	}
    	cout << "ans:" << ans << endl;
    	idx = ans.length() - 1;
    	while (idx > 0)
    	{
    		if (ans[idx] == '/')
    			ans.erase(idx);
    		else
    			break;
    		idx--;
    	}
    	idx = ans.length() - 1;
    	while (idx > 0)
    	{
    		if (ans[idx] != '.')
    			break;
    		idx--;
    	}
    	if (ans.length() - idx - 1 < 3 && ans.length() - idx - 1 > 0)
    	{
    		ans = jumpOut(ans, ans.length() - idx - 1);
    	}
    	if (ans == "")
    		ans = "/";
    	return ans;
    }
};


