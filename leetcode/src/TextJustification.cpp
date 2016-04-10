/*
 * TextJustification.cpp
 *
 *  Created on: 2016年4月10日
 *      Author: chenyulin
 */

#include "def.h"

/*
 * 解法：按照规则模拟即可，注意两点：
 *      1.最后一行是左顶格，每个单词之间一个空格，最后用空格补齐
 *      2.要保证每个单词之间至少一个空格，单词之间空格数是由剩余空格数和本行剩余单词数来计算
 */

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
    	if (maxWidth == 0)
    		return words;
    	int idx = 0;
    	vector<string> ret;
    	while (idx < words.size())
    	{
    		int len = words[idx].length();
    		int tmp = idx + 1;
    		while (tmp < words.size())
    		{
    			if (len + words[tmp].length() <= maxWidth)
    				len += words[tmp].length();
    			else
    				break;
    			tmp++;
    		}
    		tmp--;
    		cout << "len:" << len << " tmp:" << tmp << " idx:" << idx << endl;
    		while (tmp > idx)
    		{
    			if (len + (tmp - idx) * 1 <= maxWidth)
    			{
    				break;
    			}
    			else
    			{
    				len -= words[tmp].length();
    				tmp--;
    			}
    		}
    		cout << "tmp:" << tmp << endl;
    		string line;
    		if (tmp == idx)
    		{
    			line += words[tmp];
    			line += string(maxWidth - len, ' ');
    		}
    		else
    		{
    			int idx_t = idx;
    			int spaceEach = (maxWidth - len) % (tmp - idx) == 0 ?
    					(maxWidth - len) / (tmp - idx) : (maxWidth - len) / (tmp - idx) + 1;
    			int spaceTotal = 0;
    			while (idx_t < tmp)
    			{
    				line += words[idx_t];
    				int totalSpaceLeft = maxWidth - len - spaceTotal;//剩余的空格数
    				int spaceNum = totalSpaceLeft % (tmp - idx_t) == 0 ?
    						totalSpaceLeft / (tmp - idx_t) :
							totalSpaceLeft / (tmp - idx_t) + 1;
    				if (tmp == words.size() - 1)
    					spaceNum = 1;
    				line += string(spaceNum, ' ');
    				spaceTotal += spaceNum;
    				idx_t++;
    			}
    			line += words[tmp];
    			if (tmp == words.size() - 1)
    				line += string(maxWidth - line.length(), ' ');
    		}
    		ret.push_back(line);
    		idx = tmp + 1;
    	}
    	return ret;
    }
};

