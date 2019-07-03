//Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
//
//Note:
//
//    1. The length of both num1 and num2 is < 5100.
//    2. Both num1 and num2 contains only digits 0-9.
//    3. Both num1 and num2 does not contain any leading zero.
//    4. You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include <iostream>

using namespace std;

class Solution_415 {
public:
    // Exp: https://discuss.leetcode.com/topic/62310/straightforward-java-8-main-lines-25ms
    // Time:	O(n)
    // Space:	O(n)
    string addStrings(string num1, string num2) {
        string result;
        int carry = 0;
        int m = num1.size(), n = num2.size();
        for (int i = m - 1, j = n - 1; i >= 0 || j >= 0; i--, j--) {
            int num_i = i >= 0 ? num1[i] - '0' : 0;
            int num_j = j >= 0 ? num2[j] - '0' : 0;
            int sum = num_i + num_j + carry;
            int remainder = sum % 10;
            carry = sum / 10;
            result.push_back('0' + remainder);
        }
        if (carry) result.push_back('0' + carry);
        reverse(result.begin(), result.end());
        return result;
    }
};