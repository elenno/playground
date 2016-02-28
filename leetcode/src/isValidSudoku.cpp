/*
 * isValidSudoku.cpp
 *
 *  Created on: 2016年1月23日
 *      Author: chenyulin
 */

#include "def.h"
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int> > hashColVec, hashRowVec, hashBoxVec;
        hashColVec.resize(9);
        hashRowVec.resize(9);
        hashBoxVec.resize(9);
        for (int i = 0; i < 9; i++)
        {
        	hashColVec[i].resize(10, 0);
        	hashRowVec[i].resize(10, 0);
        	hashBoxVec[i].resize(10, 0);
        }

    	for (int i = 0; i < 9; i++)
        {
        	for (int j = 0; j < 9; j++)
        	{
        		if (board[i][j] == '.')
        			continue;
        		int num = (int)(board[i][j] - '0');
        		if (hashRowVec[i][num] > 0)
        		{
        			cout << "row i:" << i << " j:" << j  << " num:" << num << endl;
        			return false;
        		}
        		hashRowVec[i][num] = 1;
        		if (hashColVec[j][num] > 0)
        		{
        			cout << "col i:" << i << " j:" << j << endl;
        		    return false;
        		}
        		hashColVec[j][num] = 1;
        		int boxIdx = (i/3) * 3 + (j/3);
        		if (hashBoxVec[boxIdx][num] > 0)
        		{
        			cout << "box i:" << i << " j:" << j << " idx:" << boxIdx << endl;
        			return false;
        		}
        		hashBoxVec[boxIdx][num] = 1;
        	}
        }
    	return true;
    }
};


