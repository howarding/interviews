//有一堆朋友和朋友关系，把他们分总成两个group，group内互不认识
//就是判断一个给定graph是不是 bipartite graph

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution_bg {
public:
    // BFS      从其中一点出发，用bfs把所有点分到两个分组里
    // Time:    O(n)
    // Space:   O(n)
    bool isBipartite(vector<int> nodes, unordered_map<int, vector<int>> adj) {
        vector<unordered_set<int>> twoSets(2, unordered_set<int>());    // 表示两个分组
        queue<int> que, pre;
        que.push(nodes[0]);
        int ind = 0;

        while (!que.empty()) {
            while (!que.empty()) {
                int node = que.front();
                que.pop();
                for (int neighbor : adj[node]) {
                    if (twoSets[ind].find(node) != twoSets[ind].end())
                        return false;   // 如果在本组中出现了就直接返回false
                    if (twoSets[~ind].find(node) == twoSets[~ind].end()) {  // 如果在对方组没出现过则加进去
                        twoSets[~ind].insert(node);
                        pre.push(node);
                    }
                }
            }
            que.swap(pre);
            ind = ~ind;
        }
        return true;
    }
};


//int main() {
//    Solution_bg sol;
//
//}