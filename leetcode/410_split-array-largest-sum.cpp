//Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.
//
//Note:
//    If n is the length of array, assume the following constraints are satisfied:
//
//    1 ≤ n ≤ 1000
//    1 ≤ m ≤ min(50, n)
//Examples:
//
//    Input:
//    nums = [7,2,5,10,8]
//    m = 2
//
//    Output:
//    18
//
//    Explanation:
//    There are four ways to split nums into two subarrays.
//    The best way is to split it into [7,2,5] and [10,8],
//    where the largest sum among the two subarrays is only 18.

#include <iostream>
#include <vector>

using namespace std;

class Solution_410 {
public:
    // BSearch
    // Exp: https://discuss.leetcode.com/topic/61324/clear-explanation-8ms-binary-search-java/30
    // Time:	O(n*log(sum)) sum: sum of all the numbers in nums
    // Space:	O(1)
    int splitArray(vector<int> &nums, int m) {
        int max_num = 0;
        long sum = 0;
        for (int num : nums) {
            max_num = max(max_num, num);
            sum += num;
        }
        if (m == 1) return int(sum);

        long left = max_num, right = sum;
        while (left <= right) {
            long mid = (left + right) / 2;
            if (valid(nums, m, mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }

    bool valid(vector<int> &nums, int m, long target) {
        int count = 1;
        long total = 0;
        for (int num : nums) {
            total += num;
            if (total > target) {
                total = num;
                count++;
                if (count > m)
                    return false;
            }
        }
        return true;
    }
};