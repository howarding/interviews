//You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
//
//For example, given:
//s: "barfoothefoobarman"
//words: ["foo", "bar"]
//
//You should return the indices: [0,9].
//(order does not matter).

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_030 {
public:
    // Exp: https://discuss.leetcode.com/topic/6617/an-o-n-solution-with-detailed-explanation
    // Time:	O(kn)   n: length of s  k: length of each word
    // Space:	O(n)
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        int total = words.size(), length = words[0].size(), n = s.size();
        unordered_map<string, int> dict;
        for(string& word : words) dict[word]++;

        for (int i = 0; i < length; i++) {
            int left = i, count = 0;
            unordered_map<string, int> tmp_dict;
            for (int j = i; j <= n - length; j += length) {
                string word = s.substr(j, length);
                if (dict.count(word)) {
                    if (++tmp_dict[word] <= dict[word]) count++;
                    while (tmp_dict[word] > dict[word]) {
                        string tmp = s.substr(left, length);
                        if (--tmp_dict[tmp] < dict[tmp]) count--;
                        left += length;
                    }

                    if (count == total) {
                        result.push_back(left);
                        tmp_dict[s.substr(left, length)]--;
                        count--;
                        left += length;
                    }
                } else {
                    tmp_dict.clear();
                    left = j + length;
                    count = 0;
                }
            }
        }
        return result;
    }
};


//int main() {
//    Solution_030 sol;
//    string s = "mississippi";
//    vector<string> words({"mississippis"});
//    vector<int> result(sol.findSubstring(s, words));
//    for (int ind : result)
//        cout << ind << endl;
//}