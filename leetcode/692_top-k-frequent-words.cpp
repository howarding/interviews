//Given a non-empty list of words, return the k most frequent elements.
//
//Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.
//
//Example 1:
//    Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
//    Output: ["i", "love"]
//    Explanation: "i" and "love" are the two most frequent words.
//        Note that "i" comes before "love" due to a lower alphabetical order.
//Example 2:
//    Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
//    Output: ["the", "is", "sunny", "day"]
//    Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
//        with the number of occurrence being 4, 3, 2 and 1 respectively.
//Note:
//    1. You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
//    2. Input words contain only lowercase letters.
//Follow up:
//    1. Try to solve it in O(n log k) time and O(n) extra space.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution_692 {
public:
    // LC347    Heap
    // Time:	O(n*log(k))
    // Space:	O(k)
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result;
        if (words.empty()) return result;
        unordered_map<string, int> dict;   // 先统计每个num次数
        for (string& word : words)
            dict[word]++;

        // pair<first, second>: first is word,  second is frequency
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> min_heap;
        for (auto&& pair : dict) {
            min_heap.push(pair);
            if (min_heap.size() > k)
                min_heap.pop();
        }
        while (!min_heap.empty()) {
            pair<string, int> ele = min_heap.top();
            result.push_back(ele.first);
            min_heap.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }

    struct cmp {
        bool operator()(pair<string, int>& a, pair<string, int>& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        }
    };
};


//int main() {
//    Solution_692 sol;
//    vector<string> words({"i", "love", "leetcode", "i", "love", "coding"});
//    int k = 1;
//    vector<string> result(sol.topKFrequent(words, k));
//    for (string& word : result)
//        cout << word << "\t";
//}