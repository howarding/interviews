//Given a game board, represented as 2D array of zeroes and ones. Zero stands for possible positions and one stands for
// impossible positions. Design an algorithm to find a path from top left corner to bottom right corner. For example,
// given a board of the following, a possible path is denoted by + on the second board.
//
//    0000000
//    0010010
//    0010110
//    0010101
//    1110000
//
//Possible path:
//
//    ++++000
//    001+010
//    001+110
//    001+101
//    111++++
//
//For this question, let's return (0, 0)->(0,1)->(0,2)->(0,3)->(1,3)->(2,3)->(3,3)->(4,3)->(4,4)->(4,5)->(4,6)
//
//Follow Up: Return the shortest path.

#include <vector>
#include <queue>

using namespace std;

class Maze {
public:
    // DFS      NOT shortest path.
    // Time:    O(mn)
    // Space:   O(mn)
    vector<vector<int>> getPath(vector<vector<int>>& maze) {
        vector<vector<int>> result;
        if (maze.empty()) return result;
        vector<vector<int>> visited(maze.size(), vector<int>(maze[0].size(), 0));
        vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        dfs(maze, 0, 0, result, visited, directions);
        return result;
    }

    bool dfs(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& path, vector<vector<int>>& visited,
            vector<vector<int>>& directions) {
        if (x == maze.size() - 1 && y == maze[0].size() - 1) {
            path.push_back({x, y});
            return true;
        }
        if (x < 0 || x >= maze.size() || y < 0 || y >= maze[0].size() || maze[x][y] || visited[x][y])
            return false;
        visited[x][y] = 1;
        path.push_back({x, y});
        for (const vector<int>& dir: directions)
            if (dfs(maze, x + dir[0], y + dir[1], path, visited, directions)) return true;
        path.pop_back();
        return false;
    }

    // BFS      SHORTEST path.
    // Time:    O(mn)
    // Space:   O(mn)
    vector<vector<int>> getShortestPath(vector<vector<int>>& maze) {
        vector<vector<int>> result;
        if (maze.empty()) return result;
        vector<vector<int>> indices(maze.size(), vector<int>(maze[0].size(), -1));
        vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int m = maze.size(), n = maze[0].size();
        queue<vector<int>> que;
        que.push({0, 0});
        indices[0][0] = 0;
        while (!que.empty()) {
            vector<int> point = que.front();
            que.pop();
            if (point[0] == m - 1 && point[1] == n - 1) break;
            int idx = point[0] * n + point[1];
            for (const vector<int>& dir: directions) {
                int i = point[0] + dir[0];
                int j = point[1] + dir[1];
                if (i >= 0 && i < m && j >= 0 && j < n && maze[i][j] == 0 && indices[i][j] == -1) {
                    indices[i][j] = idx;
                    que.push({i, j});
                }
            }
        }
        if (indices[m - 1][n - 1] == -1) return result;     // No path from start to end.
        int i = m - 1, j = n - 1;
        while (i > 0 || j > 0) {
            result.push_back({i, j});
            int idx = indices[i][j];
            i = idx / n;
            j = idx % n;
        }
        result.push_back({0, 0});
        reverse(result.begin(), result.end());
        return result;
    }
};