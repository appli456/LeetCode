#pragma once
#ifndef __304__NUMMATRIX_H__
#define __304__NUMMATRIX_H__
#include <vector>
using std::vector;
class NumMatrix {
public:
	NumMatrix(vector<vector<int>> matrix) {
		if(!matrix.size())
		{
			return;
		}
		size_t col = matrix[0].size();
		sums = vector<vector<int>>(matrix.size(), vector<int>(col, 0));
		for(int i = 0; i < matrix.size(); ++i)
		{
			for(int j = 0; j < matrix[i].size(); ++j)
			{
				if(i == 0 && j == 0)
				{
					sums[i][j] = matrix[i][j];
				}
				else
				{
					sums[i][j] = matrix[i][j] + 
						(i <= 0 ? 0 : sums[i - 1][j]) +  
						(j <= 0 ? 0 : sums[i][j - 1]) - 
						(i <= 0 || j <= 0 ? 0 : sums[i - 1][j - 1]);
				}
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		if(row2 >= sums.size())
		{
			row2 = sums.size() - 1;
		}
		if (row2 < 0 && !sums.size())
		{
			return 0;
		} 
		else if(col2 >= sums[0].size())
		{
			col2 = sums[0].size() - 1;
		}

		return sums[row2][col2] - 
			(col1 - 1 >= 0 ? sums[row2][col1 - 1] : 0) - 
			(row1 - 1 >= 0 ? sums[row1 - 1][col2] : 0) + 
			(col1 - 1 >= 0 || row1 - 1 >= 0 ? sums[row1 - 1][col1 - 1] : 0);
	}

private:
	vector<vector<int>>sums;
};

/**
* Your NumMatrix object will be instantiated and called as such:
* NumMatrix obj = new NumMatrix(matrix);
* int param_1 = obj.sumRegion(row1,col1,row2,col2);
*/
#endif