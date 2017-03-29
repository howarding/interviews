//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution_020 {
public:
    // Exp: Stack
    // Time:	O(n)
    // Space:	O(n)
    bool isValid(string s) {
        unordered_map<char, char> dict = {{'(', ')'},
                                          {'[', ']'},
                                          {'{', '}'}};
        stack<char> sta;
        if (s.empty()) return true;
        for (char c : s) {
            if (dict.find(c) != dict.end()) {
                sta.push(c);
                continue;
            } else if (sta.empty() || dict[sta.top()] != c)
                return false;
            sta.pop();
        }
        return sta.empty();
    }
};


//int main() {
//    string s = "()";
//    Solution_020 sol;
//    cout << sol.isValid(s) << endl;
//}