//Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
//
//For example, Given s = “eceba”,
//
//T is "ece" which its length is 3.

#include <iostream>
#include <set>
#include <map>

using namespace std;

class Solution_159 {
public:
    // Exp: https://discuss.leetcode.com/topic/26640/simple-o-n-java-solution-easily-extend-to-k-characters
    // Time:	O(n)
    // Space:	O(1)
    int lengthOfLongestSubstringTwoDistinct(string s) {
        map<char, int> last;
        int max_len = 0, start = 0;
        for (int i = 0; i < s.length(); i++) {
            if (last.find(s[i]) == last.end() && last.size() == 2) {
                map<char, int>::iterator iter = last.begin();
                if (iter->first == s[i - 1])
                    iter++;
                start = iter->second + 1;
                last.erase(iter);
            }
            last[s[i]] = i;
            max_len = max(max_len, i - start + 1);
        }
        return max_len;
    }
};