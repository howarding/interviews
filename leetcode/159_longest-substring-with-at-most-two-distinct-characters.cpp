//Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
//
//For example, Given s = “eceba”,
//
//T is "ece" which its length is 3.

#include <iostream>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

class Solution_159 {
public:
    // Exp: https://discuss.leetcode.com/topic/26640/simple-o-n-java-solution-easily-extend-to-k-characters
    // Time:	O(n)
    // Space:	O(1)
    int lengthOfLongestSubstringTwoDistinct(string s) {
        map<char, int> last;    // 记录2个char的最新位置
        int max_len = 0, start = 0;    // start记录有效字符串的起始位置
        for (int i = 0; i < s.length(); i++) {
            if (last.find(s[i]) == last.end() && last.size() == 2) {
                map<char, int>::iterator iter = last.begin();
                if (iter->first == s[i - 1])
                    iter++;
                start = iter->second + 1;
                last.erase(iter);
            }
            last[s[i]] = i;
            max_len = max(max_len, i - start + 1);  // 每次循环都更新有效字符串的最大长度
        }
        return max_len;
    }
};

int main() {
    string s = "eceba";
    Solution_159 sol;
    cout << sol.lengthOfLongestSubstringTwoDistinct(s) << endl;
//    unordered_map<char, int> dict;
//    for (int i = 0; i < s.size(); i++)
//        dict[s[i]] = i;
//    for(auto&& pair: dict)
//        cout << pair.first << ' ' << pair.second << endl;
//    cout << endl;
//    for (int i = 0; i < s.size(); i++)
//        if (i % 2 == 0)
//            dict.erase(s[i]);
//    for(auto&& pair: dict)
//        cout << pair.first << ' ' << pair.second << endl;
}