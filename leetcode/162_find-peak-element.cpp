//A peak element is an element that is greater than its neighbors.
//
//Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
//
//The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
//
//You may imagine that num[-1] = num[n] = -∞.
//
//For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
//
//click to show spoilers.
//
//Note:
//    Your solution should be in logarithmic complexity.

#include <iostream>
#include <vector>

using namespace std;

class Solution_162 {
public:
    // Exp: https://discuss.leetcode.com/topic/5724/find-the-maximum-by-binary-search-recursion-and-iteration/37
    // Time:	O(log(n))
    // Space:	O(1)
    int findPeakElement(vector<int> &nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid1 = (low + high) / 2;
            int mid2 = mid1 + 1;
            if (nums[mid1] < nums[mid2])
                low = mid2;
            else
                high = mid1;
        }
        return low;
    }
};