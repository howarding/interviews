//Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
//
//Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
//
//The order of output does not matter.
//
//Example 1:
//
//    Input:
//    s: "cbaebabacd" p: "abc"
//
//    Output:
//    [0, 6]
//
//    Explanation:
//    The substring with start index = 0 is "cba", which is an anagram of "abc".
//    The substring with start index = 6 is "bac", which is an anagram of "abc".
//Example 2:
//
//    Input:
//    s: "abab" p: "ab"
//
//    Output:
//    [0, 1, 2]
//
//    Explanation:
//    The substring with start index = 0 is "ab", which is an anagram of "ab".
//    The substring with start index = 1 is "ba", which is an anagram of "ab".
//    The substring with start index = 2 is "ab", which is an anagram of "ab".

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_438 {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()) return result;
        unordered_map<int, int> dict;
        for (char c : p)
            dict[c - 'a']++;
        int left = 0, right = 0, count = p.size();
        while (right < s.size()) {
            //move right every time, if the character exists in p's dict, decrease the count
            //current dict value > 0 means the character is existing in p
            if (dict[s[right++] - 'a']-- > 0) count--;

            //when the count is down to 0, means we found the right anagram
            //then add window's left to result list
            if (count == 0) result.push_back(left);

            //if we find the window's size equals to p, then we have to move left (narrow the window) to find the new match window
            //++ to reset the dict because we kicked out the left
            //only increase the count if the character is in p
            //the count >= 0 indicate it was original in the dict, cuz it won't go below 0
            if (right - left == p.size() && dict[s[left++] - 'a']++ >= 0) count++;
        }
        return result;
    }
};