//Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//Each number in C may only be used once in the combination.
//
//Note:
//    All numbers (including target) will be positive integers.
//    The solution set must not contain duplicate combinations.
//For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
//A solution set is:
//    [
//        [1, 7],
//        [1, 2, 5],
//        [2, 6],
//        [1, 1, 6]
//    ]

#include <iostream>
#include <vector>

using namespace std;

class Solution_040 {
public:
    // Exp: https://discuss.leetcode.com/topic/14654/accepted-16ms-c-solution-use-backtracking-easy-understand
    // Time:
    // Space:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        if (candidates.empty()) return result;
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        helper(candidates, 0, target, path, result);
        return result;
    }

    void helper(vector<int> &candidates, int start, int rest, vector<int> &path, vector<vector<int>> &result) {
        if (rest < 0) return;
        if (rest == 0) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            helper(candidates, i + 1, rest - candidates[i], path, result);
            path.pop_back();
        }
    }
};