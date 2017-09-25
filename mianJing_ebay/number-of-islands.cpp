//Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
//Example 1:
//
//    11110
//    11010
//    11000
//    00000
//Answer: 1
//
//Example 2:
//
//    11000
//    11000
//    00100
//    00011
//Answer: 3

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution_noi {
public:
//    1. 一个矩阵，0和1，找出连接着的，并且数量最多的1，输出个数

    // BFS
    int numIslands_f1(vector<vector<char>>& grid) {
        int result = 0;
        if (grid.empty()) return result;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> directions = {{1,  0},
                                          {-1, 0},
                                          {0,  1},
                                          {0,  -1}};
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!visited[i][j] && grid[i][j] == '1')
                    result = max(result, bfs(m, n, i, j, directions, grid, visited));
        return result;
    }

    int bfs(
            int m,
            int n,
            int i,
            int j,
            vector<vector<int>>& directions,
            vector<vector<char>>& grid,
            vector<vector<bool>>& visited
    ) {
        int count = 0;
        visited[i][j] = true;
        queue<vector<int>> nodes;
        nodes.push({i, j});
        grid[i][j] = '0';
        while (!nodes.empty()) {
            auto &node = nodes.front();
            nodes.pop();
            count++;
            for (auto &direction : directions) {
                auto neighbor = vector<int>({node[0] + direction[0], node[1] + direction[1]});
                if (neighbor[0] < 0 || neighbor[0] == m || neighbor[1] < 0 || neighbor[1] == n)
                    continue;
                if (!visited[neighbor[0]][neighbor[1]] && grid[neighbor[0]][neighbor[1]] == '1') {
                    nodes.push(neighbor);
                    visited[neighbor[0]][neighbor[1]] = true;
                }
            }
        }
        return count;
    }



    // DFS recursive    FASTER than BFS
    int numIslands_f12(vector<vector<char>> &grid) {
        int result = 0;
        if (grid.empty()) return result;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1') {
                    result = max(result, dfs(m, n, i, j, grid, visited));
                }
        return result;
    }

    int dfs(int m, int n, int i, int j, vector<vector<char>> &grid, vector<vector<bool>>& visited) {
        if (i < 0 || i == m || j < 0 || j == n || visited[i][j])
            return 0;
        // 如果是锯齿状数组：
        // 1 0 0 1 1 1
        // 1 0 1 0 0
        // 0 0 0 0 0 0 1
        // 1 1 1
        // if (i < 0 || i == m || j < 0 || j >= grid[i].size() || grid[i][j] == '0')
        //     return;
        visited[i][j] = true;
        return dfs(m, n, i - 1, j, grid, visited)
               + dfs(m, n, i + 1, j, grid, visited)
               + dfs(m, n, i, j - 1, grid, visited)
               + dfs(m, n, i, j + 1, grid, visited);
    }


//    2. 但是要把1的path（坐标）给打印出来

};