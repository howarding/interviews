//Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.
//
//Example 1:
//    0          3
//    |          |
//    1 --- 2    4
//Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.
//
//Example 2:
//    0           4
//    |           |
//    1 --- 2 --- 3
//Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.
//
//Note:
//You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution_323 {
public:
    // Exp: https://discuss.leetcode.com/topic/34498/java-concise-dfs
    // DFS
    // Time:	O(n)
    // Space:	O(n)
    int countComponents(int n, vector<pair<int, int>> &edges) {
        int count = 0;
        if (edges.empty()) return n;
        unordered_map<int, vector<int>> links;
        for (auto &edge : edges) {
            links[edge.first].push_back(edge.second);
            links[edge.second].push_back(edge.first);
        }
        unordered_set<int> visited;
        for (int i = 0; i < n; i++)
            if (visited.find(i) == visited.end()) {
                dfs(i, links, visited);
                count++;
            }
        return count;
    }

    void dfs(int node, unordered_map<int, vector<int>> &links, unordered_set<int> &visited) {
        visited.insert(node);
        if (links[node].empty()) return;
        for (int neighbor : links[node])
            if (visited.find(neighbor) == visited.end())
                dfs(neighbor, links, visited);
    }


    // BFS
    int countComponents_1(int n, vector<pair<int, int>> &edges) {
        int count = 0;
        if (edges.empty()) return n;
        unordered_map<int, vector<int>> links;
        for (auto &edge : edges) {
            links[edge.first].push_back(edge.second);
            links[edge.second].push_back(edge.first);
        }
        unordered_set<int> visited;
        queue<int> nodes;
        for (int i = 0; i < n; i++)
            if (visited.find(i) == visited.end()) {
                nodes.push(i);
                count++;
                while (!nodes.empty()) {
                    int node = nodes.front();
                    nodes.pop();
                    visited.insert(node);
                    for (int neighbor : links[node])
                        if (visited.find(neighbor) == visited.end())
                            nodes.push(neighbor);
                }
            }
        return count;
    }


    // Union Find
    int countComponents_2(int n, vector<pair<int, int>> &edges) {

    }
};