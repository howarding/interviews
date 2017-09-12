//Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
//
//Examples:
//
//    s = "leetcode"
//    return 0.
//
//    s = "loveleetcode",
//    return 2.
//Note: You may assume the string contain only lowercase letters.

#include <iostream>
#include <vector>

using namespace std;

class Solution_387 {
public:
    // Exp: https://discuss.leetcode.com/topic/55082/c-2-solutions
    // Time:	O(n)
    // Space:	O(1)
    int firstUniqChar(string s) {
        if (s.empty()) return -1;
        vector<int> dict(26, 0);
        for (char c : s)
            dict[c - 'a']++;
        for (int i = 0; i < s.size(); i++)
            if (dict[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};


//int main() {
//    Solution_387 sol;
//    string s("leetcode");
//    cout << sol.firstUniqChar(s) << endl;
//}