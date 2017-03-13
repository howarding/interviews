//Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
//
//For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
//    the contiguous subarray [4,-1,2,1] has the largest sum = 6.
//
//click to show more practice.
//
//More practice:
//If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

#include <iostream>
#include <vector>

using namespace std;

class Solution_053 {
public:
    // Normal DP
    // Exp: https://discuss.leetcode.com/topic/6413/dp-solution-some-thoughts/25
    // Time:	O(n)
    // Space:	O(1)
    int maxSubArray(vector<int> &nums) {
        int local_max = 0, global_max = INT_MIN;
        for (int num : nums) {
            local_max = max(local_max + num, num);
            global_max = max(local_max, global_max);
        }
        return global_max;
    }
};