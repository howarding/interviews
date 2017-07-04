//Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
//Note: You can only move either down or right at any point in time.

#include <iostream>
#include <vector>

using namespace std;

class Solution_064 {
public:
    // DP (My own)
    // Time:	O(mn)
    // Space:	O(n)
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> val(n, 0);
        val[0] = grid[0][0];
        for(int i = 1; i < n; i++)
            val[i] = val[i-1] + grid[0][i];
        for(int i = 1; i < m; i++){
            val[0] += grid[i][0];
            for(int j = 1; j < n; j++)
                val[j] = min(val[j-1], val[j]) + grid[i][j];
        }
        return val[n-1];
    }
};