//Related to question Excel Sheet Column Title
//
//Given a column title as appear in an Excel sheet, return its corresponding column number.
//
//For example:
//
//    A -> 1
//    B -> 2
//    C -> 3
//    ...
//    Z -> 26
//    AA -> 27
//    AB -> 28

#include <iostream>

using namespace std;

class Solution_171 {
public:
    // My own
    // Time:	O(n)
    // Space:	O(1)
    int titleToNumber(string s) {
        int result = 0;
        for (char c : s)
            result = result * 26 + c - 'A' + 1;
        return result;
    }
};