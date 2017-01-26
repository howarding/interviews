//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
//For example,
//    Given [100, 4, 200, 1, 3, 2],
//    The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
//
//Your algorithm should run in O(n) complexity.

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution_128 {
public:
    // Exp: https://discuss.leetcode.com/topic/15383/simple-o-n-with-explanation-just-walk-each-streak/41
    // Time:	O(n)
    // Space:	O(n)
    int longestConsecutive(vector<int> &nums) {
        set<int> num_set;
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
            num_set.insert(*iter);
        int best = 0;
        for (set<int>::iterator iter = num_set.begin(); iter != num_set.end(); iter++) {
            int n = *iter;
            if (num_set.find(n - 1) == num_set.end()) {
                int m = n + 1;
                while (num_set.find(m) != num_set.end())
                    m++;
                best = max(m - n, best);
            }
        }
        return best;
    }
};