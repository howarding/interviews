//Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//
//For example,
//Given n = 3, there are a total of 5 unique BST's.
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3

#include <iostream>
#include <vector>

using namespace std;

class Solution_096 {
public:
    // DP   Great answer!
    // Exp: https://discuss.leetcode.com/topic/8398/dp-solution-in-6-lines-with-explanation-f-i-n-g-i-1-g-n-i
    // Time:	O(n)
    // Space:	O(n)
    int numTrees(int n) {
        if (n < 0) return 0;
        if (n == 0) return 1;
        vector<int> results(n+1, 0);
        results[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++)
                results[i] += results[j] * results[i - 1 - j];
        return results[n];
    }
};