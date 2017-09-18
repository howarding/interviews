//Given an integer n, return 1 - n in lexicographical order.
//
//For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
//
//Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.

#include <iostream>
#include <vector>

using namespace std;

class Solution_386 {
public:
    // Exp: https://discuss.leetcode.com/topic/55131/ac-200ms-c-solution-beats-98
    // Time:	O(n)
    // Space:	O(1)
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int curr = 1;
        for (int i = 0; i < n; i++) {
            result.push_back(curr);
            if (curr * 10 <= n) curr *= 10;
            else {
                if (curr == n) curr /= 10;
                curr++;
                while (curr % 10 == 0) curr /= 10;
            }
        }
        return result;
    }
};