#include<iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef int Node;

class Graph {
    unordered_map<Node, vector<Node>> adj;
    unordered_map<Node, size_t> indegree;
    unordered_set<Node> nodes;
public:
    Graph() {}

    ~Graph() {
//        delete adj1;
//        delete indegree1;
    }

    void addEdge(Node u, Node v) {
        adj[u].push_back(v);
        indegree[v]++;
        nodes.insert(u);
        nodes.insert(v);
    }

    // Kahn's Algorithm == BFS
    // Time:	O(V + E)
    // Space:	O(V)
    vector<Node> getTopologicalSort_BFS() {
        vector<Node> result;
        if (nodes.empty()) return result;

        queue<Node> que;
        for (const Node& node: nodes)
            if (indegree[node] == 0)
                que.push(node);     // start from those root nodes.

        int count = 0;
        while (!que.empty()) {
            Node node = que.front();
            que.pop();

            result.push_back(node);
            count++;

            for (const Node& neighbor: adj[node])
                if (--indegree[neighbor] == 0)
                    que.push(neighbor);
        }

        return count == nodes.size() ? result : vector<Node>();
    }

    // DFS + Stack
    // Time:	O(V + E)
    // Space:	O(V)
    vector<Node> getTopologicalSort_DFS() {
        vector<Node> result;
        if (nodes.empty()) return result;

        stack<Node> stk;
        unordered_set<Node> visited, onPath;

        for (const Node& node: nodes)
            if (visited.find(node) == visited.end() && !helper(node, visited, onPath, stk))
                return result;

        while (!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        return result;
    }

    bool helper(Node node, unordered_set<Node>& visited, unordered_set<Node>& onPath, stack<Node>& stk) {
        onPath.insert(node);
        visited.insert(node);
        for (Node& neighbor: adj[node])
            if (onPath.find(neighbor) != onPath.end()
            || (visited.find(neighbor) == visited.end() && !helper(neighbor, visited, onPath, stk)))
                return false;
        stk.push(node);
        onPath.erase(node);
        return true;
    }

    // Generate all Topological Sort
    vector<vector<Node>> getAllTopologicalSort() {
        unordered_set<Node> visited;
        vector<Node> path;
        vector<vector<Node>> result;
        helper2(visited, path, result);
        return result;
    }

    void helper2(unordered_set<Node>& visited, vector<Node>& path, vector<vector<Node>>& result) {
        if (path.size() == nodes.size()) {
            result.push_back(path);
            return;
        }
        for (const Node& node: nodes)
            if (indegree[node] == 0 && visited.find(node) == visited.end()) {
                path.push_back(node);
                visited.insert(node);
                for (Node& neighbor: adj[node])
                    indegree[neighbor]--;

                helper2(visited, path, result);

                path.pop_back();
                visited.erase(node);
                for (Node& neighbor: adj[node])
                    indegree[neighbor]++;
            }
    }
};


//int main() {
//    Graph graph;
//    graph.addEdge(5, 2);
//    graph.addEdge(5, 0);
//    graph.addEdge(4, 0);
//    graph.addEdge(4, 1);
//    graph.addEdge(2, 3);
//    graph.addEdge(3, 1);
//    // graph.addEdge(1, 5);     // to check whether topological sort can detect this cycle.
//
//    vector<Node> result1(graph.getTopologicalSort_BFS());
//    vector<Node> result2(graph.getTopologicalSort_DFS());
//    for (const Node& node: result2)
//        cout << node << "\t";
//    cout << endl;
//    vector<vector<Node>> result(graph.getAllTopologicalSort());
//    for (auto& path : result) {
//        for (Node& ele : path)
//            cout << ele << "\t";
//        cout << endl;
//    }
//}