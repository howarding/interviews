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
#include <unordered_map>
#include <set>
#include <iterator>

using namespace std;

class Solution_015 {
public:
    // BEST
    // Sort + Two Sum II (2 Pointers)
    // Exp: https://leetcode.com/problems/3sum/solution/
    // Time:    O(n^2)
    // Space:    O(1)
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
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
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < nums.size() - 1 && nums[left] == nums[left+1]) left++;
                    while (right > 0 && nums[right] == nums[right-1]) right--;
                    left++;
                }
            }
            while (i < nums.size() - 2 && nums[i] == nums[i + 1])
                i++;
        }
        return result;
    }

    // Sort + Two Sum (HashSet)
    // Time:    O(n^2)
    // Space:    O(n)
    vector<vector<int>> threeSum1(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2 && nums[i] <= 0; i++) {
            twoSum(nums, i, result);
            while (i < nums.size() - 2 && nums[i] == nums[i + 1]) i++;
        }
        return result;
    }

    void twoSum(vector<int>& nums, int i, vector<vector<int>>& result) {
        unordered_set<int> visited;
        for (int j = i + 1; j < nums.size(); j++) {
            int complement = -nums[i] - nums[j];
            if (visited.find(complement) != visited.end()) {
                result.push_back({nums[i], complement, nums[j]});
                while (j < nums.size() - 1 && nums[j] == nums[j + 1]) j++;
            }
            visited.insert(nums[j]);
        }
    }

    // FU 1. 如果不能排序怎么做，没有duplicate elements
    // SET
    // Time:    O(n^2)
    // Space:   O(n)
    vector<vector<int>> threeSum_fbfu1(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;
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

    vector<vector<int>> threeSum_fbfu2(vector<int>& nums) {
        if (nums.size() < 3) return {};
        set<vector<int>> result;
        unordered_set<int> dups;
        unordered_map<int, int> visited;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (dups.insert(nums[i]).second) {
                for (int j = i + 1; j < nums.size(); j++) {
                    int remain = -nums[i] - nums[j];
                    unordered_map<int, int>::iterator iter = visited.find(remain);
                    if (iter != visited.end() && iter->second == i) {
                        vector<int> triplet = {nums[i], nums[j], remain};
                        sort(triplet.begin(), triplet.end());
                        result.insert(triplet);
                    }
                    visited[nums[j]] = i;
                }
            }
        }
        return {result.begin(), result.end()};
    }


    // FU 2. 如果有duplicate 的怎么办? 把value和linkedlist映射起来，每个node还要存index,来比较就好了

};