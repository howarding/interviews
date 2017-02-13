//Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
//
//You have the following 3 operations permitted on a word:
//
//    a) Insert a character
//    b) Delete a character
//    c) Replace a character

#include <iostream>
#include <vector>

using namespace std;

class Solution_072 {
public:
    // 2D DP
    // Time:    O(mn)
    // Space:   O(n)
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if (!m * n) return !m ? n : m;
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++)
            dp[i] = i;
        int upper_val;
        for (int i = 1; i <= m; i++) {
            upper_val = dp[0]++;
            for (int j = 1; j <= n; j++) {
                int tmp = dp[j];
                dp[j] = min(min(dp[j - 1], dp[j]) + 1, upper_val + (word1[i - 1] != word2[j - 1]));
                upper_val = tmp;
            }
        }
        return dp[n];
    }
};