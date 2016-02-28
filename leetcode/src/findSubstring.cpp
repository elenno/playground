/*
 * findSubstring.cpp
 *
 *  Created on: 2015年12月26日
 *      Author: chenyulin
 */

#include "def.h"

class Solution
{
public:

	typedef std::map<int, int> PosMap; // <目标串的位置, 模式串数组中的序号>
	PosMap _posMap;

	//找出所有dst出现在src的序号，并存入_posMap
	void getSubStringPosition(string& src, string& dst, int idx)
	{
		size_t curPos = 0;
		while (curPos < src.length())
		{
			size_t ret = src.find(dst, curPos);
			if (ret == string::npos)
			{
				return;
			}
			_posMap.insert(PosMap::value_type(ret, idx));
			curPos = ret + 1;
		}
	}

	vector<int> findSubstring(string s, vector<string>& words)
	{
		cout << "size:" << words.size() << endl;
		std::vector<int> retVec;
		if (words.size() == 0)
			return retVec;
		int length = words[0].length();
		std::map<string, int> wordsMap;
		std::vector<int> wordsCount;
		wordsCount.resize(words.size(), 0);

		//对words中相同的字串做处理，计算所有字串出现的次数，并生成_posMap
		for (int i = 0; i < words.size(); i++)
		{
			std::map<string, int>::iterator it = wordsMap.find(words[i]);
			if (it == wordsMap.end())
			{
				getSubStringPosition(s, words[i], i);
				wordsMap.insert(std::map<string, int>::value_type(words[i], i));
				wordsCount[i] = 1;
			}
			else
			{
				int idx = it->second;
				wordsCount[idx]++;
			}
		}

		PosMap::iterator it = _posMap.begin();
		for (; it != _posMap.end(); ++it)
		{
			cout << it->first << " " << it->second << endl;
		}
		int wordsSize = words.size();
		int len = s.length();

		//这层循环是要覆盖所有起始点
		for (int start = 0; start < length; start++)
		{
			std::vector<int> hashVec;
			hashVec.resize(words.size(), 0);
			int curPos = start;
			int firstWordIdx = start;
			int cnt = 0;

			//对整条串跳跃地扫一次
			while (curPos < len)
			{
				PosMap::iterator it = _posMap.find(curPos);
				if (it == _posMap.end()) //如果这个位置找不到合适的串，则全部重置
				{
					curPos = curPos + length;
					firstWordIdx = curPos;
					cnt = 0;
					//hashVec.resize(words.size(), 0);
					for (int i = 0; i < hashVec.size(); i++)
					{
						hashVec[i] = 0;
						//cout << "ss: " << hashVec[i] << endl;
					}
					continue;
				}
				else
				{
					int wordIdx = it->second;
					if (hashVec[wordIdx] >= wordsCount[wordIdx]) //如果合适的串使用次数太多，那么需要从头去掉若干条串
					{
						cout << " shit! wIdx" << wordIdx << " hash:" << hashVec[wordIdx] << " wc:" << wordsCount[wordIdx] << endl;
						while(firstWordIdx < curPos)
						{
							int tmpIdx = _posMap[firstWordIdx];
							hashVec[tmpIdx]--;
							cnt--;
							firstWordIdx = firstWordIdx + length;
							if (tmpIdx == wordIdx)
							{
								break;
							}
						}
					}

					//使用这条合适的串
					hashVec[wordIdx]++;
					cnt++;
					cout << "cnt:" << cnt << " wordSize:" << wordsSize << endl;
					if (cnt == wordsSize) //若模式串数已达到wordsSize，则添加答案
					{
						retVec.push_back(firstWordIdx);
						cnt--;
						hashVec[_posMap[firstWordIdx]]--;

					}
					curPos += length;
					firstWordIdx = curPos - cnt * length;
					cout << "fidx:" << firstWordIdx << " cnt:" << cnt << " curPos:" << curPos << endl;
				}
			}
		}

		return retVec;
	}
};

int main()
{
	Solution s;
	void* p = &s;
	double* dp = static_cast<double*>(p);
	cout << "dp:" << dp << " val:" << *dp <<endl;
	std::vector<string> strVec;
	strVec.push_back("cb");
	strVec.push_back("aa");
	s.findSubstring("cbaacacbaa", strVec);
}
