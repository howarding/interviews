//Follow up for "Unique Paths":
//
//Now consider if some obstacles are added to the grids. How many unique paths would there be?
//
//An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
//For example,
//There is one obstacle in the middle of a 3x3 grid as illustrated below.
//
//    [
//      [0,0,0],
//      [0,1,0],
//      [0,0,0]
//    ]
//The total number of unique paths is 2.
//
//Note: m and n will be at most 100.

#include <iostream>
#include <vector>

using namespace std;

class Solution_063 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> num(n, 0);
        num[0] = 1;
        for (int j = 1; j < n; j++)
            num[j] = obstacleGrid[0][j] ? 0 : num[j-1];
        for (int i = 1; i < m; i++) {
            num[0] = obstacleGrid[i][0] ? 0 : num[0];
            for (int j = 1; j < n; j++)
                num[j] = obstacleGrid[i][j] ? 0 : num[j] + num[j-1];
        }
        return num[n-1];
    }
};


//int main() {
//    Solution_063 sol;
//    vector<vector<int>> obstacleGrid({{0}});
//    cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl;
//}