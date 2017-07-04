//Reverse digits of an integer.
//
//Example1: x = 123, return 321
//Example2: x = -123, return -321
//
//click to show spoilers.
//
//Have you thought about this?
//Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
//
//If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
//
//Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
//
//For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
//
//Note:
//The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.

#include <iostream>

using namespace std;

class Solution_007 {
public:
    // My Own
    // Time:	O(log(n))
    // Space:	O(1)
    int reverse(int x) {
        int top = INT_MAX / 10, bottom = INT_MIN / 10;
        int top_remainder = INT_MAX % 10, bottom_remainder = INT_MIN % 10;
        int result = 0;
        while (x) {
            int remainder = x % 10;
            if (result > top || (result == top && remainder > top_remainder)
                || result < bottom || (result == bottom && remainder < bottom_remainder))
                return 0;
            result = result * 10 + remainder;
            x /= 10;
        }
        return result;
    }
};


//int main() {
//    Solution_007 sol;
//    int x = -1463847412;
//    cout << sol.reverse(x) << endl;
//}