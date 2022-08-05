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
    // Exp: https://leetcode.com/problems/longest-valid-parentheses/solution/
    // Time:	O(n)    One pass
    // Space:	O(n)
    int longestValidParentheses(string s) {
        stack<int> stk;
        int result = 0;
        stk.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') stk.push(i);
            else {
                stk.pop();
                if (stk.empty())
                    stk.push(i);
                else
                    result = max(result, i - stk.top());
            }
        }
        return result;
    }

    // DP
    // Exp: https://discuss.leetcode.com/topic/2426/my-dp-o-n-solution-without-using-stack
    // Time:	O(n)
    // Space:	O(n)
    int longestValidParentheses1(string s) {
        // TODO: Complete it.
        return -1;
    }
};


//int main() {
//    Solution_032 sol;
//    string s = "(()";
//    cout << sol.longestValidParentheses(s) << endl;
//}