//Given two binary strings, return their sum (also a binary string).
//
//For example,
//a = "11"
//b = "1"
//Return "100".

#include <iostream>
#include <vector>

using namespace std;

class Solution_067 {
public:
    // Exp: My own
    // Time:	O(n)
    // Space:	O(n)
    string addBinary(string a, string b) {
        int n = a.size() > b.size() ? a.size() : b.size();
        string s;
        int al = a.size() - 1, bl = b.size() - 1;
        int carry = 0;
        while (n-- > 0) {
            int av = al >= 0 ? a[al--] - '0' : 0;
            int bv = bl >= 0 ? b[bl--] - '0' : 0;
            int value = (av + bv + carry) % 2;
            carry = (av + bv + carry) / 2;
            char c = '0' + value;
            s = c + s;
        }
        if (carry)
            s = '1' + s;
        return s;
    }
};