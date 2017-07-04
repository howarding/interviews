//Divide two integers without using multiplication, division and mod operator.
//
//If it is overflow, return MAX_INT.

#include <iostream>

using namespace std;

class Solution_029 {
public:
    // Exp: https://discuss.leetcode.com/topic/15568/detailed-explained-8ms-c-solution
    // Time:	O(log(m/n))     m: dividend, n: divisor
    // Space:	O(1)
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN) {
            if (divisor == -1) return INT_MAX;
            else if (divisor == 1) return INT_MIN;
            else return ((divisor & 1) == 1) ? divide(dividend+1, divisor) : divide(dividend>>1, divisor>>1);
        }
        if (abs(divisor) == 1) return divisor > 0 ? dividend : - dividend;
        if (!dividend || divisor == INT_MIN) return 0;
        if (!divisor) return INT_MAX;
        int sign = ((dividend > 0) ^ (divisor > 0)) ? -1 : 1;
        int dvd = abs(dividend), dvs = abs(divisor);
        int result = 0;
        while (dvd >= dvs) {
            int multiplier = 1, tmp = dvs;
            while (((tmp << 1) > 0) && (dvd >= (tmp << 1))) {
                multiplier <<= 1;
                tmp <<= 1;
            }
            dvd -= tmp;
            result += multiplier;
        }
        return sign == 1 ? result : -result;
    }
};


//int main() {
//    Solution_029 sol;
//    int dividend = 1026117192, divisor = -874002063;
//    cout << sol.divide(dividend, divisor) << endl;
//}