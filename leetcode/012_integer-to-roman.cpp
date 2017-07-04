//Given an integer, convert it to a roman numeral.
//
//Input is guaranteed to be within the range from 1 to 3999.

#include <iostream>
#include <vector>

using namespace std;

class Solution_012 {
public:
    // Exp: https://discuss.leetcode.com/topic/20510/my-java-solution-easy-to-understand
    // Time:	O(log(n))
    // Space:	O(1)
    string intToRoman(int num) {
        vector<int> values({1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1});
        vector<string> chars({"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"});
        string result = "";
        int i = 0;
        while (num) {
            while (num >= values[i]) {
                num -= values[i];
                result.append(chars[i]);
            }
            i++;
        }
        return result;
    }
};