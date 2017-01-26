//Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
//The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
//Note that you can only put the bomb at an empty cell.
//
//Example:
//    For the given grid
//
//    0 E 0 0
//    E 0 W E
//    0 E 0 0
//
//    return 3. (Placing a bomb at (1,1) kills 3 enemies)

#include <iostream>
#include <vector>

using namespace std;

class Solution_361 {
public:
    // Exp: https://discuss.leetcode.com/topic/48565/short-o-mn-solution
    // Time:	O(mn)
    // Space:	O(n)
    int maxKilledEnemies(vector<vector<char>> &grid) {
        int result = 0;
        if (grid.empty()) return result;
        int m = grid.size(), n = grid[0].size();
        int row = 0;
        vector<int> column(n, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (!j || grid[i][j - 1] == 'W') {
                    row = 0;
                    for (int k = j; k < n && grid[i][k] != 'W'; k++)
                        row += grid[i][k] == 'E';
                }
                if (!i || grid[i - 1][j] == 'W') {
                    column[j] = 0;
                    for (int k = i; k < m && grid[k][j] != 'W'; k++)
                        column[j] += grid[k][j] == 'E';
                }
                if (grid[i][j] == '0')
                    result = max(result, row + column[j]);
            }
        return result;
    }
};