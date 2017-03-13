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
        for (int count = 0, i = last_i; i < s.size(); i++) {
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
};


//int main() {
//    string s("()())())");
//    Solution_301 sol;
//    vector<string> result(sol.removeInvalidParentheses(s));
//    for (string str : result)
//        cout << str << endl;
//}