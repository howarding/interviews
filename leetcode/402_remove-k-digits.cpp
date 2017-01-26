//Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
//
//Note:
//    The length of num is less than 10002 and will be ≥ k.
//    The given num does not contain any leading zero.
//Example 1:
//
//    Input: num = "1432219", k = 3
//    Output: "1219"
//    Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
//Example 2:
//
//    Input: num = "10200", k = 1
//    Output: "200"
//    Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
//Example 3:
//
//    Input: num = "10", k = 2
//    Output: "0"
//    Explanation: Remove all the digits from the number and it is left with nothing which is 0.

#include <iostream>
#include <vector>

using namespace std;

class Solution_402 {
public:
    // Exp: https://discuss.leetcode.com/topic/59412/a-greedy-method-using-stack-o-n-time-and-o-n-space
    // Time:    O(n+k)
    // Space:   O(n)
    string removeKdigits(string num, int k) {
        int digits = num.size() - k;
        string result;
        vector<char> stk(num.size(), '\0');
        int top = 0;
        for (int i = 0; i < num.size(); i++) {
            while (top > 0 && stk[top - 1] > num[i] && k > 0) {
                top--;
                k--;
            }
            stk[top++] = num[i];
        }
        int idx = 0;
        while (idx < digits && stk[idx] == '0') idx++;
        for (int i = idx; i < digits; i++)
            result += stk[i];
        return result.empty() ? "0" : result;
    }
};


//int main() {
//    string num = "10";
//    int k = 1;
//    Solution_402 sol;
//    cout << sol.removeKdigits(num, k) << endl;
//}