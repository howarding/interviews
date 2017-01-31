//Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
//
//For example:
//
//Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
//
//Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
//
//Hint:
//
//    1. Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
//    2. According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
//Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution_261 {
public:
    // DFS
    // Time:	O(n)
    // Space:	O(n)
    bool validTree(int n, vector<pair<int, int>> &edges) {
        int num = edges.size();
        if (num != n - 1) return false;
        unordered_map<int, vector<int>> links;
        for (auto edge : edges) {
            links[edge.first].push_back(edge.second);
            links[edge.second].push_back(edge.first);
        }
        unordered_set<int> visited;
        return dfs(-1, edges[0].first, links, visited) && visited.size() == n;
    }

    bool dfs(int parent, int node, unordered_map<int, vector<int>> &links, unordered_set<int> &visited) {
        bool result = true;
        visited.insert(node);
        for (int neighbor : links[node]) {
            if (neighbor == parent) continue;
            if (visited.find(neighbor) != visited.end()) return false;
            visited.insert(neighbor);
            result &= dfs(node, neighbor, links, visited);
        }
        return result;
    }
};