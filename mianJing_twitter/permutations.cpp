//Given a collection of distinct numbers, return all possible permutations.
//
//For example,
//[1,2,3] have the following permutations:
//    [
//        [1,2,3],
//        [1,3,2],
//        [2,1,3],
//        [2,3,1],
//        [3,1,2],
//        [3,2,1]
//    ]

#include <iostream>
#include <vector>

using namespace std;

class Solution_046 {
public:
    // Backtrack
    // Time:	O(n)
    // Space:	O(1)
    vector<vector<int>> permute(vector<int> &nums) {
        // sort(nums.begin(), nums.end());     // to give sorted result
        vector<vector<int>> result;
        vector<int> path;
        helper(nums, path, result);
        return result;
    }

    void helper(vector<int> &nums, vector<int> &path, vector<vector<int>> &result) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            vector<int>::iterator it = find(path.begin(), path.end(), val);
            if (it == path.end()) {
                path.push_back(val);
                helper(nums, path, result);
                path.pop_back();
            }
        }
    }



    // the collection contains duplicates
    // Backtrack
    // Time:	O(n)
    // Space:	O(1)
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        helper(nums, 0, result);
        return result;
    }

    void helper(vector<int> nums, int i, vector<vector<int>> &result) {
        if (i == nums.size() - 1) {
            result.push_back(nums);
            return;
        }

        for (int k = i; k < nums.size(); k++) {
            if (k != i && nums[k] == nums[i]) continue;
            swap(nums[k], nums[i]);
            helper(nums, i + 1, result);
        }
    }
};