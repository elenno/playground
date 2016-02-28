/*
 * median2.cpp
 *
 *  Created on: 2015年8月29日
 *      Author: chenyulin
 */

#include<vector>
using namespace std;

class Solution
{
public:

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		if (nums1.size() == 0 && nums2.size() == 0)
			return 0;
		else if (nums1.size() == 0)
		{
			if (nums2.size() % 2 == 1)
			{
				return nums2[nums2.size() / 2];
			}
			else
			{
				return (nums2[nums2.size() / 2] + nums2[nums2.size() / 2 - 1])
						/ 2.0;
			}
		}
		else if (nums2.size() == 0)
		{
			if (nums1.size() % 2 == 1)
			{
				return nums1[nums1.size() / 2];
			}
			else
			{
				return (nums1[nums1.size() / 2] + nums1[nums1.size() / 2 - 1])
						/ 2.0;
			}
		}
		int size1 = nums1.size();
		int size2 = nums2.size();
		int midline2 = (size1 + size2) / 2;
		int low = 0, high = size1 - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			int tmp = nums1[mid];
			int u = upbound_binary_search(tmp, nums2);
			int l = lowbound_binary_search(tmp, nums2);
			printf("mid:%d u:%d l:%d\n", mid, u, l);
			int offset = 0;
			if (l == -1)
				offset = 1;
			if (mid + l + offset <= midline2 && mid + u >= midline2)
			{
				int p;
				if (u != size2)
					p = min(tmp, (int) (nums2[u]));
				else
					p = tmp;
				int q;
				if (l != -1)
					q = max(tmp, (int) (nums2[l]));
				else
					q = tmp;
				if ((size1 + size2) % 2 == 0)
				{
					printf("p:%d, q:%d\n", p, q);
					return 1.0 * (q + p) / 2.0;
				}
				else
				{
					if (mid + u == midline2)
						return p;
					else
						return q;
				}
			}
			else if (mid + l + offset > midline2)
			{
				high = mid - 1;
	        }
			else
			{
				low = mid + 1;
			}
		}
		low = 0, high = size2 - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			int tmp = nums2[mid];
			int u = upbound_binary_search(tmp, nums1);
			int l = lowbound_binary_search(tmp, nums1);
			int offset = 0;
			if (l == -1)
				offset = 1;
			if (mid + l + offset <= midline2 && mid + u >= midline2)
			{
				int p;
				if (u != size2)
					p = min(tmp, (int) (nums1[u]));
				else
					p = tmp;
				int q;
				if (l != -1)
					q = max(tmp, (int) (nums1[l]));
				else
					q = tmp;
				if ((size1 + size2) % 2 == 0)
				{
					printf("p:%d, q:%d\n", p, q);
					return 1.0 * (q + p) / 2.0;
				}
				else
				{
					if (mid + u == midline2)
						return p;
					else
						return q;
				}
			}
			else if (mid + l + offset > midline2)
			{
				high = mid - 1;
		    }
			else
			{
				low = mid + 1;
			}
		}
	}

	int upbound_binary_search(int x, vector<int>& nums)
	{
		int low = 0, high = nums.size() - 1;
		int ret = -1;
		int upper_bound = nums.size();
		while (low <= high)
		{
			int mid = (low + high) / 2;
			int tmp = nums[mid];
			if (tmp == x)
			{
				ret = mid;
				low = mid + 1;
			}
			else if (tmp > x)
			{
				high = mid - 1;
				upper_bound = mid;
			}
			else
			{
				low = mid + 1;
			}
		}
		if (ret != -1)
			return ret;
		return upper_bound;
	}

	int lowbound_binary_search(int x, vector<int>& nums)
	{
		int low = 0, high = nums.size() - 1;
		int ret = -1;
		int lower_bound = -1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			int tmp = nums[mid];
			if (tmp == x)
			{
				ret = mid;
				high = mid - 1;
			}
			else if (tmp > x)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
				lower_bound = mid;
			}
		}
		if (ret != -1)
			return ret;
		return lower_bound;
	}

	int min(int a, int b)
	{
		return a > b ? b : a;
	}

	int max(int a, int b)
	{
		return a > b ? a : b;
	}

	int get_high(double x)
	{
		return (int) (x + 1.0);
	}
	int get_low(double x)
	{
		return (int) x;
	}
};


