/*
 * TrappingRainWater.cpp
 *
 *  Created on: 2016年1月31日
 *      Author: chenyulin
 */

/*
 the main idea of the solution is to maintain a decrease stack to calculate the
 trapping water. For every height[i] in the array, we back track to the previous
 heights by looking in the stack and calculate with the formula
 (sum += (min(x.height, height[i]) - x.nextHeight) * (i - x.idx - 1) ,
 which node::nextHeight is the highest level of water that lower than node::height behind)
 then we have to pop the node from the top if node::height <= height[i]
 (the node is useless after we calculate the trapping water). At last, we should maintain
  node::nextHeight of the top node in the stack and push a new node of height[i]
 */

#include "def.h"

class Solution {
public:
	struct node
	{
		int height;
		int idx;
		int nextHeight;
	};

    int trap(vector<int>& height) {
    	stack<node> decrease;
    	int sum = 0;
    	for (int i = 0; i < height.size(); i++)
    	{
			while (!decrease.empty())
			{
				node& x = decrease.top();

				if (x.nextHeight != -1)
				{
					sum += (min(x.height, height[i]) - x.nextHeight)
							* (i - x.idx - 1);
				}
				if (x.height <= height[i])
					decrease.pop();
				else
					break;
			}
    		if (!decrease.empty())
    		{
    			node& x = decrease.top();
    			x.nextHeight = height[i];
    		}
    		node tmp;
    		tmp.idx = i;
    		tmp.nextHeight = -1;
    		tmp.height = height[i];
    		decrease.push(tmp);
    	}
    	return sum;
    }
};


