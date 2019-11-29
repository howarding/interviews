//给定一些String代表players，再给一个list，叫allies，存储了两两player那两个是盟友，然后让完成两个function，一个叫isAllies，
//输入两个player，返回是否是allies；另一个叫isAssociated，输入两个player，返回是否属于一个阵营（属于一个阵营的定义是有共同盟友
//或者本身这两个就是盟友）
//  player：A，B and C;
//  allies:{[A,B] , [B,C]};
//此时
//    isAllies（A，B） == true;
//    isAllies(A , C) == false;
//    isAssociated（A，C）== true;
//    因为都有盟友B

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Union Find
// Time:
//      AlliesAssociated:   O(n + m*log(n))
//      isAllies:           O(1)
//      isAssociated:       O(log(n))
class AlliesAssociated {
    unordered_map<string, string> parents;
    unordered_map<string, int> sz;
    unordered_map<string, unordered_set<string>> adj;
public:
    AlliesAssociated (vector<string>& players, vector<vector<string>>& allies) {
        for (string& player: players) {
            parents[player] = player;
            sz[player] = 1;
        }

        for (vector<string>& ally: allies) {
            adj[ally[0]].insert(ally[1]);
            adj[ally[1]].insert(ally[0]);
            string root_1 = find(players[0]);
            string root_2 = find(players[1]);
            if (root_1 == root_2) continue;
            if (sz[root_1] < sz[root_2]) {
                parents[root_1] = root_2;
                sz[root_2] += sz[root_1];
            } else {
                parents[root_2] = root_1;
                sz[root_1] += sz[root_2];
            }
        }
    }

    string find(string player) {
        while (parents[player] != player) {
            parents[player] = parents[parents[player]];
            player = parents[player];
        }
        return player;
    }

    bool isAllies(const string& a, const string& b) {
        return adj[a].find(b) != adj[a].end();
    }

    bool isAssociated(const string& a, const string& b) {
        return find(a) == find(b);
    }
};