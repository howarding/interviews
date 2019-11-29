#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph {
    unordered_set<int> nodes;                  // # nodes
    unordered_map<int, unordered_set<int>> adj;  // adjacency list
public:
//    Graph();
    void addEdge(int v, int w) {
        nodes.insert(v);
        nodes.insert(w);
        adj[v].insert(w);
        adj[w].insert(v);
    }


    // BFS iterative
    void bfs() {
        queue<int> que;
        unordered_set<int> visited;
        for (int root : nodes) {
            if (visited.find(root) == visited.end()) {
                que.push(root);
                visited.insert(root);
                while (!que.empty()) {
                    int node = que.front();
                    que.pop();
                    cout << node << " ";
                    for (int neighbor : adj[node])
                        if (visited.find(neighbor) == visited.end()) {
                            que.push(neighbor);
                            visited.insert(neighbor);
                        }
                }
            }
        }
        cout << endl;
    }

    // DFS iterative
    // Similar to BFS, change queue to stack
    void dfs_iterative() {
        stack<int> stk;
        unordered_set<int> visited;
        for (int root : nodes) {
            if (visited.find(root) == visited.end()) {
                stk.push(root);
                visited.insert(root);
                while (!stk.empty()) {
                    int node = stk.top();
                    stk.pop();
                    cout << node << " ";
                    for (int neighbor : adj[node])
                        if (visited.find(neighbor) == visited.end()) {
                            stk.push(neighbor);
                            visited.insert(neighbor);
                        }
                }
            }
        }
        cout << endl;
    }

    // DFS recursive
    void dfs_recursive() {
        unordered_set<int> visited;
        for (int root : nodes)
            if (visited.find(root) == visited.end())
                helper(visited, root);
        cout << endl;
    }

    void helper(unordered_set<int> &visited, int node) {
        visited.insert(node);
        cout << node << " ";
        for (int neighbor : adj[node])
            if (visited.find(neighbor) == visited.end())
                helper(visited, neighbor);
    }
};


//int main() {
//    Graph g;
//    g.addEdge(1, 5);
//    g.addEdge(1, 0);
//    g.addEdge(2, 1);
//    g.addEdge(3, 4);
//    g.addEdge(4, 0);
//
//    g.bfs();
//    g.dfs_recursive();
//    g.dfs_iterative();
//}