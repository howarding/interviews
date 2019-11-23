//Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
//
//
//OJ's undirected graph serialization:
//Nodes are labeled uniquely.
//
//We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
//As an example, consider the serialized graph {0,1,2#1,2#2,2}.
//
//The graph has a total of three nodes, and therefore contains three parts as separated by #.
//
//    1. First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
//    2. Second node is labeled as 1. Connect node 1 to node 2.
//    3. Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
//Visually, the graph looks like the following:
//
//       1
//      / \
//     /   \
//    0 --- 2
//         / \
//         \_/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


// FB
class Solution_133 {
public:
    // BFS, Iterative
    // Exp: https://discuss.leetcode.com/topic/16957/7-17-lines-c-bfs-dfs-solutions
    // Time:	O(n)
    // Space:	O(n)
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        unordered_map<Node*, Node*> dict;
        dict[node] = new Node(node->val, vector<Node*>());
        queue<Node*> que;
        que.push(node);
        while (!que.empty()) {
            Node* ele = que.front();
            que.pop();
            for (Node* neighbor: ele->neighbors) {
                if (dict.find(neighbor) == dict.end()) {
                    dict[neighbor] = new Node(neighbor->val, vector<Node*>());
                    que.push(neighbor);
                }
                dict[ele]->neighbors.push_back(dict[neighbor]);
            }
        }
        return dict[node];
    }


    // DFS, Recursive
    // Time:	O(n)
    // Space:	O(n)
    Node* cloneGraph2(Node* node) {
        unordered_map<Node*, Node*> dict;
        return helper(node, dict);
    }

    Node* helper(Node* node, unordered_map<Node*, Node*>& dict) {
        if (dict.find(node) != dict.end())
            return dict[node];
        dict[node] = new Node(node->val, vector<Node*>());
        for (Node* neighbor: node->neighbors)
            dict[node]->neighbors.push_back(helper(neighbor, dict));
        return dict[node];
    }
};