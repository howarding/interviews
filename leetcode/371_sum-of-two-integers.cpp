//Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
//
//Example:
//Given a = 1 and b = 2, return 3.

#include <iostream>

using namespace std;

class Solution_371 {
public:
    // bit (my own)
    // Time:	O(1)
    // Space:	O(1)
    int getSum(int a, int b) {
        int result = 0, carry = 0;
        for (int i = 0; i < 32; i++) {
            int x = (a >> i) & 1;
            int y = (b >> i) & 1;
            int digit = x ^ y ^ carry;
            carry = (x & y) | ((x | y) & carry);
            result |= (digit << i);
        }
        return result;
    }
};


//int main() {
//    Solution_371 sol;
//    int a = 4, b = 5;
//    cout << sol.getSum(a, b) << endl;
//}