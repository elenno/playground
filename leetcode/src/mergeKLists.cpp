/*
 * mergeKLists.cpp
 *
 *  Created on: 2015年11月21日
 *      Author: chenyulin
 */

#include "def.h"

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :
			val(x), next(NULL)
	{
	}
};

class Solution
{
public:
	ListNode* mergeTwoList(ListNode* p0, ListNode* pi)
	{
		ListNode* ret = p0;
		if (p0 == NULL)
		{
			ret = pi;
			return ret;
		}
		while (p0 != NULL && pi != NULL)
		{
			if (p0->val > pi->val)
			{
				ListNode* tmp = pi;
				while (tmp->next != NULL && p0->val > tmp->next->val)
				{
					tmp = tmp->next;
				}
				int val = tmp->val;
				tmp->val = p0->val;
				p0->val = val;
			}
			if (p0->val <= pi->val)
			{
				while (p0->next != NULL && p0->next->val <= pi->val)
				{
					p0 = p0->next;
				}
				if (p0->next == NULL)
				{
					p0->next = pi;
					break;
				}
				else
				{
					ListNode* tmpi = pi;
					while (pi->next != NULL && pi->next->val <= p0->next->val)
					{
						pi = pi->next;
					}
					if (pi->next == NULL)
					{
						pi->next = p0->next;
						p0->next = tmpi;
						break;
					}
					else
					{
						ListNode* pinext = pi->next;
						pi->next = p0->next;
						p0->next = tmpi;
						p0 = pi->next;
						pi = pinext;
					}
				}
			}
		}
		return ret;
	}
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		if (lists.size() == 0)
			return NULL;
		else if (lists.size() == 1)
			return lists[0];

		int size = lists.size();
		while(size > 1)
		{
			int low = 0;
			int high = size - 1;
			while(low < high)
			{
				lists[low] = mergeTwoList(lists[low], lists[high]);
				low++;
			    high--;
			}
			size = (size + 1) / 2;
		}
		return lists[0];
	}
};

