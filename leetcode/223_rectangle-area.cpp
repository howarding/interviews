//Find the total area covered by two rectilinear rectangles in a 2D plane.
//
//Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
//
//Rectangle Area
//Assume that the total area is never beyond the maximum possible value of int.

#include <iostream>

using namespace std;

class Solution_223 {
public:
    // Exp: https://discuss.leetcode.com/topic/17705/just-another-short-way
    // Time:	O(1)
    // Space:	O(1)
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (D - B) * (C - A);
        int area2 = (H - F) * (G - E);
        int left = max(A, E), right = max(min(C, G), left);
        int bottom = max(B, F), top = max(min(D, H), bottom);
        return area1 + area2 - (right - left) * (top - bottom);
    }



    // My own.
    // Time:	O(1)
    // Space:	O(1)
    int computeArea1(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (D - B) * (C - A);
        int area2 = (H - F) * (G - E);
        int overlap_x = min(C, G) < max(A, E) ? 0 : min(C, G) - max(A, E);  // avoid overflow
        int overlap_y = min(D, H) < max(B, F) ? 0 : min(D, H) - max(B, F);  // avoid overflow
        return area1 + area2 - overlap_x * overlap_y;
    }
};