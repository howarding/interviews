//Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//
//
//Example 1:
//
//Input: k = 3, n = 7
//
//Output:
//
//    [[1,2,4]]
//
//Example 2:
//
//Input: k = 3, n = 9
//
//Output:
//
//    [[1,2,6], [1,3,5], [2,3,4]]

#include <iostream>
#include <vector>

using namespace std;

class Solution_216 {
public:
    // Exp: https://discuss.leetcode.com/topic/14654/accepted-16ms-c-solution-use-backtracking-easy-understand
    // Time:
    // Space:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        if (k == 0 || n <= 0) return result;
        vector<int> path;
        dfs(n, k, 10, 1, path, result);
        return result;
    }

    void dfs(int target, int rest, int N, int start, vector<int> &path, vector<vector<int>> &result) {
        if (rest == 0) {
            if (target == 0)
                result.push_back(path);
            return;
        }

        for (int i = start; i < N; i++) {
            path.push_back(i);
            dfs(target - i, rest - 1, N, i + 1, path, result);
            path.pop_back();
        }
    }
};