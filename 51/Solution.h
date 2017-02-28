#pragma once
#ifndef __51__SOLUTION_H__
#define __51__SOLUTION_H__
#include <vector>
#include <string>
using std::vector;
using std::string;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        if (n <= 0) 
        {
            return result;
        }
        vector<int>columns;
        search(n, columns, result);
        return result;
    }

    void search(int n, vector<int>& columns, vector<vector<string>>& result) 
    {
        if(columns.size() == n)
        {
            result.push_back(draw(columns, n));
            return;
        }
        for(int col = 0; col < n; col++)
        {
            if(!is_valid(columns, col))
            {
                continue;
            }
            columns.push_back(col);
            search(n, columns, result);
            columns.pop_back();
        }
    }

    bool is_valid(vector<int>& columns, int column) 
    {
        for(int i = 0; i < columns.size(); ++i) 
        {
            if (columns[i] == column || 
            i - columns[i] == columns.size() - column || 
            i + columns[i] == columns.size() + column) {
                return false;
            }
        }
        return true;
    }

    vector<string> draw (vector<int>& columns, int n) 
    {
        vector<string>result;
        for (int i = 0; i < columns.size(); ++i)
        {
            string row(n, '.');
            row[columns[i]] = 'Q';
            result.push_back(row);
        }

        return result;
    }
};

#endif