/*
 * mergeKLists2.cpp
 *
 *  Created on: 2015年11月21日
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
	  struct node
	  {
		  int val;
		  ListNode* addr;
		  bool operator< (const node& n) const
		  {
			  return val < n.val;
		  }
	  };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if (lists.size() == 0)
    		return NULL;
    	else if (lists.size() == 1)
    		return lists[0];

    	node tmp;
    	vector<node> nodeList;
    	for (int i = 0; i < lists.size(); i++)
    	{
    		ListNode* p = lists[i];
    	    while (p != NULL)
    	    {
    	    	tmp.val = p->val;
    	    	tmp.addr = p;
    	    	p = p->next;
    	    	nodeList.push_back(tmp);
    	    }
    	}
    	sort(nodeList.begin(), nodeList.end(), std::less<node>());
    	if (nodeList.size() == 0)
    	{
    		return NULL;
    	}
    	for (int i = 0; i < nodeList.size() - 1; i++)
    	{
    		nodeList[i].addr->next = nodeList[i + 1].addr;
    	}
    	nodeList[nodeList.size() - 1].addr->next = NULL;
    	return nodeList[0].addr;
    }
};


