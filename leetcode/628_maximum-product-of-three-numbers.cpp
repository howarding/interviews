//Given an integer array, find three numbers whose product is maximum and output the maximum product.
//
//Example 1:
//    Input: [1,2,3]
//    Output: 6
//Example 2:
//    Input: [1,2,3,4]
//    Output: 24
//Note:
//    1. The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
//    2. Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.

#include <iostream>
#include <stack>

using namespace std;

class Solution_628 {
public:
    // No sorting
    // Exp: https://leetcode.com/problems/maximum-product-of-three-numbers/solution/
    // Time:	O(n)
    // Space:	O(1)
    int maximumProduct(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        for (int num : nums) {
            if (num <= min1) {
                min2 = min1;
                min1 = num;
            } else if (num <= min2)
                min2 = num;

            if (num >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num >= max2) {
                max3 = max2;
                max2 = num;
            } else if (num >= max3)
                max3 = num;
        }
        return max(max1 * max2 * max3, max1 * min1 * min2);
    }
};