/*
 * removeNthFromEnd.cpp
 *
 *  Created on: 2015年11月14日
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        std::vector<ListNode*> listVec;
        while(p != NULL)
        {
        	listVec.push_back(p);
        	p = p->next;
        }
        int len = listVec.size();
        ListNode* removePtr = listVec[len - n];
        ListNode* afterPtr = removePtr->next;
        if (len - n > 0)
        {
        	ListNode* beforePtr = listVec[len - n - 1];
        	beforePtr->next = afterPtr;
        }
        else if (len - n == 0)
        {
        	head = head->next;
        }
        else
        {
        	cout << "n invalid " << endl;
        }
        free(removePtr);
        return head;
    }
};
