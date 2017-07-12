//Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
//
//You may assume that the array is non-empty and the majority element always exist in the array.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_169 {
public:
    // Exp: https://discuss.leetcode.com/topic/17446/6-suggested-solutions-in-c-with-explanations
    // Moore Voting Algorithm
    // Time:	O(n)
    // Space:	O(1)
    int majorityElement(vector<int>& nums) {
        int result = nums[0], count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (!count) {
                count++;
                result = nums[i];
            } else if (nums[i] == result)
                count++;
            else
                count--;
        }
        return result;
    }

    // Hash Table
    // Time:	O(n)
    // Space:	O(n)
    int majorityElement1(vector<int>& nums) {
        unordered_map<int, int> dict;
        int n = nums.size();
        for (int num : nums)
            if (++dict[num] > n / 2)
                return num;
    }



    // Sort
    // Time:	O(nlog(n))
    // Space:	O(1)
    int majorityElement2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};