#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Union:   O(n)
// Find:    O(1)
class UnionFind1 {
    unordered_map<string, int> node_group;
    int groupNum;
public:
    UnionFind1(vector<string>& nodes) {
        for (int i = 0; i < nodes.size(); i++)
            node_group[nodes[i]] = i;
        groupNum = nodes.size();
    }

    // Time:    O(n)
    void Union(string& node1, string& node2) {
        if (node_group[node1] == node_group[node2]) return;
        int id = min(node_group[node1], node_group[node2]);
        for (auto&& pair: node_group)
            if (pair.second == node_group[node1] || pair.second == node_group[node2])
                node_group[pair.first] = id;
        groupNum--;
    }

    // Time:    O(1)
    int Find(string& node) {
        return node_group[node];
    }

    // Time:    O(1)
    bool isConnected(string& node1, string& node2) {
        return Find(node1) == Find(node2);
    }

    // Time:    O(1)
    int getGroupNum() {
        return groupNum;
    }
};


// Union:   O(h)
// Find:    O(h)
class QuickUnion {
    unordered_map<string, string> parent;
    int groupNum;
public:
    QuickUnion(vector<string>& nodes) {
        for (string& node: nodes)
            parent[node] = node;
        groupNum = nodes.size();
    }

    // Time:    O(h)
    void Union(string& node1, string& node2) {
        string root1 = Find(node1);
        string root2 = Find(node2);
        if (root1 == root2) return;
        parent[root2] = root1;
        groupNum--;
    }

    // Time:    O(h)
    string Find(string node) {
        while (parent[node] != node)
            node = parent[node];
        return node;
    }

    // Time:    O(1)
    bool isConnected(string& node1, string& node2) {
        return Find(node1) == Find(node2);
    }

    // Time:    O(1)
    int getGroupNum() {
        return groupNum;
    }
};



class WeightedQuickUnion {
    unordered_map<string, string> parent;
    unordered_map<string, int> sz;
    int groupNum;
public:
    WeightedQuickUnion(vector<string>& nodes) {
        for (string& node: nodes) {
            parent[node] = node;
            sz[node] = 1;
        }
        groupNum = nodes.size();
    }

    // Time:    O(log(n))
    void Union(string& node1, string& node2) {
        string root1 = Find(node1);
        string root2 = Find(node2);
        if (root1 == root2) return;
        if (sz[root1] < sz[root2]) {
            parent[root1] = root2;
            sz[root2] += sz[root1];
        } else {
            parent[root2] = root1;
            sz[root1] += sz[root2];
        }
        groupNum--;
    }

    // Time:    O(log(n))
    string Find(string node) {
        while (parent[node] != node) {
            // parent[node] = parent[parent[node]];    // 将node的父节点设置为它的爷爷节点，压缩树的深度，查找更快
            node = parent[node];
        }
        return node;
    }
};