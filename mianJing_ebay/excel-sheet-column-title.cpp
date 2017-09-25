//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
//For example:
//
//    1 -> A
//    2 -> B
//    3 -> C
//    ...
//    26 -> Z
//    27 -> AA
//    28 -> AB

#include <iostream>

using namespace std;

class Solution_168 {
public:
    // Exp: https://discuss.leetcode.com/topic/6248/accepted-java-solution
    // Time:	O(log(n))
    // Space:	O(1)
    string convertToTitle(int n) {
        string result;
        while (n--) {
            result.push_back('A' + n % 26);
            n /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }



    // Time:	O(n)
    // Space:	O(1)
    int titleToNumber(string s) {
        int result = 0;
        for (char c : s)
            result = result * 26 + c - 'A' + 1;
        return result;
    }
};
