//Write a program to check whether a given number is an ugly number.
//
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
//
//Note that 1 is typically treated as an ugly number.

#include <iostream>
#include <vector>

using namespace std;

class Solution_263 {
public:
    // Exp: https://discuss.leetcode.com/topic/21785/2-4-lines-every-language
    // Time:	O(log(n))
    // Space:	O(1)
    bool isUgly(int num) {
        if (num <= 0) return false;
        vector<int> dividers({2, 3, 5});
        for (int divider : dividers)
            while (num % divider == 0)
                num /= divider;
        return num == 1;
    }
};