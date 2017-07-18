//Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution_217 {
public:
    // Exp: https://discuss.leetcode.com/topic/14730/possible-solutions
    // Time:	O(n)
    // Space:	O(n)
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();
    }



    // Sort
    // Time:	O(nlog(n))
    // Space:	O(1)
    bool containsDuplicate1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == nums[i-1]) return true;
        return false;
    }
};