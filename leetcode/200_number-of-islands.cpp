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

class Solution_200 {
public:
    // BFS
    // Time:    O(n)
    // Space:    O(n)
    int numIslands(vector<vector<char>> &grid) {
        int count = 0;
        if (grid.empty()) return count;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> directions = {{1,  0},
                                          {-1, 0},
                                          {0,  1},
                                          {0,  -1}};
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1') {
                    bfs(m, n, i, j, directions, grid);
                    count++;
                }
        return count;
    }

    void bfs(int m, int n, int i, int j, vector<vector<int>> &directions, vector<vector<char>> &grid) {
        queue<vector<int>> nodes;
        nodes.push({i, j});
        grid[i][j] = '0';
        while (!nodes.empty()) {
            auto &node = nodes.front();
            nodes.pop();
            for (auto &direction : directions) {
                auto neighbor = vector<int>({node[0] + direction[0], node[1] + direction[1]});
                if (neighbor[0] < 0 || neighbor[0] == m || neighbor[1] < 0 || neighbor[1] == n)
                    continue;
                if (grid[neighbor[0]][neighbor[1]] == '1') {
                    nodes.push(neighbor);
                    grid[neighbor[0]][neighbor[1]] = '0';
                }
            }
        }
    }

    // DFS recursive    FASTER than BFS
    // Exp: https://discuss.leetcode.com/topic/13248/very-concise-java-ac-solution
    int numIslands_1(vector<vector<char>> &grid) {
        int count = 0;
        if (grid.empty()) return count;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1') {
                    dfs(m, n, i, j, grid);
                    count++;
                }
        return count;
    }

    void dfs(int m, int n, int i, int j, vector<vector<char>> &grid) {
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0')
            return;
        // 如果是锯齿状数组：
        // 1 0 0 1 1 1
        // 1 0 1 0 0
        // 0 0 0 0 0 0 1
        // 1 1 1
        // if (i < 0 || i == m || j < 0 || j >= grid[i].size() || grid[i][j] == '0')
        //     return;
        grid[i][j] = '0';
        dfs(m, n, i - 1, j, grid);
        dfs(m, n, i + 1, j, grid);
        dfs(m, n, i, j - 1, grid);
        dfs(m, n, i, j + 1, grid);
    }


    // DFS non recursive    stack
    int numIslands_2(vector<vector<char>> &grid) {
        int count = 0;
        if (grid.empty()) return count;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> directions = {{1,  0},
                                          {-1, 0},
                                          {0,  1},
                                          {0,  -1}};
        stack<vector<int>> stk;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1') {
                    stk.push({i, j});
                    while (!stk.empty()) {
                        auto &node = stk.top();
                        stk.pop();
                        if (grid[node[0]][node[1]] == '1') {
                            grid[node[0]][node[1]] = '0';
                            for (auto &direction : directions) {
                                auto neighbor = vector<int>({node[0] + direction[0], node[1] + direction[1]});
                                if (neighbor[0] < 0 || neighbor[0] == m || neighbor[1] < 0 || neighbor[1] == n)
                                    continue;
                                if (grid[neighbor[0]][neighbor[1]] == '1')
                                    stk.push(neighbor);
                            }
                        }
                    }
                    count++;
                }
        return count;
    }

    // Union-Find

};


//int main() {
//    vector<vector<char>> grid = {
//        {'1', '1', '1', '1', '0'},
//        {'1', '1', '0', '1', '0'},
//        {'1', '1', '0', '0', '0'},
//        {'0', '0', '0', '0', '0'}};
//    Solution_200 sol;
//    cout << sol.numIslands(grid) << endl;
//}