// https://play.google.com/store/apps/details?id=com.bigduckgames.flow&hl=en，直接丢给了我这个游戏的链接， 名字叫flow free，
// 要求实现一个函数， 参数是一个矩阵表示的grid，grid上有用正整数表示的各个颜色的start和end point，要求找出一个solution，即连接所有相
// 同颜色的start和end point，同时联线不能有重叠或者交叉，不要求每个格子必须填满

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution_flow_free {
    vector<vector<int>> directions{
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
    };

public:
    bool isValid(vector<vector<int>>& nums) {
        unordered_set<int> nodes;
        vector<vector<int>> start_nodes;
        int i = 0, j = 0;
        for (i = 0; i < nums.size(); i++)
            for (j = 0; j < nums[0].size(); j++)
                if (nums[i][j] != 0 && nodes.find(nums[i][j]) == nodes.end()) {
                    start_nodes.push_back({i, j, nums[i][j]});
                    nodes.insert(nums[i][j]);
                }
        if (start_nodes.empty()) return true;
        i = start_nodes[0][0], j = start_nodes[0][1];
        return dfs(nums, start_nodes, 0, true, i, j);
    }

    bool dfs(vector<vector<int>>& nums, vector<vector<int>>& start_nodes, int n, bool start, int i , int j) {
        int start_i = start_nodes[n][0], start_j = start_nodes[n][1], target = start_nodes[n][2];
        if (i < 0 || i == nums.size() || j < 0 || j == nums[0].size())
            return false;
        if (nums[i][j] != 0 && nums[i][j] != target) return false;

        if (!start && nums[i][j] == target) {   // 找到终点，或者回到起点
            if (i == start_i && j == start_j) return false; // 回到起点
            // 找到终点了
            if (n == start_nodes.size() - 1) return true;   // 现在已经是最后一条连线了
            int next_i = start_nodes[n+1][0];
            int next_j = start_nodes[n+1][1];
            return dfs(nums, start_nodes, n+1, true, next_i, next_j);
        } else {    // 要么是刚刚出发，要么是正在路上
            if (!start) nums[i][j] = -1;   // 正在路上，标记此点已经访问
            for (const vector<int>& dir: directions) {
                int next_i = i + dir[0];
                int next_j = j + dir[1];
                if (dfs(nums, start_nodes, n, false, next_i, next_j)) return true;
            }
            if (!start) nums[i][j] = 0;
            return false;
        }
    }
};



//int main() {
//    Solution_flow_free sol;
//    vector<vector<int>> nums{
//            {1, 0, 0, 2, 0},
//            {0, 0, 3, 0, 0},
//            {0, 0, 0, 1, 0},
//            {0, 2, 0, 0, 0},
//            {0, 0, 0, 3, 0}
//    };
//    cout << sol.isValid(nums) << endl;
//}