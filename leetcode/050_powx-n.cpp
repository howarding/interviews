//Implement pow(x, n).

#include <iostream>

using namespace std;

class Solution_50 {
public:
    // Exp: https://discuss.leetcode.com/topic/5425/short-and-easy-to-understand-solution/37
    // Time:	O(log(n))
    // Space:	O(1)
    double myPow(double x, int n) {
        if (n == INT_MIN) return myPow(x, n + 1) * 1 / x;
        if (n < 0) return myPow(1/x, -n);
        if (n == 0) return 1;
        if (n == 1) return x;
        return myPow(x * x, n / 2) * myPow(x, n % 2);
    }
};