//Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//
//If the fractional part is repeating, enclose the repeating part in parentheses.
//
//For example,
//
//    Given numerator = 1, denominator = 2, return "0.5".
//Given numerator = 2, denominator = 1, return "2".
//Given numerator = 2, denominator = 3, return "0.(6)".
//Hint:
//
//    No scary math, just apply elementary math knowledge. Still remember how to perform a long division?
//Try a long division on 4/9, the repeating part is obvious. Now try 4/333. Do you see a pattern?
//Be wary of edge cases! List out as many test cases as you can think of and test your code thoroughly.

#include <iostream>
#include <map>

using namespace std;

class Solution_166 {
public:
    // Exp: https://discuss.leetcode.com/topic/6079/accepted-cpp-solution-with-explainations
    // Time:	O(n)
    // Space:	O(1)
    string fractionToDecimal(int numerator, int denominator) {
        string result;
        if (denominator == 0) return result;
        if (numerator == 0) return "0";
        if ((numerator >= 0) != (denominator > 0))
            result += "-";
        long numer = numerator < 0 ? (long) numerator * (-1) : (long) numerator;
        long denom = denominator < 0 ? (long) denominator * (-1) : (long) denominator;
        result += to_string(numer / denom);
        if (numer % denom == 0) return result;
        result += ".";
        map<int, int> remainder_set;
        for (long p = numer % denom; p; p %= denom) {
            if (remainder_set.find(p) != remainder_set.end()) {
                result.insert(remainder_set[p], "(");
                result += ")";
                break;
            }
            remainder_set[p] = result.size();
            p *= 10;
            result += to_string(p / denom);
        }
        return result;
    }
};