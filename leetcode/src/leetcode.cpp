//============================================================================
// Name        : leetcode.cpp
// Author      : LynnChan
// Version     :
// Copyright   : __Lynn_Chan__
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//Definition for singly-linked list.
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
	ListNode* getNewNode(int x, int y, int &z)
	{
		ListNode* node = new ListNode(x + y + z);
		if (node->val >= 10)
		{
			node->val -= 10;
			z = 1;
		}
		else
		{
			z = 0;
		}
		return node;
	}

	ListNode* addToList(ListNode* tail, ListNode* node, ListNode*& root)
	{
		if (node == NULL)
		{
			return tail;
		}
		if (tail == NULL)
		{
			root = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			tail = tail->next;
		}

		return tail;
	}

//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        ListNode* root = NULL;
//        ListNode* tail  = NULL;
//        ListNode* ptr1 = l1;
//        ListNode* ptr2 = l2;
//        int tmp = 0;
//        for (; ptr1 != NULL && ptr2 != NULL; ptr1 = ptr1->next, ptr2 = ptr2->next)
//        {
//            ListNode* node = getNewNode(ptr1->val, ptr2->val, tmp);
//            tail = addToList(tail, node, root);
//        }
//        for (; ptr1 != NULL; ptr1 = ptr1->next)
//        {
//        	ListNode* node = getNewNode(ptr1->val, 0, tmp);
//        	tail = addToList(tail, node, root);
//        }
//		for (; ptr2 != NULL; ptr2 = ptr2->next)
//		{
//			ListNode* node = getNewNode(0, ptr2->val, tmp);
//			tail = addToList(tail, node, root);
//		}
//		if (tmp == 1)
//		{
//			ListNode* node = getNewNode(0, 0, tmp);
//			tail = addToList(tail, node, root);
//		}
//		return root;
//    }

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode* root = l1 ? l1 : l2;
		ListNode* tail = root;
		int tmp = 0;
		int sum = 0;
		while (l1 || l2)
		{
			sum = tmp;
			if (l1)
			{
				sum += l1->val;
				l1 = l1->next;
			}
			if (l2)
			{
				sum += l2->val;
				l2 = l2->next;
			}
			if (sum >= 10)
			{
				tmp = 1;
				sum -= 10;
			}
			else
			{
				tmp = 0;
			}
			tail->val = sum;
			if (l1)
			{
				tail = tail->next = l1;
			}
			else if (l2)
			{
				tail = tail->next = l2;
			}
			else
			{
				tail->next = NULL;
			}
		}
		if (tmp == 1)
		{
			ListNode* node = new ListNode(1);
			tail->next = node;
		}
		return root;
	}

};

