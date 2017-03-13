//The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//
//Now your job is to find the total Hamming distance between all pairs of the given numbers.
//
//Example:
//    Input: 4, 14, 2
//
//    Output: 6
//
//    Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
//    showing the four bits relevant in this case). So the answer will be:
//    HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
//Note:
//    1. Elements of the given array are in the range of 0 to 10^9
//    2. Length of the array will not exceed 10^4.

#include <iostream>
#include <vector>

using namespace std;

class Solution_477 {
public:
    // Exp: https://discuss.leetcode.com/topic/72092/java-o-n-time-o-1-space
    // Time:	O(n)
    // Space:	O(1)
    int totalHammingDistance(vector<int> &nums) {
        int n = nums.size(), result = 0;
        for (int i = 0; i < 32; i++) {
            int one_num = 0;
            for (int num : nums)
                one_num += (num >> i) & 1;
            result += one_num * (n - one_num);
        }
        return result;
    }
};