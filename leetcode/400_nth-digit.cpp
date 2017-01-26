//Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
//
//Note:
//    n is positive and will fit within the range of a 32-bit signed integer (n < 231).
//
//Example 1:
//
//    Input:
//    3
//
//    Output:
//    3
//
//Example 2:
//
//    Input:
//    11
//
//    Output:
//    0
//
//    Explanation:
//    The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.

#include <iostream>
//#include <cmath>

using namespace std;

class Solution_400 {
public:
    // Exp: https://discuss.leetcode.com/topic/59314/java-solution
    // Time:	O(log(n))
    // Space:	O(1)
    int findNthDigit(int n) {
        int d = 1, base = 1;
        while (double(n) / 9 / d > base) {
            n -= 9 * base * d++;
            base *= 10;
        }
        int num = (n - 1) / d + base;
        int digit_i = n % d == 0 ? d : n % d;
        while (digit_i < d) {
            num /= 10;
            digit_i++;
        }
        return num % 10;
    }
};


//int main() {
//    cout << pow(2, 30) << endl;
//    int n = 11;
//    Solution_400 sol;
//    cout << sol.findNthDigit(n) << endl;
//}
