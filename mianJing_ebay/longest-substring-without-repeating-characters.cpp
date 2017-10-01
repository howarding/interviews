//Given a string, find the length of the longest substring without repeating characters.
//Example
//For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
//
//For "bbbbb" the longest substring is "b", with the length of 1.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /*
     * @param s: a string
     * @return: an integer
     */
    // 2 Pointers
    // Time:	O(n)
    // Space:	O(1)
    int lengthOfLongestSubstring(string &s) {
        // write your code here
        if (s.size() < 2) return s.size();
        vector<int> chars(256, -1);
        int result = 0, start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (chars[s[i]] >= 0) {
                result = max(result, i - start);
                start = chars[s[i]] + 1;
                for (int j = 0; j < 256; j++)
                    if (chars[j] < chars[s[i]]) chars[j] = -1;
            }
            chars[s[i]] = i;
        }
        result = max(result, int(s.size() - start));
        return result;
    }
};


//int main() {
//    Solution sol;
//    string s("gehmbfqmozbpripibusbezagafqtypz");
//    cout << sol.lengthOfLongestSubstring(s) << endl;
//}