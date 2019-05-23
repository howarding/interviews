//Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
//For example,
//[1,1,2] have the following unique permutations:
//    [
//        [1,1,2],
//        [1,2,1],
//        [2,1,1]
//    ]

#include <iostream>
#include <vector>

using namespace std;

class Solution_047 {
public:
    // Backtrack
    // Exp: https://discuss.leetcode.com/topic/8831/a-simple-c-solution-in-only-20-lines
    // Time:	O(nlogn)
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

//int main() {
//    Solution_047 sol;
//    vector<int> nums{1, 2, 2, 4};
//    vector<vector<int>> result(sol.permuteUnique(nums));
//    for (auto&& path: result) {
//        for (auto num: path)
//            cout << num << '\t';
//        cout << endl;
//    }
//}