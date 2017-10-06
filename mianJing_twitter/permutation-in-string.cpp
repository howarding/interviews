//给两个字符串s1和s2，找出s2的任何permutation第一次在s1中出现时的index，返回index. 我用了一个map存s2的所有字符和出现次数，
//对s1中的每个字符，查它在不在map里，同时更新map，直到找到一个s2的permutation。worst case是O(n2)。面试官问有没有更优的解法，
//没想出来

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // s1 in s2

    // Sliding window, BEST
    // Time:	O(n)
    // Space:	O(1)
    bool checkInclusion1(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> s1Dict(26, 0), s2Dict(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            s1Dict[s1[i] - 'a']++;
            s2Dict[s2[i] - 'a']++;
        }
        for (int i = 0; i < s2.size() - s1.size(); i++) {
            if (matches(s1Dict, s2Dict)) return true;
            s2Dict[s2[i] - 'a']--;
            s2Dict[s2[i + s1.size()] - 'a']++;
        }
        return matches(s1Dict, s2Dict);
    }


    bool matches(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < 26; i++)
            if (a[i] != b[i]) return false;
        return true;
    }




    // HashMap
    // Time:	O(mn)
    // Space:	O(1)
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> s1Dict(26, 0);
        for (char c : s1)
            s1Dict[c - 'a']++;
        for (int i = 0; i < s2.size() - s1.size(); i++) {
            vector<int> s2Dict(26, 0);
            for (int j = 0; j < s1.size(); j++)
                s2Dict[s2[i+j] - 'a']++;
            if (match(s1Dict, s2Dict)) return true;
        }
        return false;
    }

    bool match(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < 26; i++)
            if (a[i] != b[i]) return false;
        return true;
    }
};