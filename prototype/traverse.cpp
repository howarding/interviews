#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>

using namespace std;

/**
 * Node class definition
 */
class Node {
public:
    const int ind;
    explicit Node(const int v): ind(v) {};
};

bool operator==(const Node& a, const Node& b) {
    return a.ind == b.ind;
}

ostream& operator<<(ostream& os, const Node& node) {
    os << node.ind;
    return os;
}

/**
 * Function-object CLASS
 * Hash function for the unordered_set<Node>
 */
class NodeHashFun {
public:
    int operator()(const Node& node) const {
        return node.ind;
    }
};

class NodeCompare {
public:
    bool operator()(const Node& a, const Node& b) const{
        return a.ind - b.ind;
    }
};

using NodeSet = unordered_set<Node, NodeHashFun>;

/**
 * Graph class definition
 */
class Graph {
    NodeSet nodes;                  // # nodes
    unordered_map<Node, NodeSet, NodeHashFun> adj;  // adjacency list
    map<Node, NodeSet, NodeCompare> adj2;
public:
    Graph() = default;;
    void addEdge(const Node& v, const Node& w) {
        nodes.insert(v);
        nodes.insert(w);
        adj[v].insert(w);
        adj[w].insert(v);
        adj2[v].insert(w);
        adj2[v].insert(v);
    }


    // BFS iterative
    // Use que
    void bfs(void (*nodeFun)(const Node&)) {
        queue<Node> que;
        NodeSet visited;
        for (auto &root : nodes) {
            if (visited.find(root) == visited.end()) {
                que.push(root);
                visited.insert(root);
                while (!que.empty()) {
                    Node& node = que.front();
                    que.pop();
                    nodeFun(node);
                    for (auto &&neighbor : adj2[node])
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
    // Use stack
    void dfs_iterative(void (*nodeFun)(const Node&)) {
        stack<Node> stk;
        NodeSet visited;
        for (auto &root : nodes) {
            if (visited.find(root) == visited.end()) {
                stk.push(root);
                visited.insert(root);
                while (!stk.empty()) {
                    Node& node = stk.top();
                    stk.pop();
                    nodeFun(node);
                    for (auto &&neighbor : adj[node])
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
    void dfs_recursive(void (*nodeFun)(const Node&)) {
        NodeSet visited;
        for (auto &root : nodes)
            if (visited.find(root) == visited.end()) {
                nodeFun(root);
                helper(visited, root, nodeFun);
            }
        cout << endl;
    }

    void helper(NodeSet &visited, const Node& node, void (*nodeFun)(const Node&)) {
        visited.insert(node);
        nodeFun(node);
        for (auto &&neighbor : adj[node])
            if (visited.find(neighbor) == visited.end())
                helper(visited, neighbor, nodeFun);
    }
};

void print(const Node& node) {
    cout << "Function on " << node << endl;
}

int main() {
    /**
     * Make a graph with the structure:
     *      2 -- 1 -- 0 -- 4 -- 3
     *           |
     *           5
     */
    Graph g;
    vector<Node> nodes{Node(0), Node(1), Node(2), Node(3), Node(4), Node(5)};
    g.addEdge(nodes[1], nodes[5]);
    g.addEdge(nodes[1], nodes[0]);
    g.addEdge(nodes[2], nodes[1]);
    g.addEdge(nodes[3], nodes[4]);
    g.addEdge(nodes[4], nodes[0]);

    g.bfs(print);
    g.dfs_recursive(print);
    g.dfs_iterative(print);
}