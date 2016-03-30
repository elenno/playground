/*
 * nqueen.cpp
 *
 *  Created on: 2016年3月26日
 *      Author: chenyulin
 */

#include "def.h"

class Solution
{
public:

	void dfs(int n, int step, vector<vector<string> >& ans, int& x, int& y,
			int& yy, int& z, int& zz, vector<string>& tmp)
	{
		if (step == n)
		{
			ans.push_back(tmp);
			for (int i = 0; i < n; i++)
			{
			    cout << tmp[i] << endl;
			}
			cout << endl;
			return;
		}
		std::string str(n, '.');
		for (int i = 0; i < n; i++)
		{
		    int j = n - i - 1;
		    int a = step - j;
		    int b = j - step;

			int p = step - i;
			int q = i - step;
			if (((1 << i) & x) > 0)
				continue;
			if (i >= step && ((1 << q) & y) > 0)
				continue;
			if (i <= step && ((1 << p) & yy) > 0)
				continue;
			if (j >= step && ((1 << b) & z) > 0)
				continue;
			if (j <= step && ((1 << a) & zz) > 0)
				continue;

			x += (1 << i);
			if (i >= step)
			{
				y += (1 << q);
			}
			else if (i <= step)
			{
			    yy += (1 << p);
			}
			if (j >= step)
			{
			    z += (1 << b);
			}
			else if (j <= step)
			{
				zz += (1 << a);
			}
			str[i] = 'Q';
			tmp.push_back(str);
			dfs(n, step + 1, ans, x, y, yy, z, zz, tmp);
			tmp.pop_back();
			str[i] = '.';
			x -= (1 << i);
			if (i >= step)
			{
				y -= (1 << q);
			}
			else if (i <= step)
			{
			    yy -= (1 << p);
			}
			if (j >= step)
			{
			    z -= (1 << b);
			}
			else if (j <= step)
			{
				zz -= (1 << a);
			}
		}
	}

	vector<vector<string>> solveNQueens(int n)
	{
	    //n = 5;
		vector<vector<string> > ret;
		int x = 0;
		int y = 0;
		int z = 0;
		int yy = 0;
		int zz = 0;
		vector<string> tmp;
		dfs(n, 0, ret, x, y, yy, z, zz, tmp);
		return ret;
	}
};

int main()
{
	int n = 9;
	Solution s;
	vector<vector<string> > ret = s.solveNQueens(n);
	return 0;
}

