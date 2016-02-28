/*
 * mergeTwoLists.cpp
 *
 *  Created on: 2015年11月14日
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
	ListNode() : val(0), next(NULL)
	{

	}
};

class Solution
{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		if (l1 == NULL)
		{
			return l2;
		}
		if (l2 == NULL)
		{
			return l1;
		}
		ListNode* head = NULL;
		ListNode* p = head;

		ListNode* p1 = l1;
		ListNode* p2 = l2;
		while (p1 != NULL)
		{
			cout << p1->val << endl;
		    p1 = p1->next;
		}
		while (p2 != NULL)
				{
					cout << p2->val << endl;
				    p2 = p2->next;
				}

		p1 = l1;
		p2 = l2;
		while (p1 != NULL && p2 != NULL)
		{
			ListNode* tmp = NULL;
			if (p1->val < p2->val)
			{
				tmp = p1;
				p1 = p1->next;
			}
			else
			{
				tmp = p2;
				p2 = p2->next;
			}
            cout << ":" << tmp->val << endl;
			if (p == NULL)
			{
				head = tmp;
				p = tmp;
			}
			else
			{
				p->next = tmp;
				p = p->next;
			}
		}
		if (p1 != NULL)
		{
			p->next = p1;
		}
		if (p2 != NULL)
		{
			p->next = p2;
		}
		return head;
	}
};


