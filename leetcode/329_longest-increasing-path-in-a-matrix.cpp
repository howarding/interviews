//Given an integer matrix, find the length of the longest increasing path.
//
//From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
//
//Example 1:
//
//    nums = [
//    [9,9,4],
//    [6,6,8],
//    [2,1,1]
//    ]
//Return 4
//The longest increasing path is [1, 2, 6, 9].
//
//Example 2:
//
//    nums = [
//    [3,4,5],
//    [3,2,6],
//    [2,2,1]
//    ]
//Return 4
//The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

#include <iostream>
#include <vector>

using namespace std;

class Solution_329 {
public:
    // DFS + Memorization
    // Exp: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/solution/
    // Time:	O(mn)
    // Space:	O(mn)
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> cache(m, vector<int>(n, 0));
        int result = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                result = max(result, dfs(matrix, i, j, dirs, cache));
        return result;
    }

    int dfs(
            vector<vector<int>>& matrix,
            int i,
            int j,
            vector<vector<int>>& dirs,
            vector<vector<int>>& cache
    ) {
        if (cache[i][j]) return cache[i][j];
        int m = matrix.size(), n = matrix[0].size();
        for (auto&& dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j])
                cache[i][j] = max(cache[i][j], dfs(matrix, x, y, dirs, cache));
        }
        return ++cache[i][j];
    }
};