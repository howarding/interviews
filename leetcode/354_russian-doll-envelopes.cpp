//ou have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
//
//What is the maximum number of envelopes can you Russian doll? (put one inside other)
//
//Example:
//    Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

#include <iostream>
#include <vector>

using namespace std;

class Solution_354 {
public:
    // 先排序 + LC300 Longest Increasing Subsequence
    // Exp: https://leetcode.com/problems/russian-doll-envelopes/discuss/82763/Java-NLogN-Solution-with-Explanation
    // Time:    O(n*log(n))
    // Space:   O(n)
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp;
        for (const vector<int>& envelope: envelopes) {
            int left = 0, right = dp.size() - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (envelope[1] <= dp[mid])
                    right = mid - 1;
                else left = mid + 1;
            }
            if (left == dp.size()) dp.push_back(envelope[1]);
            else dp[left] = envelope[1];
        }
        return dp.size();
    }

    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }
};