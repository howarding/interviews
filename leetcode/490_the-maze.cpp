//There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
//
//Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.
//
//The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.
//
//Example 1
//
//    Input 1: a maze represented by a 2D array
//
//    0 0 1 0 0
//    0 0 0 0 0
//    0 0 0 1 0
//    1 1 0 1 1
//    0 0 0 0 0
//
//    Input 2: start coordinate (rowStart, colStart) = (0, 4)
//    Input 3: destination coordinate (rowDest, colDest) = (4, 4)
//
//    Output: true
//    Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
//
//Example 2
//
//    Input 1: a maze represented by a 2D array
//
//    0 0 1 0 0
//    0 0 0 0 0
//    0 0 0 1 0
//    1 1 0 1 1
//    0 0 0 0 0
//
//    Input 2: start coordinate (rowStart, colStart) = (0, 4)
//    Input 3: destination coordinate (rowDest, colDest) = (3, 2)
//
//    Output: false
//    Explanation: There is no way for the ball to stop at the destination.
//
//Note:
//    1. There is only one ball and one destination in the maze.
//    2. Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
//    3. The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
//    4. The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution_490 {
public:
    // Exp: https://discuss.leetcode.com/topic/77590/simple-c-dfs-solution-using-set-to-mark-the-visited-end-points
    // DFS
    // Time:	O(mn)
    // Space:	O(mn)
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        bool result = false;
        if (maze.empty()) return false;
        int m = maze.size(), n = maze[0].size();
        int x = start[0], y = start[1];
        vector<vector<int>> directions = {{1,  0},
                                          {-1, 0},
                                          {0,  1},
                                          {0,  -1}};
        unordered_set<int> visited;
        visited.insert(x * n + y);

        for (int k = 0; k < 4; k++)
            result |= dfs(maze, start, destination, visited, directions, k);
        return result;
    }

    bool dfs(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination, unordered_set<int> &visited,
             vector<vector<int>> &directions, int k) {
        int m = maze.size(), n = maze[0].size();
        int i = start[0], j = start[1], di = directions[k][0], dj = directions[k][1];
        bool result = false;
        while (i >= 0 && i < m && j >= 0 && j < n && !maze[i][j]) {
            i += di;
            j += dj;
        }
        vector<int> hit({i - directions[k][0], j - directions[k][1]});
        if (hit == destination) return true;
        if (visited.find(hit[0] * n + hit[1]) != visited.end()) return false;
        visited.insert(hit[0] * n + hit[1]);
        for (int l = 0; l < 4; l++) {
            if (l == k) continue;
            result |= dfs(maze, hit, destination, visited, directions, l);
        }
//        visited.erase(hit[0] * n + hit[1]);
        return result;
    }
};