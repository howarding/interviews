#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

    // 2 Pointers
    // Time:    O(n)
    // Space:   O(1)
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while(left < right){
            if(!isalnum(s[left]))
                left++;
            else if(!isalnum(s[right]))
                right--;
            else if(tolower(s[left++]) != tolower(s[right--]))
                return false;
        }
        return true;
    }


    // considering all chars
    // Reverse
    bool isPalindrome1(string s) {
        string t(s);
        reverse(t.begin(), t.end());
        return t == s;
    }


//Given a string s, find the longest palindromic substring in s.

    // Expand around center, BEST
    // Time:	O(n^2)
    // Space:	O(1)
    string longestPalindrome(string s) {
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


    // DP
    // Time:	O(n^2)
    // Space:	O(n^2)
    string longestPalindrome1(string s) {
        int n = s.size();
        if (n <= 1) return s;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxLen = 0;
        string result = "";
        dp[n-1][n-1] = true;
        for (int i = n - 2; i >= 0; i--) {
            int maxJ = i;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j] && (j < i + 3 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    maxJ = j;
                } else dp[i][j] = false;
            }
            if (maxJ - i + 1 > maxLen) {
                maxLen = maxJ - i + 1;
                result = s.substr(i, maxLen);
            }
        }
        return result;
    }



//check if a Integer is Palindrome
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        int rev = 0;
        while (x > rev) {
            rev  = rev * 10 + x % 10;
            x /= 10;
        }
        return (x == rev || x == rev / 10);
    }

};