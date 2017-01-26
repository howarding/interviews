//Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
//
//Note that it is the kth smallest element in the sorted order, not the kth distinct element.
//
//Example:
//
//    matrix = [
//        [ 1,  5,  9],
//        [10, 11, 13],
//        [12, 13, 15]
//    ],
//    k = 8,
//
//    return 13.
//Note:
//    You may assume k is always valid, 1 ≤ k ≤ n^2.

#include <iostream>
#include <vector>

using namespace std;

class Solution_378 {
public:
    // Exp: https://discuss.leetcode.com/topic/52865/my-solution-using-binary-search-in-c
    // Time:	O(nlog(n)log(max-min))
    // Space:	O(1)
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n - 1][n - 1];
        int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            int total = 0, max_v = INT_MIN;
            for (auto &row : matrix) {
                auto pos = upper_bound(row.begin(), row.end(), mid);
                max_v = max(max_v, pos == row.end() ? row[n - 1] : *(pos - 1));
                int num = pos - row.begin();
                total += num;
            }
            if (total == k) return max_v;
            if (total < k)
                low = max_v + 1;
            else
                high = max_v;
        }
        return -1;
    }
};