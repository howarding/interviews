//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
//
//click to show follow up.
//
//Follow up:
//Did you use extra space?
//A straight forward solution using O(mn) space is probably a bad idea.
//A simple improvement uses O(m + n) space, but still not the best solution.
//Could you devise a constant space solution?

#include <iostream>
#include <vector>

using namespace std;

class Solution_073 {
public:
    // In-place Mark
    // Time:	O(mn)
    // Space:	O(1)
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty()) return;
        int m = matrix.size();
        int n = matrix[0].size();
        bool row0 = false, column0 = false;
        for (int i = 0; i < n; i++)
            if (matrix[0][i] == 0) {
                row0 = true;
                break;
            }
        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0) {
                column0 = true;
                break;
            }
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        if (column0)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        if (row0)
            for (int i = 0; i < n; i++)
                matrix[0][i] = 0;
    }
};