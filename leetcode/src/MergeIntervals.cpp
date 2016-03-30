/*
 * MergeIntervals.cpp
 *
 *  Created on: 2016年3月30日
 *      Author: chenyulin
 */

#include "def.h"

struct Interval
	{
		int start;
		int end;
		Interval() :
				start(0), end(0)
		{
		}
		Interval(int s, int e) :
				start(s), end(e)
		{
		}
	};

/*
 * 合并区间, O(nlogn)time   O(n)space
 * 首先按Interval.start排序
 * 维护一个临时区间 然后遍历一次，如果当前区间与临时区间重合，则更新临时区间
 * 否则加入答案，并用当前区间取缔临时区间成为新的临时区间
 */

class Solution
{
public:

	struct cmp
	{
		bool operator() (const Interval& lhs, const Interval& rhs)
		{
			if (lhs.start != rhs.start)
				return lhs.start < rhs.start;
			return lhs.end < rhs.end;
		}
	};

	vector<Interval> merge(vector<Interval>& intervals)
	{
		vector<Interval> ret;
		if (intervals.size() == 0)
			return ret;
		sort(intervals.begin(), intervals.end(), cmp());
		Interval tmp(intervals[0]);
		for (int i = 1; i < intervals.size(); i++)
		{
			if (tmp.end < intervals[i].start)
			{
				ret.push_back(tmp);
				tmp = intervals[i];
			}
			else
			{
				tmp.end = std::max(tmp.end, intervals[i].end);
			}
		}
		ret.push_back(tmp);
		return ret;
	}
};

