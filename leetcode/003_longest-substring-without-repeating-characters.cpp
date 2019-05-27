//Given a string, find the length of the longest substring without repeating characters.
//
//Examples:
//
//Given "abcabcbb", the answer is "abc", which the length is 3.
//
//Given "bbbbb", the answer is "b", with the length of 1.
//
//Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include <iostream>
#include <vector>

using namespace std;

class Solution_003 {
public:
    // Hash Table
    // Exp: https://discuss.leetcode.com/topic/24739/c-code-in-9-lines
    // Time:	O(n)
    // Space:	O(1)
    int lengthOfLongestSubstring(string s) {
        vector<int> ind(256, -1);
        int start = -1, result = 0;
        for (int i = 0; i < s.size(); i++) {
            if (ind[s[i]] >= 0)
                start = max(ind[s[i]], start);
            result = max(result, i - start);
            ind[s[i]] = i;
        }
        return result;
    }
};


//int main() {
//    Solution_003 sol;
//    string s = "bbbbb";
//    cout << sol.lengthOfLongestSubstring(s) << endl;
//}