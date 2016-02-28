/*
 * RegularExpressionMatching.h
 *
 *  Created on: 2015年9月5日
 *      Author: chenyulin
 */

#ifndef REGULAREXPRESSIONMATCHING_H_
#define REGULAREXPRESSIONMATCHING_H_

#include "def.h"

class Solution
{
public:
	bool isMatch(string s, string p)
	{
		const int sizeS = s.size();
		const int sizeP = p.size();
		bool dp[sizeS + 1][sizeP + 1];
		memset(dp, 0, sizeof(dp));
		int pre[sizeS];
		pre[0] = 0;
		for (int i = 1; i < sizeS; i++)
		{
			if (s[i] == s[i - 1])
			{
				pre[i] = pre[i - 1];
			}
			else
			{
				pre[i] = i;
			}
			//cout << pre[i];
		}
		int star = 0;
		bool hasNoStarElm = true;
		for (int j = 0; j <= sizeP; j++)
		{
			//dp[0][j] = true;
			if (j + 1 < sizeP && p[j + 1] == '*')
			{
				star++;
			}
			if (j < sizeP && p[j] == '*' && hasNoStarElm)
			{
				dp[0][j + 1] = true;
			}
			if (j + 1 < sizeP && p[j] != '*' && p[j + 1] != '*')
			{
				hasNoStarElm = false;
				star++;
			}
		}
		if (sizeS < sizeP - star * 2)
		{
			cout << "not enough character to match, ret false" << endl;
			return false;
		}
		//cout << endl;
		dp[0][0] = true;

		for (int i = 0; i < sizeS; i++)
		{
			for (int j = 0; j < sizeP; j++)
			{
				if (p[j] == '*')
				{
					dp[i + 1][j + 1] = dp[i + 1][j];
					//todo go back and do matching again!
					if (!dp[i + 1][j + 1])
					{
						//cout << "here!" << i << " " << j<< endl;
						int l = j;
						do
						{
							l -= 2;
							if (l < 0)
							{
								break;
							}
							if (p[l] == '*')
							{
								if (s[i] == p[l - 1])
								{
									dp[i + 1][j + 1] = dp[i][l];
								}
							}
							else if (p[l] == '.')
							{
								bool tmp = false;
								int o = l;
								do
								{
									tmp = dp[i][o] || tmp;
									if (tmp || o <= 0 || p[o - 1] != '*')
									{
										break;
									}
									o -= 2;
								} while (o >= 0);
								dp[i + 1][j + 1] = tmp;
							}
							else
							{
								bool tmp = false;
								int o = l;
								do
								{
									tmp = dp[i][o] || tmp;
									if (tmp || o <= 0 || p[o - 1] != '*')
									{
										break;
									}
									o -= 2;
								} while (o >= 0);
								dp[i + 1][j + 1] = (tmp && s[i] == p[l]);
							}
							if (dp[i + 1][j + 1])
							{
								break;
							}
						} while (l > 0 && p[l] == '*');
					}
				}
				else if (p[j] == '.')
				{
					if (j + 1 < sizeP && p[j + 1] == '*')
					{
						if (j == 0)
						{
							dp[i + 1][j + 1] = true;
						}
						else
						{
							dp[i + 1][j + 1] = false;
							if (dp[i][j + 1])
							{
								dp[i + 1][j + 1] = true;
							}
							int k = i + 1;
							while (k > 0)
							{
								if (dp[k][j])
								{
									dp[i + 1][j + 1] = true;
								}
								k--;
							}
							int l = j;
							bool tmp = false;
							int o = l;
							do
							{
								tmp = dp[i][o] || tmp;
								if (tmp || o <= 0 || p[o - 1] != '*')
								{
									break;
								}
								o -= 2;
							}while (o >= 0);
							dp[i + 1][j + 1] = dp[i + 1][j + 1] || tmp;
						}
					}
					else
					{
						int l = j;
						bool tmp = false;
						int o = l;
						do
						{
							tmp = dp[i][o] || tmp;
							if (tmp || o <= 0 || p[o - 1] != '*')
							{
								break;
							}
							o -= 2;
						} while (o >= 0);
						dp[i + 1][j + 1] = tmp;
					}
				}
				else
				{
					if (j + 1 < sizeP && p[j + 1] == '*')
					{
						if (s[i] == p[j])
						{
							dp[i + 1][j + 1] = false;
							int k = i;
							//cout << "pre[k]=" << pre[k] << " k:" << k << endl;
							int preK = pre[k];
							while (k >= preK)
							{
								bool tmp = dp[k][j];
								int l = j;
								while (l > 0 && p[l - 1] == '*' && !tmp)
								{
									l -= 2;
									if (l >= 0)
									{
										tmp = tmp || dp[i][l];
									}
								}

								if (tmp)
								{
									//cout << "k:" << k << " j:" << j << " dp[k][j]: <<" << dp[k][j] << endl;
									dp[i + 1][j + 1] = true;
									break;
								}
								k--;
							}
						}
						else
						{
							int l = j;
							bool tmp = false;
							int o = l;
							do
							{
								tmp = dp[i + 1][o] || tmp;
								if (tmp || o <= 0 || p[o - 1] != '*')
								{
									break;
								}
								o -= 2;
							} while (o >= 0);
							dp[i + 1][j + 1] = tmp;
						}
					}
					else
					{
						int l = j;
						bool tmp = false;
						int o = l;
						do
						{
							tmp = dp[i][o] || tmp;
							if (tmp || o <= 0 ||p[o - 1] != '*')
							{
								break;
							}
							o -= 2;
						} while (o >= 0);
						dp[i + 1][j + 1] = (tmp && (s[i] == p[j]));
					}
				}
				cout << dp[i + 1][j + 1];
			}
			cout << endl;
		}
		cout << "s:" << s << " p:" << p << " ret:" << dp[sizeS][sizeP] << endl;
		//for (int j = 0; j < sizeP; j++)
		//{
		//	if (dp[sizeS][j + 1])
		//	{
		//		cout << "true" << endl;
		//		return true;
		//	}
		//}
		//cout << "false" << endl;
		//return false;
		return dp[sizeS][sizeP];
	}
};

#endif /* REGULAREXPRESSIONMATCHING_H_ */
