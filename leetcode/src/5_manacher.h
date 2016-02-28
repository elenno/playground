/*
 * 5_manacher.h
 *
 *  Created on: 2015年8月30日
 *      Author: chenyulin
 *          ps: manacher算法求最长回文子串 参考http://blog.csdn.net/pi9nc/article/details/9251455的算法解析
 */

#ifndef __5_MANACHER_H__
#define __5_MANACHER_H__
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int p[2100];
        char t[2100];
        memset(p, 0, sizeof(p)); //以i为中心的回文串的长度
        memset(t, 0, sizeof(t));

        t[0] = '$';
        t[1] = '#';
        for (int i = 0; i < s.length(); i++)
        {
        	t[(i+1) * 2] = s[i];
        	t[(i+1) * 2 + 1] = '#';
        }
        t[(s.length() + 1) * 2] = '@';
        cout << t << endl;
        int length = (s.length() + 1) * 2;
        p[0] = 0;
        int id = 0;
        int mx = 0;
        for (int i = 1; i < length; i++)
        {
        	mx = p[id] + id;
        	if (mx > i) //若以id为中心的最大回文串包括i, 则判断i关于id的对称点j
        	{
        		int j = 2 * id - i;
        		if (p[j] <= mx - i) //若以j为中心的回文串的长度比i到mx距离小，则i有可能扩展成更长的回文串
        		{
        			p[i] = p[j];
        			while(t[i+p[i]+1] == t[i-p[i]-1])
        			{
        				p[i]++;
        			}
        			if (p[i] > p[id])
        				id = i;
        		}
        		else //若以j为中心的回文串长度比i到mx的距离大，则以i为中心的回文串最长为p[j] (因为以i为中心的回文串已在j的时候算出来了)
        		{
        			p[i] = p[j];
        		}
        	}
        	else  //若以id为中心的最长回文串不包括i, 则自行寻找回文串
        	{
        		p[i] = 0;
        		while(t[i+p[i]+1] == t[i-p[i]-1])
        		{
        			p[i]++;
        		}
        		if (p[i] > p[id])
        			id = i;
        	}
        	//cout << "i:" << i << " t[i]:" << t[i] << " p[i]:" << p[i] << " id:" << id << endl;
        }
        int len = (p[id] / 2) * 2;
        if (t[id] != '#')
        	len += 1;
        int idx = id - p[id];
        idx /= 2;
        string ret = s.substr(idx, len);
        cout << "ret:" << ret << endl;
        return ret;

    }
};




#endif /* 5_MANACHER_H_ */
