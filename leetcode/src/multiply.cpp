/*
 * multiply.cpp
 *
 *  Created on: 2016年2月27日
 *      Author: chenyulin
 */

#include "def.h"

class Solution {
public:
	char add_two_num(char a, char b, int& temp)
	{
		int ans = a - '0' + b - '0' + temp;
		temp = ans / 10;
		return ((char)(ans % 10 + '0'));
	}

	string add(string num1, string num2)
	{
		string ret = "";
		int temp = 0;
		int i = num1.length() - 1;
		int j = num2.length() - 1;
		for (; i >= 0 && j >= 0; i--, j--)
		{
			ret += add_two_num(num1[i], num2[j], temp);
		}
		for (; i>= 0; i--)
		{
			ret += add_two_num(num1[i], '0', temp);
		}
		for (; j>= 0; j--)
		{
			ret += add_two_num('0', num2[j], temp);
		}
		if (temp != 0)
		{
			ret += (char)('0' + temp);
		}
		reverse(ret.begin(), ret.end());
		cout << "ret:" << ret << endl;
		return ret;
	}

	string multi(string num, int times)
	{
		string ret = "";
		int temp = 0;
		for (int i = num.length() - 1; i >= 0; i--)
		{
			int ans = (num[i] - '0') * times + temp;
			temp = ans / 10;
			ret += (char)('0' + ans % 10);
		}
		if ( temp != 0)
		{
			ret += (char)('0' + temp);
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}

//    string multiply(string num1, string num2) {
//		if (num1 == "0" || num2 == "0")
//			return "0";
//    	string ret = "0";
//    	for (int j = num2.length() - 1, zero = 0; j >= 0; j--, zero++)
//    	{
//    		int times = num2[j] - '0';
//    		string tmp = "0";
//    		for (int k = 0; k < times; k++)
//    		{
//    			tmp = add(tmp, num1);
//    		}
//    		for (int l = 0; l < zero; l++)
//    		{
//    			tmp += '0';
//    		}
//    		cout << "tmp:" << tmp <<endl;
//    		ret = add(ret, tmp);
//    	}
//    	return ret;
//    }

//	string multiply(string num1, string num2)
//	{
//		if (num1 == "0" || num2 == "0")
//			return "0";
//		string ret = "0";
//		for (int j = num2.length() - 1, zero = 0; j >= 0; j--, zero++)
//		{
//			int times = num2[j] - '0';
//			string tmp = multi(num1, times);
//			for (int l = 0; l < zero; l++)
//			{
//				tmp += '0';
//			}
//			cout << "tmp:" << tmp << endl;
//			ret = add(ret, tmp);
//		}
//		return ret;
//	}

	//递推方法
	string multiply(string num1, string num2)
	{
		if (num1 == "0" || num2 == "0")
			return "0";
		vector<int> resVec;
		int n = num1.length();
		int m = num2.length();
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		resVec.resize(n + m + 2, 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				resVec[i + j] += (num1[i] - '0') * (num2[j] - '0');
			}
		}

		for (int i = 0; i < n + m + 1; i++)
		{
			int temp = resVec[i] / 10;
			resVec[i + 1] += temp;
			resVec[i] %= 10;
		}
		string ret = "";
		for (int i = 0; i < n + m + 2; i++)
		{
			ret += '0' + resVec[i];
		}
		cout << ret << endl;
		int pos = ret.length();
		for (int i = ret.length() - 1; i > 0; i--)
		{
			if (ret[i] != '0')
				break;
			pos = i;
		}
		ret = ret.substr(0, 0 + pos);
		cout << ret << endl;
		reverse(ret.begin(), ret.end());
		cout << ret << endl;
		return ret;
	}
};


