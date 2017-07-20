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
    // Exp: https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html
    // Moore Voting Algorithm
    // Time:	O(n)
    // Space:	O(1)
    int majorityElement(vector<int>& nums) {
        int result = 0, count = 0;
        for (int num : nums) {
            if (count == 0)
                result = num;
            if (result == num)
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