//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
//
//You may assume that the given expression is always valid.
//
//Some examples:
//    "3+2*2" = 7
//    " 3/2 " = 1
//    " 3+5 / 2 " = 5
//Note: Do not use the eval built-in library function.

#include <iostream>

using namespace std;

class Solution_227 {
public:
    // One pass (My own)
    // Time:	O(n)
    // Space:	O(1)
    int calculate(string s) {
        if (s.empty()) return 0;
        int result(0), pre(0), num(0);
        char sign('+');
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i]))
                num = num * 10 + s[i] - '0';
            if ((!isdigit(s[i]) && s[i] != ' ')|| i == s.size() - 1) {
                if (sign == '+') {
                    result += pre;
                    pre = num;
                }
                else if (sign == '-') {
                    result += pre;
                    pre = -num;
                }
                else if (sign == '*')
                    pre *= num;
                else
                    pre /= num;
                sign = s[i];
                num = 0;
            }
        }
        return result + pre;
    }
};



//int main() {
//    Solution_227 sol;
//    string s("0");
//    cout << sol.calculate1(s) << endl;
//}