//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
//Note: The solution set must not contain duplicate triplets.
//
//For example, given array S = [-1, 0, 1, 2, -1, -4],
//
//A solution set is:
//[
//[-1, 0, 1],
//[-1, -1, 2]
//]

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution_015 {
public:
    // Sort + Two Sum II (2 Pointers)
    // Exp: https://discuss.leetcode.com/topic/8107/share-my-ac-c-solution-around-50ms-o-n-n-with-explanation-and-comments/16
    // Time:    O(n^2)
    // Space:    O(n)
    vector<vector<int>> threeSum(vector<int> &nums) {
        if (nums.size() < 3)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 2; i++) {
            int target = -nums[i];
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (target < sum)
                    right--;
                else if (target > sum)
                    left++;
                else {
                    vector<int> ele({nums[i], nums[left], nums[right]});
                    result.push_back(ele);
                    while (nums[left] == ele[1])
                        left++;
                    while (nums[right] == ele[2])
                        right--;
                }
            }
            while (i < nums.size() - 2 && nums[i] == nums[i + 1])
                i++;
        }
        return result;
    }


    // FU 1. 如果不能排序怎么做，没有duplicate elements
    // Time:    O(n^2)
    // Space:    O(n)
    vector<vector<int>> threeSum_fbfu1(vector<int> &nums) {
        if (nums.size() < 3)
            return {};
        vector<vector<int>> result;
        unordered_set<int> visited;
        for (int i = 0; i < nums.size() - 2; i++) {
            int target = -nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                int remain = target - nums[j];
                if (visited.find(remain) == visited.end())
                    visited.insert(nums[j]);
                else
                    result.push_back({nums[i], nums[j], remain});
            }
        }
        return result;
    }


    // FU 2. 如果有duplicate 的怎么办? 把value和linkedlist映射起来，每个node还要存index,来比较就好了

};