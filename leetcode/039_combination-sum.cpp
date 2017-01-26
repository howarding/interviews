//Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//The same repeated number may be chosen from C unlimited number of times.
//
//Note:
//    All numbers (including target) will be positive integers.
//    The solution set must not contain duplicate combinations.
//For example, given candidate set [2, 3, 6, 7] and target 7,
//A solution set is:
//    [
//        [7],
//        [2, 2, 3]
//    ]

#include <iostream>
#include <vector>

using namespace std;

class Solution_039 {
public:
    // Exp: https://discuss.leetcode.com/topic/14654/accepted-16ms-c-solution-use-backtracking-easy-understand
    // Time:
    // Space:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        if (candidates.empty()) return result;
        vector<int> path;
        dfs(candidates, 0, target, path, result);
        return result;
    }

    void dfs(vector<int> &candidates, int start, int rest, vector<int> &path, vector<vector<int>> &result) {
        if (rest < 0) return;
        if (rest == 0) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            dfs(candidates, i, rest - candidates[i], path, result);
            path.pop_back();
        }
    }
};