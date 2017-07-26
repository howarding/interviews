//Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
//
//For example:
//
//Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
//
//Follow up:
//Could you do it without any loop/recursion in O(1) runtime?

#include <iostream>
#include <vector>

using namespace std;

class Solution_258 {
public:
    // formula
    // Exp: https://en.wikipedia.org/wiki/Digital_root#Significance_and_formula_of_the_digital_root
    // Time:	O(1)
    // Space:	O(1)
    int addDigits(int num) {
        return num - (num - 1) / 9 * 9;
    }
};