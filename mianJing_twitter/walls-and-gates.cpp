//"Given a 2D matrix a two cells inside the matrix, find the length of the shortest path between the two points. The matrix have two types of cells: 0 and 1.
//You can pass through 0 cells, but not 1 cells. Also, you can only go up, down, left, right, but not outside the matrix or diagonally.
//Example 1:
//matrix:
//0, 0
//0, 0
//start: (0, 0), end (1, 1), then return 2
//start: (0, 0), end (0, 1), then return 1
//Example 2:
//matrix:
//0, 1, 0
//0, 1, 0
//0, 0, 0
//start (0, 0), end (0, 2), then return 6
//a. output shortest path length. b. output indexes of the path nodes. c. 如果node的间距不等怎么办 (dijastra算法，记录每个点的最短距离等等)"

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution_wg {
public:
    // Exp: https://discuss.leetcode.com/topic/25265/java-bfs-solution-o-mn-time
    // BFS
    // Time:	O(mn)
    // Space:	O(1)
    int shortestPathLength(vector<vector<int>> &rooms, vector<int>& start, vector<int>& end) {
        if (rooms.empty()) return -1;
        int m = rooms.size(), n = rooms[0].size();
        queue<vector<int>> nodes;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (rooms[i][j] == 1)
                    rooms[i][j] = -1;

        nodes.push(start);

        while (!nodes.empty()) {
            auto &node = nodes.front();
            nodes.pop();
            int i = node[0], j = node[1];
            if (end[0] == i && end[1] == j) return rooms[i][j];
            if (i > 0 && rooms[i - 1][j] != -1) {
                rooms[i - 1][j] = rooms[i][j] + 1;
                nodes.push(vector<int>({i - 1, j}));
            }
            if (i < m - 1 && rooms[i + 1][j] != -1) {
                rooms[i + 1][j] = rooms[i][j] + 1;
                nodes.push(vector<int>({i + 1, j}));
            }
            if (j > 0 && rooms[i][j - 1] != -1) {
                rooms[i][j - 1] = rooms[i][j] + 1;
                nodes.push(vector<int>({i, j - 1}));
            }
            if (j < n - 1 && rooms[i][j + 1] != -1) {
                rooms[i][j + 1] = rooms[i][j] + 1;
                nodes.push(vector<int>({i, j + 1}));
            }
        }
        return -1;
    }



    // Get the shortest path from start to end
    // 1. get shortest path length.
    // 2. DFS to get path.
    vector<vector<int>> shortestPath(vector<vector<int>> &rooms, vector<int>& start, vector<int>& end) {
        vector<vector<int>> result;
        if (rooms.empty()) return result;
        int m = rooms.size(), n = rooms[0].size();
        int len = shortestPathLength(rooms, start, end);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (rooms[i][j] == 1)
                    rooms[i][j] = -1;
        helper(rooms, start, end, len, result);
        return result;
    }

    bool helper(
            vector<vector<int>>& rooms,
            vector<int>& start,
            vector<int>& end,
            int count,
            vector<vector<int>>& result
    ) {
        int m = rooms.size(), n = rooms[0].size();
        int i = start[0], j = start[1];
        if (end[0] == i && end[1] == j && rooms[i][j] == count) return true;
        if (rooms[i][j] == count) return false;
        if (i > 0 && rooms[i - 1][j] == 0) {
            rooms[i - 1][j] = rooms[i][j] + 1;
            result.push_back({i-1, j});
            if (helper(rooms, result.back(), end, count, result)) return true;
            result.pop_back();
        }
        if (i < m - 1 && rooms[i + 1][j] == 0) {
            rooms[i + 1][j] = rooms[i][j] + 1;
            result.push_back({i+1, j});
            if (helper(rooms, result.back(), end, count, result)) return true;
            result.pop_back();
        }
        if (j > 0 && rooms[i][j - 1] == 0) {
            rooms[i][j - 1] = rooms[i][j] + 1;
            result.push_back({i, j-1});
            if (helper(rooms, result.back(), end, count, result)) return true;
            result.pop_back();
        }
        if (j < n - 1 && rooms[i][j + 1] == 0) {
            rooms[i][j + 1] = rooms[i][j] + 1;
            result.push_back({i, j+1});
            if (helper(rooms, result.back(), end, count, result)) return true;
            result.pop_back();
        }
        return false;
    }
};