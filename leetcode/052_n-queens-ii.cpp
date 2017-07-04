//Follow up for N-Queens problem.
//
//Now, instead outputting board configurations, return the total number of distinct solutions.

#include <iostream>
#include <vector>

using namespace std;

class Solution_052 {
public:
    // Refer to 051_n-queens.cpp
    // Time:	O(n^2)
    // Space:	O(n)
    int totalNQueens(int n) {
        if (n <= 0) return 0;
        vector<bool> row(n, false);
        vector<bool> column(n, false);
        vector<bool> slash(2 * n - 1, false);
        vector<bool> anti_slash(2 * n - 1, false);
        return helper(n, row, column, slash, anti_slash, 0);
    }

    int helper(
            int n,
            vector<bool>& row,
            vector<bool>& column,
            vector<bool>& slash,
            vector<bool>& anti_slash,
            int x
    ) {
        if (x == n) return 1;
        int result = 0;
        for (int j = 0; j < n; j++) {
            if (row[x] || column[j] || slash[x+j] || anti_slash[n-1+x-j])
                continue;
            row[x] = column[j] = slash[x+j] = anti_slash[n-1+x-j] = true;
            result += helper(n, row, column, slash, anti_slash, x + 1);
            row[x] = column[j] = slash[x+j] = anti_slash[n-1+x-j] = false;
        }
        return result;
    }
};