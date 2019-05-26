//Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
//For example,
//Given n = 3,
//
//You should return the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

#include <iostream>
#include <vector>

using namespace std;

class Solution_059 {
public:
    // LC54 Spiral matrix I
    // Time:	O(n)
    // Space:	O(1)
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int x0 = 0, x1 = n - 1;
        int y0 = 0, y1 = n - 1;
        int i, j, num = 0;
        while (x0 <= x1 && y0 <= y1) {
            for (j = y0; j <= y1; j++)
                result[x0][j] = ++num;
            x0++;
            for (i = x0; i <= x1; i++)
                result[i][y1] = ++num;
            y1--;
            if (x0 > x1) break;
            for (j = y1; j >= y0; j--)
                result[x1][j] = ++num;
            x1--;
            if (y0 > y1) break;
            for (i = x1; i >= x0; i--)
                result[i][y0] = ++num;
            y0++;
        }
        return result;
    }


    // Exp: https://discuss.leetcode.com/topic/7282/simple-c-solution-with-explaination
    // Time:	O(n)
    // Space:	O(1)
    vector<vector<int>> generateMatrix2(int n) {
        vector<vector<int>> ret(n, vector<int>(n));
        int k = 1, i = 0;
        while (k <= n * n) {
            int j = i;
            // four steps
            while (j < n - i)             // 1. horizonal, left to right
                ret[i][j++] = k++;
            j = i + 1;
            while (j < n - i)             // 2. vertical, top to bottom
                ret[j++][n - i - 1] = k++;
            j = n - i - 2;
            while (j > i)                  // 3. horizonal, right to left
                ret[n - i - 1][j--] = k++;
            j = n - i - 1;
            while (j > i)                  // 4. vertical, bottom to  top
                ret[j--][i] = k++;
            i++;      // next loop
        }
        return ret;
    }
};