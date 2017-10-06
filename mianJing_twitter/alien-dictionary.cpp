//There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
//
//Example 1:
//Given the following words in dictionary,
//
//    [
//        "wrt",
//        "wrf",
//        "er",
//        "ett",
//        "rftt"
//    ]
//The correct order is: "wertf".
//
//Example 2:
//Given the following words in dictionary,
//
//    [
//        "z",
//        "x"
//    ]
//The correct order is: "zx".
//
//Example 3:
//Given the following words in dictionary,
//
//    [
//        "z",
//        "x",
//        "z"
//    ]
//The order is invalid, so return "".
//
//Note:
//    1. You may assume all letters are in lowercase.
//    2. You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
//    3. If the order is invalid, return an empty string.
//    4. There may be multiple valid order of letters, return any one of them is fine.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution_ad {
public:
    // Topological Sort, BFS, queue.
    // Time:	O(V + E)
    // Space:	O(V)
    string alienOrder(vector<string> &words) {
        string result;
        if (words.empty()) return result;
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;
        unordered_set<char> chars;
        queue<char> que;
        int count = 0;  // to detect whether there's a loop in the graph
        for (int i = 0; i < words.size(); i++) {
            bool compared = false;
            for (int j = 0; j < words[i].size(); j++) {
                chars.insert(words[i][j]);
                if (i > 0 && j < words[i - 1].size() && !compared && words[i - 1][j] != words[i][j]) {
                    adj[words[i - 1][j]].push_back(words[i][j]);
                    indegree[words[i][j]]++;
                    compared = true;
                }
            }
        }

        for (char c : chars)
            if (!indegree[c])
                que.push(c);

        while (!que.empty()) {
            char c = que.front();
            que.pop();
            result.push_back(c);
            count++;
            for (char child : adj[c])
                if (--indegree[child] == 0)
                    que.push(child);
        }
        return count == chars.size() ? result : "";
    }
};


//int main() {
//    vector<string> words({"wnlb"});
//    Solution_269 sol;
//    cout << sol.alienOrder(words) << endl;
//}