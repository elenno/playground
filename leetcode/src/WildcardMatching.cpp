/*
 * WildcardMatching.cpp
 *
 *  Created on: 2016年3月5日
 *      Author: chenyulin
 */

#include "def.h"
class Solution {
public:
	/*
	 * 回退匹配法：O(n) time O(1) space
	 * 令star等于上一个'*'的序号
	 * 令(star_s-1)等于s串中匹配上一个'*'的序号
	 * 遍历s串
	 * 当匹配'?'和相同字符时, i、j 同时增加1
	 * 当遇到'*'时， 用star记录下'*'的序号，star_s更新为i,表示i前的所有字符匹配完成
	 * 当无法匹配的字符时，若star不为-1，则回退到上一个star和star_s,更新star star_s，重新继续匹配
	 * 若star为-1，则必定无法匹配完成，提前return false
	 * 最后return j == lenP
	 * ps:最后可能是若干个'*', 切记继续遍历p串直到没有'*'或串尾
	 */
	bool isMatch(string s, string p) {
		int i = 0;
		int j = 0;
		int lenS = s.length();
		int lenP = p.length();
		int star = -1;
		int star_s = 0;

		while (i < lenS)
		{
			if (j < lenP && (s[i] == p[j] || p[j] == '?'))
			{
				i++;
				j++;
			}
			else if (j < lenP && p[j] == '*')
			{
				star = j;
				star_s = i;
				j++;
			}
			else if (-1 != star)
			{
				j = star + 1;
				star_s++;
				i = star_s;
			}
			else
			{
				return false;
			}
		}
		while (j < lenP && p[j] == '*')
			j++;

		return j == lenP;
	}

/*
 * dp解法: O(NM) time  O(kN) space  k=2 （滚动数组）
 * dp[i][j]表示长度为i的s的前缀和长度为j的p的前缀是否匹配(0为不匹配 1为匹配)
 * 若p[j]不为'*'  dp[i + 1][j + 1] = dp[i][j] == 0 ? 0 : 1
 * 若p[j]为'*'  dp[i + 1][j + 1] = 1 当以下情况发生( 1.dp[i][j]为1  2.dp[i + 1][j]为1 即'*'匹配空串
 *  3.当'*'匹配了s[i]之前的任意字符 即 dp[x][j] == 1  x=[0, i)   ) 若不满足该3种情况，dp[i+1][j+1]=0
 * 最后，return dp[lenS][lenP] == 1
 * ps:注意初始化滚动数组
 */

//	bool isMatch(string s, string p) {
//	        cout << s.length() << " " << p.length() << endl;
//	        if (s.length() == 0 && p.length() == 0)
//	        {
//	            return true;
//	        }
//	        else if (p.length() == 0)
//	        {
//	        	return false;
//	        }
//	        else if (s.length() == 0)
//	        {
//	        	for (int i = 0; i < p.length(); i++)
//	        	{
//	        		if (p[i] != '*')
//	        			return false;
//	        	}
//	        	return true;
//	        }
//	    	vector<vector<int>> dp;
//	    	dp.resize(s.length() + 1);
//	    	for (int i = 0; i <= s.length(); i++)
//	    	{
//	    		dp[i].resize(2, 0);
//	    	}
//	//    	if (p[0] == '*')
//	//    	{
//	//    	    for (int i = 0; i <= s.length(); i++)
//	//    	    {
//	//    	        dp[i][0] = 1;
//	//    	    }
//	//    	}
//	    	dp[0][0] = 1;
//	    	int k = 0;
//
//	    	for (int j = 0; j < p.length(); j++, k ^= 1)
//			{
//			    int pre = -1;
//			    dp[0][k ^ 1] = 0;
//				for (int i = 0; i < s.length(); i++)
//				{
//				    dp[i + 1][k ^ 1] = 0;
//					if (p[j] == '?')
//					{
//						if (dp[i][k] == 1)
//						{
//							dp[i + 1][k ^ 1] = 1;
//						}
//					}
//					else if (p[j] == '*')
//					{
//	                    if (dp[i][k] == 1 || pre != -1)
//						{
//							dp[i + 1][k ^ 1] = 1;
//							if (pre == -1)
//							{
//							    dp[i][k ^ 1] = 1;
//							    pre = 1;
//							}
//						}
//						else if (dp[i + 1][k] == 1)
//						{
//						    dp[i + 1][k ^ 1] = 1;
//						}
//					}
//					else if (p[j] == s[i] && dp[i][k] == 1)
//					{
//						dp[i + 1][k ^ 1] = 1;
//					}
//
//				//	cout << dp[i + 1][k ^ 1];
//				}
//			//	cout << endl;
//			}
//
//	    	if (dp[s.length()][k] == 1)
//	    		return true;
//	    	return false;
//	    }
};

