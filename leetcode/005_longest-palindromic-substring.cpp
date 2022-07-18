//Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
//Example:
//
//        Input: "babad"
//
//        Output: "bab"
//
//        Note: "aba" is also a valid answer.
//Example:
//
//        Input: "cbbd"
//
//        Output: "bb"

#include <iostream>

using namespace std;

class Solution_005 {
public:
    // Faster, skip palindrome checks on duplicate chars
    // Exp: https://discuss.leetcode.com/topic/12187/simple-c-solution-8ms-13-lines
    // Exp: https://leetcode.com/problems/longest-palindromic-substring/solution/
    // Time:	O(n^2)
    // Space:	O(1)
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s.size() == 1) return s;
        int start_ind = 0, max_len = 1;
        for (int i = 0; i < s.size(); i++) {
            if ((s.size() - i) * 2 <= max_len) break;
            int start = i, end = i;
            while (end + 1 < s.size() && s[end + 1] == s[end]) end++;
            i = end;
            while (end + 1 < s.size() && start > 0 && s[end+1] == s[start-1]) {
                start--;
                end++;
            }
            int length = end - start + 1;
            if (length > max_len) {
                start_ind = start;
                max_len = length;
            }
        }
        return s.substr(start_ind, max_len);
    }

    // Exp: my own
    // Time:	O(n^2)
    // Space:	O(1)
    string longestPalindrome2(string s) {
        string result = "";
        if (s.empty()) return result;
        for (int i = 0; i < s.size(); i++) {
            int j = 0;
            while (i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]) {
                if (result.size() < 2 * j + 1)
                    result = s.substr(i-j, 2*j+1);
                j++;
            }
            j = 1;
            while (i - j >= 0 && i + j - 1 < s.size() && s[i - j] == s[i + j - 1]) {
                if (result.size() < 2 * j)
                    result = s.substr(i-j, 2*j);
                j++;
            }
        }
        return result;
    }

    // Exp: DP
    // Time:	O(n^2)
    // Space:	O(n^2)
    string longestPalindrome3(string s) {}
};


//int main() {
//    Solution_005 sol;
//    string s = "babad";
//    cout << sol.longestPalindrome(s) << endl;
//}