//You are given a m x n 2D grid initialized with these three possible values.
//
//    1. -1 - A wall or an obstacle.
//    2. 0 - A gate.
//    3. INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
//Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
//
//For example, given the 2D grid:
//    INF  -1  0  INF
//    INF INF INF  -1
//    INF  -1 INF  -1
//    0  -1 INF INF
//After running your function, the 2D grid should be:
//    3  -1   0   1
//    2   2   1  -1
//    1  -1   2  -1
//    0  -1   3   4

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution_286 {
public:
    // Exp: https://discuss.leetcode.com/topic/25265/java-bfs-solution-o-mn-time
    // BFS
    // Time:	O(mn)
    // Space:	O(1)
    void wallsAndGates(vector<vector<int>> &rooms) {
        if (rooms.empty()) return;
        int m = rooms.size(), n = rooms[0].size();
        queue<vector<int>> nodes;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (rooms[i][j] == 0)
                    nodes.push(vector<int>({i, j}));

        while (!nodes.empty()) {
            auto &node = nodes.front();
            nodes.pop();
            int i = node[0], j = node[1];
            if (i > 0 && rooms[i - 1][j] == INT_MAX) {
                rooms[i - 1][j] = rooms[i][j] + 1;
                nodes.push(vector<int>({i - 1, j}));
            }
            if (i < m - 1 && rooms[i + 1][j] == INT_MAX) {
                rooms[i + 1][j] = rooms[i][j] + 1;
                nodes.push(vector<int>({i + 1, j}));
            }
            if (j > 0 && rooms[i][j - 1] == INT_MAX) {
                rooms[i][j - 1] = rooms[i][j] + 1;
                nodes.push(vector<int>({i, j - 1}));
            }
            if (j < n - 1 && rooms[i][j + 1] == INT_MAX) {
                rooms[i][j + 1] = rooms[i][j] + 1;
                nodes.push(vector<int>({i, j + 1}));
            }
        }
    }
};