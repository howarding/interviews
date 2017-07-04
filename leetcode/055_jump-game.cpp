//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Determine if you are able to reach the last index.
//
//For example:
//A = [2,3,1,1,4], return true.
//
//A = [3,2,1,0,4], return false.

#include <iostream>
#include <vector>

using namespace std;

class Solution_055 {
public:
    // DP
    // Time:	O(n)
    // Space:	O(1)
    bool canJump(vector<int>& nums) {
        int max_length = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            max_length = max(max_length - 1, nums[i]);
            if (!max_length) return false;
        }
        return true;
    }
};