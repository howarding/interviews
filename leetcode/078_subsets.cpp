//Given a set of distinct integers, nums, return all possible subsets.
//
//Note: The solution set must not contain duplicate subsets.
//
//For example,
//    If nums = [1,2,3], a solution is:
//
//    [
//        [3],
//        [1],
//        [2],
//        [1,2,3],
//        [1,3],
//        [2,3],
//        [1,2],
//        []
//    ]

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution_078 {
public:
    // DFS
    // Time:	O(2^n)
    // Space:	O(2^n)
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> result;
        if (nums.empty()) return result;
        vector<int> path;
        helper(nums, 0, path, result);
        return result;
    }

    void helper(vector<int> &nums, int start, vector<int> &path, vector<vector<int>> &result) {
        if (start == nums.size()) {
            result.push_back(path);
            return;
        }
        helper(nums, start + 1, path, result);
        path.push_back(nums[start]);
        helper(nums, start + 1, path, result);
        path.pop_back();
    }


    // 给一个int array 没有重复 和一个target，要求数可以生成的subset数目满足条件 min(subset) + max(subset) < target
    // 2Pointers
    int subsetsNum_fb(vector<int> &nums, int target) {
        if (nums.empty()) return 1; // only include empty set
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1, result = 0;
        while (left <= right) {
            while (left <= right && nums[left] + nums[right] >= target)
                right--;
            if (left > right) break;
            result += pow(2, right - left);
            left++;
        }
        return result;
    }
};