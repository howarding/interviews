//Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
//
//Note: The input string may contain letters other than the parentheses ( and ).
//
//Examples:
//    "()())()" -> ["()()()", "(())()"]
//    "(a)())()" -> ["(a)()()", "(a())()"]
//    ")(" -> [""]

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution_301 {
public:
    // DFS
    // Exp: https://discuss.leetcode.com/topic/34875/easy-short-concise-and-fast-java-dfs-3-ms-solution
    // Time:	O(n!)
    // Space:	O(n!)
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        remove(s, result, 0, 0, {'(', ')'});
        return result;
    }

    void remove(string s, vector<string> &result, int last_i, int last_j, vector<char> par) {
        int count = 0;
        for (int i = last_i; i < s.size(); i++) {
            if (s[i] == par[0]) count++;
            if (s[i] == par[1]) count--;
            if (count >= 0) continue;
            for (int j = last_j; j <= i; j++)
                if (s[j] == par[1] && (j == last_j || s[j - 1] != par[1]))
                    remove(s.substr(0, j) + s.substr(j + 1), result, i, j, par);
            return;
        }
        string reversed(s);
        reverse(reversed.begin(), reversed.end());
        if (par[0] == '(')
            remove(reversed, result, 0, 0, {')', '('});
        else
            result.push_back(reversed);
    }


    // FB: 结果只用输出一组解就可以
    // Stack
    // Time:	O(n)
    // Space:	O(n)
    string removeInvalidParentheses_fb(string s) {
        string result;
        stack<int> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') stk.push(i);
            if (s[i] == ')') {
                if (stk.empty()) s[i] = '_';
                else stk.pop();
            }
        }
        while(!stk.empty()) {
            s[stk.top()] = '_';
            stk.pop();
        }
        for (char c: s)
            if (c != '_')
                result.push_back(c);
        return result;
    }

    // FB: 结果只用输出一组解就可以
    // BEST: Count + In place
    // Time:	O(n)
    // Space:	O(1)
    string removeInvalidParentheses_fb1(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') count++;
            if (s[i] == ')') {
                if (count == 0) s[i] = '_';
                else count--;
            }
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            if (count == 0) break;
            if (s[i] == '(') {
                s[i] = '_';
                count--;
            }
        }
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '_')
                s[start++] = s[i];
        }
        s.resize(start);
    }
};


//int main() {
//    string s("()())())");
//    string s("(a)())()");
//    string s(")(");
//    string s("(238347)))()(((23r209)))()23239)(df0s9f0w0)w0e()))sf((");
//    Solution_301 sol;
//    vector<string> result(sol.removeInvalidParentheses(s));
//    for (string str : result)
//        cout << str << endl;
//    cout << sol.removeInvalidParentheses_fb(s) << endl;
//}