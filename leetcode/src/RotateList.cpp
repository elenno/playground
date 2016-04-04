/*
 * RotateList.cpp
 *
 *  Created on: 2016年4月4日
 *      Author: chenyulin
 */

/*
 * 解法：第一次循环找出tail，list长度和关节位(维护一个与当前指针相差k个位置的指针）
 *      若k大于list长度，则求余并再遍历一次找到关节位
 *      拼接链表获得答案
 *
 */


#include "def.h"


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    	if (k == 0 || head == NULL)
    	{
    		return head;
    	}
    	int cnt = 0;
    	ListNode* ret = head;
    	ListNode* tail = head;
    	ListNode* ptr = head;
    	while (ptr)
    	{
    		if (cnt > k)
    			ret = ret->next;
    		cnt++;
    		tail = ptr;
    		ptr = ptr->next;
    	}
    	if (k >= cnt)
    	{
    		k = k % cnt;
    	}
    	ptr = head;
    	ret = head;
    	cnt = 0;
    	while (ptr)
    	{
    		if (cnt > k)
    			ret = ret->next;
    		cnt++;
    		ptr = ptr->next;
    	}
    	cout << ret->val << endl;
    	if (ret->next != NULL)
    	{
    		tail->next = head;
    		head = ret->next;
    		ret->next = NULL;
    	}
    	return head;
    }
};


