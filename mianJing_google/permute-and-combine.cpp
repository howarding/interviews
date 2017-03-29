//
// Created by Howard Ding on 2/12/17.
//


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution_pac {
    // Permutation
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(nums, path, result);
        return result;
    }

    void dfs(vector<int> &nums, vector<int> &path, vector<vector<int>> &result) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            vector<int>::iterator it = find(path.begin(), path.end(), val);
            if (it == path.end()) {
                path.push_back(val);
                dfs(nums, path, result);
                path.pop_back();
            }
        }
    }


    // Combination
    vector<vector<int> > combine(vector<int> &nums, int k) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(nums, k, 0, path, result);
        return result;
    }

    void dfs(vector<int> &nums, int k, int start, vector<int> &path, vector<vector<int>> &result) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, k, i + 1, path, result);
            path.pop_back();
        }
    }
};