// 304.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NumMartix.h"

int main()
{
	NumMatrix* num_matrix = new NumMatrix(vector<vector<int>>(1, vector<int>({ -4, -5 })));
	num_matrix->sumRegion(0, 0, 0, 0);
	num_matrix->sumRegion(0, 0, 0, 1);
	num_matrix->sumRegion(0, 1, 0, 1);
	system("pause");
    return 0;
}

