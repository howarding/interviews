//Given a string, sort it in decreasing order based on the frequency of characters.
//
//Example 1:
//
//    Input:
//    "tree"
//
//    Output:
//    "eert"
//
//    Explanation:
//    'e' appears twice while 'r' and 't' both appear once.
//    So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
//Example 2:
//
//    Input:
//    "cccaaa"
//
//    Output:
//    "cccaaa"
//
//    Explanation:
//        Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
//    Note that "cacaca" is incorrect, as the same characters must be together.
//Example 3:
//
//    Input:
//    "Aabb"
//
//    Output:
//    "bbAa"
//
//    Explanation:
//    "bbaA" is also a valid answer, but "Aabb" is incorrect.
//    Note that 'A' and 'a' are treated as two different characters.

#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution_451 {
public:
    // Exp: https://discuss.leetcode.com/topic/66024/java-o-n-bucket-sort-solution-o-nlogn-priorityqueue-solution-easy-to-understand
    // Time:	O(nlog(n))
    // Space:	O(n)
    string frequencySort(string s) {
        string result;
        if (s.empty()) return result;
        unordered_map<char, int> map;
        for (char c : s)
            map[c]++;
        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> max_heap;
        for (auto ele: map)
            max_heap.push(pair<int, char>({ele.second, ele.first}));
        while (!max_heap.empty()) {
            auto ele = max_heap.top();
            max_heap.pop();
            result.append(ele.first, ele.second);
        }
        return result;
    }

    struct cmp {
        bool operator()(pair<int, char> a, pair<int, char> b) {
            return a.first < b.first;
        }
    };
};


//int main() {
//    string s = "tree";
//    Solution_451 sol;
//    cout << sol.frequencySort(s) << endl;
//}