//Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
//
//Note:
//
//    1. The length of both num1 and num2 is < 110.
//    2. Both num1 and num2 contains only digits 0-9.
//    3. Both num1 and num2 does not contain any leading zero.
//    4. You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include <iostream>
#include <vector>

using namespace std;

class Solution_043 {
public:
    // 2 nested for loops
    // Exp: https://leetcode.com/problems/multiply-strings/solutions/1495073/multiply-strings/
    // Approach 3
    // Exp: https://discuss.leetcode.com/topic/9449/brief-c-solution-using-only-strings-and-without-reversal
    // Time:	O(m*n)  m: length of num1. n: length of num2.
    // Space:	O(m+n)
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int m = num1.size(), n = num2.size();
        vector<int> product(m + n, 0);  // 相乘的数字最多m+n位
        for (int i = 0; i < m; i++)
            if (num1[i] - '0')
                for (int j = 0; j < n; j++)
                    product[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');

        int carry = 0;
        string result = "";
        for (int i = m + n - 1; i > 0; i--) {
            int sum = product[i] + carry;
            result = to_string(sum % 10) + result;
            carry = sum / 10;
        }
        if (carry)
            result = to_string(carry) + result;
        return result;
    }
};


//int main() {
//    string num1 = "98", num2 = "9";
//    Solution_043 sol;
//    cout << sol.multiply(num1, num2) << endl;
//}