/**
 * author: LynnChan
 * problem: 给出一个字符串，求最长的一条子串的长度，该子串里面的字符互不重复
 * solution: 遍历一次字符串，在这个过程中记录当前字母的上个位置在哪里(代码中的last数组, 默认值-1)
 *           比如"abcda" 则i=0时last['a']=-1, i=4时last['a']=0, 再记录一个hash数组,
 *           hash[i]记录的是以第i个字母为终点的目标子串最长的长度, 则当 i - last[s[i]] < hash[i-1]时
 *           hash[i] = hash[i-1] + 1, 否则hash[i]=i-last[s[i]], 在遍历过程中取最大的hash[i]即可
 */

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	if (s.length() == 0)
    		return 0;
        int len = 1;
        std::vector<int> last;
        int hash[2] = {1, 1};//滚动数组
        last.resize(128, -1);//numbers of ascll
        int i = 0, p = 0;
        for (string::iterator it = s.begin(); it != s.end(); ++it, ++i, p ^= 1)
        {
            hash[p] = i - last[*it];
        	last[*it] = i;
        	if (hash[p] > hash[p^1])
        	{
        		hash[p] = hash[p^1] + 1;
       		}
       		if (len < hash[p])
       		{
       			len = hash[p];
       		}
        }
    	return len;
    }
};

