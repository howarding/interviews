//Given a non-negative number represented as an array of digits, plus one to the number.
//
//The digits are stored such that the most significant digit is at the head of the list.

#include <iostream>
#include <vector>

using namespace std;

class Solution_066 {
public:
    // Exp: https://discuss.leetcode.com/topic/4556/is-it-a-simple-code-c/25
    // Time:	O(n)
    // Space:	O(1)
    vector<int> plusOne(vector<int> &digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};