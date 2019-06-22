//Given an integer, write a function to determine if it is a power of three.
//
//Follow up:
//Could you do it without using any loop / recursion?

#include <iostream>
#include <cmath>

using namespace std;

class Solution_326 {
public:
    // log, log2, log10 都不一定准确
    // Exp: https://leetcode.com/submissions/detail/87907753/
    // Time:	O(1)
    // Space:	O(1)
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        double power = log10(n) / log10(3);
        return power == floor(power);
    }

    // Recursion
    // Time:    O(n)
    // Space:   O(1)
    bool isPowerOfThree2(int n) {
        return n < 3 ? n == 1 : (n % 3 == 0 && isPowerOfThree2(n / 3));
    }
};


//int main() {
//    Solution_326 sol;
//    int n = 161051;
//    cout << sol.isPowerOfThree(n) << endl;
//}