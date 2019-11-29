//On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.
//Now, a move consists of removing a stone that shares a column or row with another stone on the grid.
//What is the largest possible number of moves we can make?
//
//
//
//Example 1:
//
//    Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
//    Output: 5
//Example 2:
//
//    Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
//    Output: 3
//Example 3:
//
//    Input: stones = [[0,0]]
//    Output: 0
//
//
//Note:
//
//    1. 1 <= stones.length <= 1000
//    2. 0 <= stones[i][j] < 10000

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution_947 {
public:
    // Union Find
    // Time:    O(n^2)  Faster
    // Space:   O(n)
    int removeStones1(vector<vector<int>>& stones) {
        unordered_map<int, unordered_set<int>> adj;
        vector<int> parent(stones.size());
        vector<int> sz(stones.size());
        int count = stones.size();
        for (int i = 0; i < stones.size(); i++) {
            parent[i] = i;
            sz[i] = 1;
        }

        for (int i = 0; i < stones.size(); i++)
            for (int j = i + 1; j < stones.size(); j++)
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    int root_i = find(parent, i);
                    int root_j = find(parent, j);
                    if (root_i == root_j) continue;
                    if (sz[root_i] < sz[root_j]) {
                        parent[root_i] = root_j;
                        sz[root_j] += sz[root_i];
                    } else {
                        parent[root_j] = root_i;
                        sz[root_i] += sz[root_j];
                    }
                    count--;
                }
        return stones.size() - count;
    }

    int find(vector<int>& parent, int i) {
        while (parent[i] != i) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }


    // DFS
    // Time:    O(n^2)
    // Space:   O(n^2)
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, unordered_set<int>> adj;
        unordered_set<int> visited;
        int result = 0;

        for (int i = 0; i < stones.size(); i++)
            for (int j = i + 1; j < stones.size(); j++)
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    adj[i].insert(j);
                    adj[j].insert(i);
                }

        for (int i = 0; i < stones.size(); i++)
            if (visited.find(i) == visited.end())
                result += dfs(adj, visited, i);

        return result;
    }

    int dfs(unordered_map<int, unordered_set<int>>& adj, unordered_set<int>& visited, int node) {
        visited.insert(node);
        int result = 0;
        for (int neighbor: adj[node])
            if (visited.find(neighbor) == visited.end())
                result += 1 + dfs(adj, visited, neighbor);
        return result;
    }
};


//int main() {
//    Solution_947 sol;
////    vector<vector<int>> stones{{3, 2}, {0, 0}, {3, 3}, {2, 1}, {2, 3}, {2, 2}, {0, 2}};
//    vector<vector<int>> stones{{4, 4}, {5, 5}, {3, 1}, {1, 4}, {1, 1}, {2, 3}, {0, 3}, {2, 4}, {3, 5}};
//    int result = sol.removeStones1(stones);
//    cout << result << endl;
//}