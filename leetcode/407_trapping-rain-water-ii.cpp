//Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.
//
//Note:
//Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.
//
//Example:
//
//    Given the following 3x6 height map:
//    [
//        [1,4,3,1,3,2],
//        [3,2,1,3,2,4],
//        [2,3,3,2,3,1]
//    ]
//
//    Return 4.
//The above image represents the elevation map [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] before the rain.
//
//
//After the rain, water are trapped between the blocks. The total volume of water trapped is 4.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution_407 {
public:
    // BFS, heap
    // Exp: https://discuss.leetcode.com/topic/60418/java-solution-using-priorityqueue/23
    // Time:	O(n)
    // Space:	O(n)
    int trapRainWater(vector<vector<int>> &heightMap) {
        int result = 0;
        if (heightMap.empty()) return result;
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<cell *, vector<cell *>, cmp> min_heap;
        for (int i = 0; i < m; i++) {
            visited[i][0] = true;
            visited[i][n - 1] = true;
            min_heap.push(new cell(i, 0, heightMap[i][0]));
            min_heap.push(new cell(i, n - 1, heightMap[i][n - 1]));
        }

        for (int j = 1; j < n - 1; j++) {
            visited[0][j] = true;
            visited[m - 1][j] = true;
            min_heap.push(new cell(0, j, heightMap[0][j]));
            min_heap.push(new cell(m - 1, j, heightMap[m - 1][j]));
        }

        vector<vector<int>> dirs({{1,  0},
                                  {0,  1},
                                  {-1, 0},
                                  {0,  -1}});
        while (!min_heap.empty()) {
            cell *node = min_heap.top();
            min_heap.pop();
            for (auto &dir : dirs) {
                int i = node->i + dir[0];
                int j = node->j + dir[1];
                if (i < 0 || i == m || j < 0 || j == n || visited[i][j])
                    continue;
                result += max(0, node->height - heightMap[i][j]);
                visited[i][j] = true;
                min_heap.push(new cell(i, j, max(node->height, heightMap[i][j])));
            }
        }
        return result;
    }

    struct cell {
        int i;
        int j;
        int height;

        cell(int i, int j, int height) : i(i), j(j), height(height) {}
    };

    struct cmp {
        bool operator()(cell *a, cell *b) {
            return a->height > b->height;
        }
    };
};