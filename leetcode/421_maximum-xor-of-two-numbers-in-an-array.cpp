//Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
//
//Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
//
//Could you do this in O(n) runtime?
//
//Example:
//
//    Input: [3, 10, 5, 25, 2, 8]
//
//    Output: 28
//
//    Explanation: The maximum result is 5 ^ 25 = 28.

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution_421 {
public:
    // Bit Manipulation
    // Exp: https://discuss.leetcode.com/topic/63213/java-o-n-solution-using-bit-manipulation-and-hashmap/49
    // Time:	O(n)
    // Space:	O(1)
    int findMaximumXOR(vector<int> &nums) {
        int max = 0, mask = 0;
        for (int i = 31; i >= 0; i--) {
            mask |= (1 << i);
            unordered_set<int> prefixes;
            for (int num : nums)
                prefixes.insert(num & mask);

            int tmp = max | (1 << i);
            for (int prefix : prefixes)
                if (prefixes.find(prefix ^ tmp) != prefixes.end())
                    max = tmp;
        }
        return max;
    }


    // Trie
    // Exp: https://discuss.leetcode.com/topic/63207/java-o-n-solution-using-trie
    // Time:	O(n)
    // Space:	O(1)
    struct TrieNode {
        vector<TrieNode *> child;

        TrieNode() : child(2) {}
    };

    int findMaximumXOR_1(vector<int> &nums) {
        if (nums.empty()) return 0;

        // Initialize Trie
        TrieNode *root = new TrieNode();
        for (int num : nums) {
            TrieNode *p = root;
            for (int i = 31; i >= 0; i--) {
                int digit = (num >> i) & 1;
                if (!p->child[digit])
                    p->child[digit] = new TrieNode();
                p = p->child[digit];
            }
        }

        // Search in Trie
        int max_len = 0;
        for (int num : nums) {
            TrieNode *p = root;
            int curSum = 0;
            for (int i = 31; i >= 0; i--) {
                int digit = (num >> i) & 1;
                if (p->child[digit ^ 1]) {
                    curSum += (1 << i);
                    p = p->child[digit ^ 1];
                } else
                    p = p->child[digit];
            }
            max_len = max(max_len, curSum);
        }
        return max_len;
    }
};