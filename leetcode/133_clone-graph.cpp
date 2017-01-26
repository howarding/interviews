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

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;

    UndirectedGraphNode(int x) : label(x) {};
};

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution_133 {
public:
    // Exp: https://discuss.leetcode.com/topic/16957/7-17-lines-c-bfs-dfs-solutions
    // Time:	O(n)
    // Space:	O(n)
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return node;
        UndirectedGraphNode *result = new UndirectedGraphNode(node->label);
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> map;
        map[node] = result;
        queue<UndirectedGraphNode *> nodes;
        nodes.push(node);
        while (!nodes.empty()) {
            UndirectedGraphNode *ele = nodes.front();
            nodes.pop();
            for (auto neighbor: ele->neighbors) {
                if (map.find(neighbor) == map.end()) {
                    UndirectedGraphNode *neighbor_clone = new UndirectedGraphNode(neighbor->label);
                    map[neighbor] = neighbor_clone;
                    nodes.push(neighbor);
                }
                map[ele]->neighbors.push_back(map[neighbor]);
            }
        }
        return result;
    }
};