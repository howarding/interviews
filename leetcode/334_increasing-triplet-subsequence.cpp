//Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
//
//Formally the function should:
//    Return true if there exists i, j, k
//    such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
//Your algorithm should run in O(n) time complexity and O(1) space complexity.
//
//Examples:
//Given [1, 2, 3, 4, 5],
//return true.
//
//Given [5, 4, 3, 2, 1],
//return false.

#include <iostream>
#include <vector>

using namespace std;

class Solution_334 {
public:
    // Exp: https://discuss.leetcode.com/topic/37281/clean-and-short-with-comments-c
    // Time:	O(n)
    // Space:	O(1)
    bool increasingTriplet(vector<int> &nums) {
        vector<int> mins(2, INT_MAX);
        for (int num : nums) {
            if (num <= mins[0])
                mins[0] = num;
            else {
                if (num <= mins[1])
                    mins[1] = num;
                else return true;
            }
        }
        return false;
    }


    // Follow Up:   Find m increasing numbers and return true
    // Time:	O(n)
    // Space:	O(m)
    bool increasingNNUmbers(vector<int> &nums, int m) {
        if (nums.size() < m) return false;
        vector<int> mins(m - 1, INT_MAX);
        for (int num : nums)
            for (int i = 0; i < m - 1; i++) {
                if (num <= mins[i]) {
                    mins[i] = num;
                    break;
                }
                if (i == m - 2)
                    return true;
            }
        return false;
    }
};