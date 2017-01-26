//Implement pow(x, n).

#include <iostream>

using namespace std;

class Solution_50 {
public:
    // Exp: https://discuss.leetcode.com/topic/5425/short-and-easy-to-understand-solution/37
    // Time:	O(log(n))
    // Space:	O(1)
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == INT_MIN) {
            x = x * x;
            n /= 2;
        }
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        return (n % 2 == 0) ? myPow(x * x, n / 2) : myPow(x * x, n / 2) * x;
    }
};