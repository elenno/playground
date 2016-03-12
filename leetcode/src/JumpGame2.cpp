/*
 * JumpGame2.cpp
 *
 *  Created on: 2016年3月12日
 *      Author: chenyulin
 */
#include "def.h"

/*
 * 优先队列解法 O(nlogn) time, O(n) space
 * 使ans[i]等于到达i处的最小步数
 * 则ans[i] = min(ans[x, i - 1]) + 1, x为离i最远的可以到达i的点
 * 利用优先队列的特性，可以在O(1)的时间内找到min(ans[x, i - 1])
 * 结点保存的信息为steps:最小步数, fatherest_point:最远可到达的点
 * 循环对每个点i，若优先队列的第一位结点不能到达i点，则出队舍去该结点，并转向下个结点，
 * 以此类推，直到找到可到达i点的结点， 然后构造一个i点的结点入队。
 * 每个结点只会被入队和出队一次，所以是O(n) space，
 * 每个结点入队和出队耗时为O(logn)
 * 所以总的时间是O(nlogn)的。
 */

class Solution
{
public:
	struct node
	{
		int fatherest_point;
		int steps;
	};
	struct compare
	{
		bool operator()(const node& lhs, const node& rhs) const
		{
			cout << "comparing:" << lhs.steps << " " << rhs.steps << endl;
			if (lhs.steps != rhs.steps)
				return lhs.steps < rhs.steps;
			else
				return lhs.fatherest_point > rhs.fatherest_point;
		}
	};
	int jump(vector<int>& nums)
	{
		if (nums.size() < 2)
			return 0;
		priority_queue<node, std::vector<node>, compare> queue;
		node tmp;
		tmp.fatherest_point = nums[0];
		tmp.steps = 0;
		queue.push(tmp);
		for (int i = 1; i < nums.size(); i++)
		{
			while (!queue.empty())
			{
				const node& top = queue.top();
				cout << "i:" << i << " steps:" << top.steps << " dist:"
						<< top.fatherest_point << endl;
				if (top.fatherest_point >= i)
				{
					if (i == nums.size() - 1)
						return top.steps + 1;
					tmp.steps = top.steps + 1;
					tmp.fatherest_point = i + nums[i];
					queue.push(tmp);
					break;
				}
				else
				{
					queue.pop();
				}
			}

		}
		return -1;
	}
};

