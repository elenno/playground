/*
 * threeSum.cpp
 *
 *  Created on: 2015年10月24日
 *      Author: chenyulin
 */
#include "threeSum.h"
/*vector<vector<int> > Solution::threeSum(vector<int>& nums)
{
	vector<vector<int> > retVec;
	if (nums.size() < 3)
		return retVec;
	sort(nums.begin(), nums.end(), std::less<int>());

	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	cout << "\n";
	twosum tmp;
	TwosumVec twosumVec;

	for (int i = 0; i < nums.size(); i++)
	{
		tmp.param[0] = nums[i];
		tmp.pos[0] = i;
		for (int j = i + 1; j < nums.size(); j++)
		{
			tmp.param[1] = nums[j];
			tmp.val = tmp.param[0] + tmp.param[1];
			tmp.pos[1] = j;
			twosumVec.push_back(tmp);
		}
	}

	sort(twosumVec.begin(), twosumVec.end());
	for (int i = 0; i < twosumVec.size(); i++)
	{
		cout << twosumVec[i].val << " " << twosumVec[i].param[0] << " "
				<< twosumVec[i].param[1] << "\n";
	}
	set<threenums> answerSet;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i != 0 && nums[i] == nums[i - 1])
			continue;
		int low = 0;
		int high = twosumVec.size() - 1;
		int pos = -1;
		int target = -nums[i];
		cout << "target:" << target << "\n";
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (twosumVec[mid].val == target)
			{
				pos = mid;
				high = mid - 1;
			}
			else if (twosumVec[mid].val > target)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		if (pos == -1)
			continue;
		threenums temp;
		for (int j = pos; j < twosumVec.size(); j++)
		{
			if (twosumVec[j].val != target)
			{
				break;
			}
			cout << "s1:" << target << "\n";
			if (i == twosumVec[j].pos[0] || i == twosumVec[j].pos[1])
				continue;
			temp.a = nums[i];
			temp.b = twosumVec[j].param[0];
			temp.c = twosumVec[j].param[1];
			temp.sortt();
			if (answerSet.find(temp) == answerSet.end())
			{
				cout << "s2:" << temp.a << " " << temp.b << " " << temp.c
						<< "\n";
				answerSet.insert(temp);
				vector<int> vec;
				vec.push_back(temp.a);
				vec.push_back(temp.b);
				vec.push_back(temp.c);
				retVec.push_back(vec);
			}
		}
	}
	for (int i = 0; i < retVec.size(); i++)
	{
		cout << retVec[i][0] << " " << retVec[i][1] << " " << retVec[i][2]
				<< "\n";
	}
	return retVec;
}

*/
