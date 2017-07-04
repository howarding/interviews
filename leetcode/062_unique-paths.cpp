//A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
//The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//
//How many possible unique paths are there?
//
//Above is a 3 x 7 grid. How many possible unique paths are there?
//
//Note: m and n will be at most 100.

#include <iostream>
#include <vector>

using namespace std;

class Solution_062 {
public:
    // DP (My own)
    // Time:	O(mn)
    // Space:	O(n)
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        vector<int> num(n, 0);
        for(int i = 0; i < n; i++)
            num[i] = 1;
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                num[j] += num[j-1];
        return num[n-1];
    }
};