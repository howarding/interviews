#include<iostream>
#include <list>
#include <queue>
#include <stack>

using namespace std;

class Graph {
    int V;                  // # nodes
    vector<list<int>> adj;  // adjacency list
    vector<int> indegree;   // indegree of each node
public:
    Graph(int v) {
        V = v;
        adj = vector<list<int>>(V, list<int>());
        indegree = vector<int>(V);
    }

    ~Graph() {
//        delete adj;
//        delete indegree;
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        indegree[w]++;
    }

    // Kahn's Algorithm == BFS
    // Time:	O(V + E)
    // Space:	O(V)
    bool topological_sort() {
        queue<int> que;           // a set of nodes with 0 indegree
        for (int i = 0; i < V; i++)
            if (!indegree[i])
                que.push(i);        // push all nodes with 0 indegree

        int count = 0;              // count # nodes that have been output so far.
        while (!que.empty()) {
            int v = que.front();
            que.pop();

            cout << v << "\t";       // output the current node
            count++;

            // reduce the indegree of v's destination nodes by 1.
            for (auto &neighbor : adj[v])
                if (!(--indegree[neighbor]))
                    que.push(neighbor);   // push nodes with 0 indegree into que
        }

        return count == V;          // validate there's no cycle in the graph.
    }

    // DFS
    // Time:	O(V + E)
    // Space:	O(V)
    bool topological_sort_dfs() {
        stack<int> stk;
        vector<bool> visited(V, false), onPath(V, false);

        for (int i = 0; i < V; i++)
            if (!visited[i] && !topological_sort_helper(i, visited, onPath, stk))
                return false;

        while (!stk.empty()) {
            cout << stk.top() << "\t";
            stk.pop();
        }
        return true;
    }

    bool topological_sort_helper(int node, vector<bool> &visited, vector<bool>& onPath, stack<int> &stk) {
        onPath[node] = visited[node] = true;
        for (int child : adj[node])
            if (onPath[child] || (!visited[child] && !topological_sort_helper(child, visited, onPath, stk)))
                return false;
        stk.push(node);
        onPath[node] = false;
        return true;
    }


    // Generate all Topological Sort
    vector<vector<int>> all_topological_sort() {
        vector<bool> visited(V, false);
        vector<int> path;
        vector<vector<int>> result;
        all_topological_sort_helper(path, result, visited);
        return result;
    }

    void all_topological_sort_helper(vector<int> &path, vector<vector<int>> &result, vector<bool> &visited) {
        if (path.size() == V) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < V; i++)
            if (!indegree[i] && !visited[i]) {
                for (int neighbor : adj[i])
                    indegree[neighbor]--;

                path.push_back(i);
                visited[i] = true;
                all_topological_sort_helper(path, result, visited);

                visited[i] = false;
                path.pop_back();
                for (int neighbor : adj[i])
                    indegree[neighbor]++;
            }
    }
};


//int main() {
//    Graph graph(6);
//    graph.addEdge(5, 2);
//    graph.addEdge(5, 0);
//    graph.addEdge(4, 0);
//    graph.addEdge(4, 1);
//    graph.addEdge(2, 3);
//    graph.addEdge(3, 1);
//
//    graph.topological_sort();
//    cout << endl;
//    graph.topological_sort_dfs();
//    cout << endl;
//    vector<vector<int>> result(graph.all_topological_sort());
//    for (auto& path : result) {
//        for (int ele : path)
//            cout << ele << "\t";
//        cout << endl;
//    }
//}