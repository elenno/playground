/*
 * ContainerMostWater.h
 *
 *  Created on: 2015年9月19日
 *      Author: chenyulin
 */

#ifndef CONTAINERMOSTWATER_H_
#define CONTAINERMOSTWATER_H_

#include "def.h"

class Solution {
public:
#define min(x,y) ((x) < (y) ? (x) : (y))
#define max(x,y) ((x) > (y) ? (x) : (y))
#define positive(x) ((x) < 0 ? (-(x)) : (x))

	struct temp
	{
		int pos;
		int height;
		bool operator < (const temp& t)
		{
			if (height != t.height)
				return height < t.height;
			else
				return pos < t.pos;
		}
	};

    int maxArea2(vector<int>& height) {
    	if (height.size() <= 1)
    		return 0;
    	vector<temp> arr;
    	temp p;
    	for (int i = 0; i < height.size(); i++)
    	{
    		p.pos = i;
    		p.height = height[i];
    		arr.push_back(p);
    	}
    	sort(arr.begin(), arr.end());
    	int area = 0;
        int maxPos = arr[arr.size() - 1].pos;
        int minPos = arr[arr.size() - 1].pos;
    	for (int i = arr.size() - 2; i >= 0; i--)
    	{
    		int tmp1 = positive(maxPos - arr[i].pos);
    		int tmp2 = positive(minPos - arr[i].pos);
    		int tmp = max(tmp1, tmp2) * arr[i].height;
    		if (area < tmp)
    			area = tmp;
    		maxPos = max(maxPos, arr[i].pos);
    		minPos = min(minPos, arr[i].pos);
    	}
    	return area;
    }

    //由于遍历的时候，宽会越来越小，所以高度需要找更大的，才有机会获得更大的面积
    int maxArea(vector<int>& height) {
    	int left = 0;
    	int right = height.size() - 1;
    	int area = 0;
    	int minH = 0;
    	while (left < right)
    	{
    		if (height[left] > minH || height[right] > minH) //找到一个更大的高度
    		{
    			minH = min(height[left], height[right]);
    		    area = max(area, (right - left) * minH); //计算面积
    		    if (minH == height[left]) //较矮的一边往中间靠拢寻找更高的高度
    		    	left++;
    		    else
    		    	right--;
    		}
    		else if (height[left] <= minH)
    		{
    			left++;
    		}
    		else if (height[right] <= minH)
    		{
    			right--;
    		}
    	}
    	return area;
    }
};



#endif /* CONTAINERMOSTWATER_H_ */
