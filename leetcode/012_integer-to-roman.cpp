//Given an integer, convert it to a roman numeral.
//
//Input is guaranteed to be within the range from 1 to 3999.

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Comp {
public:
    bool operator()(const int a, const int b) const {
        return b - a;
    }
};

class Solution_012 {
public:
    // Greedy algo
    // Exp: https://discuss.leetcode.com/topic/20510/my-java-solution-easy-to-understand
    // Exp: https://leetcode.com/problems/integer-to-roman/solution/
    // Time:	O(1)
    // Space:	O(1)
    string intToRoman(int num) {
        vector<int> values({1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1});
        vector<string> chars({"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"});
        string result;
        for (int i = 0; i < values.size(); i++) {
            while (values[i] <= num) {
                result += chars[i];
                num -= values[i];
            }
        }
        return result;
    }

    // Using map with comparer
    string intToRoman_1(int num) {
        map<int, string, Comp, allocator<pair<const int, string>>> value_chars{
                {1000, "M"},
                {900, "CM"},
                {500, "D"},
                {400, "CD"},
                {100, "C"},
                {90, "XC"},
                {50, "L"},
                {40, "XL"},
                {10, "X"},
                {9, "IX"},
                {5, "V"},
                {4, "IV"},
                {1, "I"}
        };
        map<int, string, greater<int>> value_chars_1{
                {1000, "M"},
                {900, "CM"},
                {500, "D"},
                {400, "CD"},
                {100, "C"},
                {90, "XC"},
                {50, "L"},
                {40, "XL"},
                {10, "X"},
                {9, "IX"},
                {5, "V"},
                {4, "IV"},
                {1, "I"}
        };
        string result;
        for (auto &pair: value_chars) {
            while (num >= pair.first) {
                result += pair.second;
                num -= pair.first;
            }
        }
        return result;
    }
};