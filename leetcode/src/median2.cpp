/*
 * median2.cpp
 *
 *  Created on: 2015年8月29日
 *      Author: chenyulin
 *        Idea: 对两个数组的最大最小值做二分， 对于二分的值， 若其下界在中位线以下， 上界在中位线以上，
 *              则这个值附近的元素就是中位数所在
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
		//int midline1 = (size1 + size2) % 2 == 0 ? (midline2 - 1) : midline2;
		int a = nums1[0], b = nums2[0], c = nums1[nums1.size() - 1], d =
				nums2[nums2.size() - 1];
		int low = min(a, b);
		int high = max(c, d);
		printf("low:%d, high:%d, midline1:%d, midline2:%d\n", low, high,
				midline2, midline2);
		double mid = (low + high) / 2.0;
		while (low <= high)
		{
			mid = (low + high) / 2.0;
			int u1 = upbound_binary_search(mid, nums1);
			int u2 = upbound_binary_search(mid, nums2);
			int l1 = lowbound_binary_search(mid, nums1);
			int l2 = lowbound_binary_search(mid, nums2);
			printf("mid:%.2f, u1:%d, u2:%d, l1:%d, l2:%d\n", mid, u1, u2, l1,
					l2);
			int idx1 = 0, idx2 = 0;
			if (l1 == -1)
			{
				idx1 += l2;
				if (nums2[l2] != mid)
					idx1++;
			}
			else if (l2 == -1)
			{
				idx1 += l1;
				if (nums1[l1] != mid)
					idx1++;
			}
			else
			{
				idx1 = l1 + l2;
				if (nums1[l1] != mid)
					idx1++;
				if (nums2[l2] != mid)
					idx1++;
			}

			idx2 = u1 + u2;
			if (u1 == size1 && u2 == size2)
				idx2++;
			printf("idx1:%d, idx2:%d\n", idx1, idx2);

			if (idx2 >= midline2 && idx1 <= midline2)
			{
				int p;
				if (u1 != size1 && u2 != size2)
				{
					p = min((int) (nums1[u1]), (int) (nums2[u2]));
				}
				else if (u1 != size1)
				{
					p = nums1[u1];
				}
				else
				{
					p = nums2[u2];
				}

				int q;
				if (l1 != -1 && l2 != -1)
				{
					q = max((int) (nums1[l1]), (int) (nums2[l2]));
				}
				else if (l1 != -1)
				{
					q = nums1[l1];
				}
				else
				{
					q = nums2[l2];
				}
				if ((size1 + size2) % 2 == 0)
				{
					printf("p:%d, q:%d\n", p, q);
				    return 1.0 * (q + p) / 2.0;
				}
				else
				{
					if (idx2 == midline2)
						return p;
					else
						return q;
				}

				//return mid;
			}
			else if (idx1 > midline2)
			{
				high = get_low(mid);
			}
			else
			{
				low = get_high(mid);
			}
		}
		return mid;
	}

	int upbound_binary_search(double x, vector<int>& nums)
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

	int lowbound_binary_search(double x, vector<int>& nums)
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

//int main()
//{
//	int a[] =
//	{ 1,2 };
//	int b[] =
//	{ 1,2 };
//	vector<int> nums1(a, a + sizeof(a) / sizeof(int));
//	vector<int> nums2(b, b + sizeof(b) / sizeof(int));
//	Solution s;
//	printf("%.2f\n", s.findMedianSortedArrays(nums1, nums2));
//	return 0;
//}

