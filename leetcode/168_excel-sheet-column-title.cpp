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
//            result = to_string(('A'+ n % 26)) + result;   // Doesn't work
            n /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};


//int main() {
//    int n = 27;
//    Solution_168 sol;
//    cout << sol.convertToTitle(n) << endl;
//}