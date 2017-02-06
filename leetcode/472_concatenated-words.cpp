//Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
//
//A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.
//
//Example:
//    Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
//
//    Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
//
//    Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";
//    "dogcatsdog" can be concatenated by "dog", "cats" and "dog";
//    "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
//Note:
//    1. The number of elements of the given array will not exceed 10,000
//    2. The length sum of elements in the given array will not exceed 600,000.
//    3. All the input string will only include lower case letters.
//    4. The returned elements order does not matter.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_472 {
    struct TrieNode {
        bool isEnd;
        unordered_map<char, TrieNode *> child;

        TrieNode() : isEnd(false) {}
    };

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        vector<string> result;
        if (words.empty()) return result;
        sort(words.begin(), words.end(), cmp);
        TrieNode *root = new TrieNode();
        for (string word : words) {
            if (word.empty()) continue;
            if (dfs(word, 0, root)) {
                result.push_back(word);
                continue;
            }
            TrieNode *p = root;
            for (char c : word) {
                if (p->child.find(c) == p->child.end())
                    p->child[c] = new TrieNode();
                p = p->child[c];
            }
            p->isEnd = true;
        }
        return result;
    }

    bool dfs(string &word, int i, TrieNode *root) {
        if (word.empty()) return true;
        bool result = false;
        int n = word.size();
        int height = 0;
        TrieNode *p = root;
        while (i < n) {
            if (p->isEnd)
                result |= dfs(word, i, root);
            if (p->child.find(word[i]) == p->child.end())
                return result;
            p = p->child[word[i++]];
            height++;
        }
        return result || (p->isEnd && n > height);
    }

    static bool cmp(string &a, string &b) {
        return a.size() < b.size();
    }
};


//int main() {
//    vector<string> words({"cat","cats","catsdogcats","dog", ""});
////    vector<string> words({"cat","cats","catsdogcats","dog"});
//    Solution_472 sol;
//    vector<string> result = sol.findAllConcatenatedWordsInADict(words);
//    for (auto& word : result)
//        cout << word << endl;
//}