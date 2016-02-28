/*
 * solveSudoku.cpp
 *
 *  Created on: 2016年1月24日
 *      Author: chenyulin
 */

/*
 * isValidSudoku.cpp
 *
 *  Created on: 2016年1月23日
 *      Author: chenyulin
 */

#include "def.h"
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
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
        		hashRowVec[i][num] = 1;
        		hashColVec[j][num] = 1;
        		int boxIdx = (i/3) * 3 + (j/3);
        		hashBoxVec[boxIdx][num] = 1;
        	}
        }
    	dfs(board, hashRowVec, hashColVec, hashBoxVec, 0);
    }

    typedef vector<vector<char> > CharVecVec;
    typedef vector<vector<int> > IntVecVec;
    bool dfs(CharVecVec& board, IntVecVec& hashRowVec, IntVecVec& hashColVec, IntVecVec& hashBoxVec, int step)
    {
    	if (step == 81)
    	{
    		return true;
    	}
    	int i = step / 9;
    	int j = step % 9;
    	if (board[i][j] != '.')
    	{
    		return dfs(board, hashRowVec, hashColVec, hashBoxVec, step + 1);
    	}
    	else
    	{
    		for (int num = 1; num <= 9; ++num)
    		{
    			int boxIdx = (i/3) * 3 + (j/3);
    			if (hashRowVec[i][num] == 0 && hashColVec[j][num] == 0 && hashBoxVec[boxIdx][num] == 0)
    			{
    				hashRowVec[i][num] = 1;
    				hashColVec[j][num] = 1;
    				hashBoxVec[boxIdx][num] = 1;
    				board[i][j] = '0' + num;
    				if (dfs(board, hashRowVec, hashColVec, hashBoxVec, step + 1))
    				{
    					return true;
    				}
    				hashRowVec[i][num] = 0;
    				hashColVec[j][num] = 0;
    				hashBoxVec[boxIdx][num] = 0;
    				board[i][j] = '.';
    			}
    		}
    	}
    	return false;
    }
};





