#include <iostream>
#include "Solution.h"
using namespace std;

void print(vector<vector<string>>container) {
    for (auto i : container) {
        for (auto j : i) {
            cout << j << endl;
        }

        cout << "===============" << endl;
    }
    cout << "------------------" << endl;
}

int main () 
{
    Solution *s = new Solution();
    print(s->solveNQueens(4));
    print(s->solveNQueens(8));
    return 0;
}