#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
typedef int Node;

class Graph {
    unordered_set<Node> nodes;                  // # nodes
    vector<pair<pair<Node, Node>, int>> edges;  // graph edges with weights
    unordered_map<Node, Node> parent;
public:
    Graph();

    void addEdge(Node node1, Node node2, int weight) {
        nodes.insert(node1);
        nodes.insert(node2);
        edges.push_back({{node1, node2}, weight});
        parent[node1] = node1;
        parent[node2] = node2;
    }

    Node Find(Node node) {
        while (parent[node] != node) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    bool Union(Node& node1, Node& node2) {
        Node root1 = Find(node1);
        Node root2 = Find(node2);
        if (root1 == root2) return false;
        parent[root2] = root1;
        return true;
    }

    static bool cmp(pair<pair<Node, Node>, int> edge1, pair<pair<Node, Node>, int> edge2) {
        return edge1.second < edge2.second;
    }

    // Kruskal's Algorithm to build MST (Greedy)
    // For E << V
    // Time:    O(E*log(E) + E*log(V))
    // Space:   O(V): parent
    int kruskal(unordered_set<Node>& nodes, vector<pair<pair<Node, Node>, int>>& edges) {
        int result = 0;
        sort(edges.begin(), edges.end(), cmp);
        for (auto&& edge: edges) {
            Node& node1 = edge.first.first;
            Node& node2 = edge.first.second;
            int weight = edge.second;
            if (Union(node1, node2)) result += weight;
        }
        return result;
    }



    // Prim's Algorithm to build MST (Greedy)
    // For E >> V
    // Time:    O(V*log(V) + E*log(V))
    // Space:   O(E): adj, min_heap
    int prim(unordered_set<Node>& nodes, vector<pair<pair<Node, Node>, int>>& edges, Node& node) {
        int result = 0;
        unordered_map<Node, vector<pair<Node, int>>> adj;
        for (auto&& edge: edges) {
            Node& node1 = edge.first.first;
            Node& node2 = edge.first.second;
            int weight = edge.second;
            adj[node1].push_back({node2, weight});
            adj[node2].push_back({node1, weight});
        }

        priority_queue<pair<Node, int>, vector<pair<Node, int>>, Cmp> min_heap;
        unordered_set<Node> visited;
        min_heap.push({node, 0});

        while (!min_heap.empty()) {
            auto&& n = min_heap.top();
            min_heap.pop();
            if (visited.find(n.first) != visited.end()) continue;
            visited.insert(n.first);
            result += n.second;
            for (auto&& neighbor: adj[n.first])
                if (visited.find(neighbor.first) == visited.end())
                    min_heap.push(neighbor);
        }
        return result;
    }

    struct Cmp {
        bool operator()(pair<Node, int>& a, pair<Node, int>& b) {
            return a.second > b.second;
        }
    };

};