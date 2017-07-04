//You are given an n x n 2D matrix representing an image.
//
//Rotate the image by 90 degrees (clockwise).
//
//Follow up:
//Could you do this in-place?

#include <iostream>
#include <vector>

using namespace std;

class Solution_048 {
public:
    // My own
    // Time:	O(n^2)
    // Space:	O(1)
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++)
            for (int j = 0; j < (n + 1) / 2; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
    }
};