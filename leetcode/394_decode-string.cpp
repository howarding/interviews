//Given an encoded string, return it's decoded string.
//
//The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
//
//You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
//
//Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
//
//Examples:
//
//    s = "3[a]2[bc]", return "aaabcbc".
//    s = "3[a2[c]]", return "accaccacc".
//    s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

#include <iostream>
#include <stack>

using namespace std;

class Solution_394 {
public:
    // Exp: https://discuss.leetcode.com/topic/57250/java-short-and-easy-understanding-solution-using-stack
    // Stack, Iterative
    // Time:    O(n)
    // Space:   O(n)
    string decodeString(string s) {
        stack<int> count;
        stack<string> result;
        int i = 0;
        result.push("");
        while (i < s.size()) {
            if (isdigit(s[i])) {
                int num = s[i] - '0';
                while (isdigit(s[i + 1]))
                    num = num * 10 + s[++i] - '0';
                count.push(num);
            } else if (s[i] == '[')
                result.push("");
            else if (s[i] == ']') {
                int num = count.top();
                count.pop();
                string &element = result.top();
                result.pop();
                string res;
                for (int j = 0; j < num; j++)
                    res.append(element);
                element = result.top();
                result.pop();
                result.push(element + res);
            } else {
                string &element = result.top();
                result.pop();
                result.push(element + s[i]);
            }
            i++;
        }
        return result.top();
    }


    // Exp: https://discuss.leetcode.com/topic/57228/0ms-simple-c-solution
    // Recursive
    // Time:    O(n)
    // Space:   O(n)
    string decodeString_1(string s) {
        int i = 0;
        return dfs(s, i);
    }

    string dfs(string s, int &i) {
        string res;

        while (i < s.length() && s[i] != ']') {
            if (!isdigit(s[i]))
                res += s[i++];
            else {
                int n = 0;
                while (i < s.length() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';

                i++; // '['
                string t = dfs(s, i);
                i++; // ']'

                while (n-- > 0)
                    res += t;
            }
        }
        return res;
    }
};


//int main() {
////    string s = "3[a10[bc]]";
//    string s = "2[abc]3[cd]ef";
////    string s = "23[abc34[cd]]56[xy]";
//    Solution_394 sol;
//    cout << sol.decodeString(s) << endl;
//}