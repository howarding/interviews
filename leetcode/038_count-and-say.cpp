//The count-and-say sequence is the sequence of integers with the first five terms as following:
//
//    1.     1
//    2.     11
//    3.     21
//    4.     1211
//    5.     111221
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//Given an integer n, generate the nth term of the count-and-say sequence.
//
//Note: Each term of the sequence of integers will be represented as a string.
//
//Example 1:
//
//    Input: 1
//    Output: "1"
//Example 2:
//
//    Input: 4
//    Output: "1211"

#include <iostream>

using namespace std;

class Solution_038 {
public:
    // DP
    // Time:	O(n)
    // Space:	O(n)
    string countAndSay(int n) {
        if (n <= 0) return "";
        if (n == 1) return "1";
        string pre = "1", result;
        for (int i = 2; i <= n; i++) {
            result = "";
            int count = 1;
            for (int j = 1; j < pre.size(); j++)
                if (pre[j] == pre[j - 1]) count++;
                else {
                    result.push_back('0' + count);
                    result.push_back(pre[j - 1]);
                    count = 1;
                }
            result.push_back('0' + count);
            result.push_back(pre.back());
            pre = result;
        }
        return result;
    }
};