/*
 * swapNode.cpp
 *
 *  Created on: 2015年11月25日
 *      Author: chenyulin
 */

#include "def.h"

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    	ListNode* p = head;
    	ListNode* pre = NULL;
    	while(p != NULL && p->next != NULL)
    	{
    		if (p != head)
    		{
    			pre->next = p->next;
    		}
    		else
    		{
    			head = p->next;
    		}
    		ListNode* tmp = p->next;
    		p->next = tmp->next;
    		tmp->next = p;
    		pre = p;
    		p = p->next;
    	}
    	return head;
    }
};

