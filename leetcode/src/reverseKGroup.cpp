/*
 * reverseKGroup.cpp
 *
 *  Created on: 2015年11月27日
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
	ListNode* reverseKGroup(ListNode* head, int k)
	{
		if (k < 2 || head == NULL)
			return head;
		int len = 0;
		ListNode* p = head;
		while (p != NULL)
		{
			len++;
			p = p->next;
		}

		if (len < k)
		{
			return head;
		}
		ListNode* front = NULL;
		ListNode* pre = NULL;
		int cnt = 0;
		p = head;
		bool first_time = true;
		int tot = 0;
		while (p != NULL)
		{
			ListNode* tmp = p->next;
			if (pre != NULL && cnt != 0)
			{
				p->next = pre;
			}
			else
			{
				front = p;
			}
			pre = p;
			p = tmp;
			cnt++;
			if (cnt == k)
			{
				front->next = tmp;
				cnt = 0;
				if (first_time)
				{
					first_time = false;
					head = pre;
				}
				pre = front;
			}

			if (len - tot < k)
				break;
			tot++;
		}
		p = head;
		while (p != NULL)
		{
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
		return head;
	}
	ListNode* reverseKGroup2(ListNode* head, int k)
	{
		if (k < 2 || head == NULL)
			return head;
		int len = 0;
		ListNode* p = head;
		while (p != NULL)
		{
			len++;
			p = p->next;
		}
		if (len < k)
		{
			return head;
		}
		for (int i = 0; i < k - 1; i++)
		{
			p = head;
			int cnt = 0;
			int tot = 0;
			int lim = k - i - 1;
			ListNode* front = NULL;
			ListNode* pre = NULL;
			while (p != NULL)
			{
				if (len - tot < k)
				{
					break;
				}
				tot++;
				if (cnt == 0)
				{
					front = p;
				}
				else if (cnt == lim)
				{
					//cout << p->val << "sdsds\n";
					ListNode* tmp = front->next;
					front->next = p->next;
					p->next = front;
					if (pre != NULL)
					{
						pre->next = tmp;
					}
					else
					{
						head = tmp;
						//	cout << "head:" << tmp->val << endl;
					}
					p = front;
				}
				cnt++;
				if (tot % k == 0)
				{
					pre = p;
					cnt = 0;
					//cout << "pre:" << pre->val << endl;
				}
				p = p->next;
			}
			p = head;
			while (p != NULL)
			{
				cout << p->val << " ";
				p = p->next;
			}
			cout << endl;
		}

		return head;
	}
};

