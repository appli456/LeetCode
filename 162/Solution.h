#pragma once
#include <vector>

class Solution {
public:
    int findPeakElement(std::vector<int>& A) {
        // write your code here
        // if (A.size() == 1) { return 0; } 

        int left = 0;
        int right = A.size() - 1;
        int mid;
        while (left < right - 1)
        {
            mid = (left + right) / 2;
            if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) {
                return mid;
            }
            if (A[mid] > A[mid - 1]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return A[left] > A[right] ? left : right;
    }
};
