//Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
//For "(()", the longest valid parentheses substring is "()", which has length = 2.
//
//Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

#include <iostream>
#include <stack>

using namespace std;

class Solution_032 {
public:
    // Stack
    // Exp: https://discuss.leetcode.com/topic/2289/my-o-n-solution-using-a-stack
    // Time:	O(n)
    // Space:	O(n)
    int longestValidParentheses(string s) {
        stack<int> stk;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == ')' && !stk.empty() && s[stk.top()] == '(')
                stk.pop();
            else
                stk.push(i);
        if (stk.empty()) return s.size();
        int result = 0, top = s.size();
        while (!stk.empty()) {
            int ind = stk.top();
            stk.pop();
            result = max(result, top - ind - 1);
            top = ind;
        }
        result = max(result, top);
        return result;
    }


    // DP
    // Exp: https://discuss.leetcode.com/topic/2426/my-dp-o-n-solution-without-using-stack
    // Time:	O(n)
    // Space:	O(n)
    int longestValidParentheses1(string s) {
        // TODO: Complete it.
    }
};


//int main() {
//    Solution_032 sol;
//    string s = "(()";
//    cout << sol.longestValidParentheses(s) << endl;
//}