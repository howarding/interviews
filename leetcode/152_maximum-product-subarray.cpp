//Find the contiguous subarray within an array (containing at least one number) which has the largest product.
//
//For example, given the array [2,3,-2,4],
//the contiguous subarray [2,3] has the largest product = 6.

#include <iostream>
#include <vector>

using namespace std;

class Solution_152 {
public:
    // Normal DP
    // Exp: https://discuss.leetcode.com/topic/4417/possibly-simplest-solution-with-o-n-time-complexity
    // Time:	O(n)
    // Space:	O(1)
    int maxProduct(vector<int>& nums) {
        // global_max stores the result that is the max we have found so far.
        int global_max(INT_MIN), local_max(1), local_min(1);
        for (int num : nums) {
            // multiplied by a negative makes big number smaller, small number bigger
            // so we redefine the extreme nums by swapping them
            if (num < 0) swap(local_max, local_min);
            // local_max/local_min stores the max/min product of
            // subarray that ends with the current number num
            local_max = max(local_max * num, num);
            local_min = min(local_min * num, num);
            global_max = max(local_max, global_max);
        }
        return global_max;
    }
};