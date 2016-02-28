/*
 * DivideTwoIntegers.cpp
 *
 *  Created on: 2015年12月19日
 *      Author: chenyulin
 */

#include "def.h"

#define MAX_INT 2147483647
#define MIN_INT -2147483647
class Solution
{
public:
	int divide(int dividend, int divisor)
	{
		if (divisor == 0)
			return MAX_INT;
		if (dividend == 0)
			return 0;
		int ans = 0;
		int sign = 1;
		unsigned int dd = abs(dividend), ds = abs(divisor);
		if (dividend < 0 && divisor > 0 || divisor < 0 && dividend > 0)
		{
			sign = -1;
		}
		unsigned int ret = divide_pos_pos(dd, ds);
		cout << ret << endl;
		if (sign == -1)
		{
			return -ret;
		}
		if (ret > MAX_INT)
			return MAX_INT;
		return ret;
	}

	unsigned int divide_pos_pos(unsigned int dividend, unsigned int divisor)
	{
		unsigned int ans = 0;
		while (dividend >= divisor)
		{
			int cur = divisor;
			int times = 1;
			while (dividend >= cur)
			{
				if (dividend - cur < cur)
					break;
				cur += cur;
				times += times;

			}
			cout << times << " " << cur << endl;
			ans += times;
			dividend -= cur;
		}
		return ans;
	}

	int divide_neg_neg(int dividend, int divisor)
	{
		int ans = 0;
		while (dividend <= divisor)
		{
			int cur = divisor;
			int times = 1;
			while (dividend <= cur)
			{
				if (dividend - cur > cur)
					break;
				cur += cur;
				times += times;

			}
			cout << times << " " << cur << endl;
			ans += times;
			dividend -= cur;
		}
		return ans;
	}

	int divide_pos_neg(int dividend, int divisor)
		{
			int ans = 0;
			while (dividend <= divisor)
			{
				int cur = divisor;
				int times = 1;
				while (dividend <= cur)
				{
					if (dividend - cur > cur)
						break;
					cur += cur;
					times += times;

				}
				cout << times << " " << cur << endl;
				ans += times;
				dividend -= cur;
			}
			return ans;
		}
};

