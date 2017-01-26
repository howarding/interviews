//Given a list of points that form a polygon when joined sequentially, find if this polygon is convex (Convex polygon definition).
//
//Note:
//
//    1. There are at least 3 and at most 10,000 points.
//    2. Coordinates are in the range -10,000 to 10,000.
//    3. You may assume the polygon formed by given points is always a simple polygon (Simple polygon definition). In other words, we ensure that exactly two edges intersect at each vertex, and that edges otherwise don't intersect each other.
//
//Example 1:
//
//    [[0,0],[0,1],[1,1],[1,0]]
//
//    Answer: True
//
//    Explanation:     -----
//                     |   |
//                     |   |
//                     -----
//Example 2:
//
//    [[0,0],[0,10],[10,10],[10,0],[5,5]]
//
//    Answer: False
//
//    Explanation:    ------
//                    |    |
//                    | /\ |
//                    |/  \|

#include <iostream>
#include <vector>

using namespace std;

class Solution_469 {
public:
    // Exp: My own algorithm, hard to explain.
    // Exp: https://discuss.leetcode.com/topic/62310/straightforward-java-8-main-lines-25ms
    // Time:	O(n)
    // Space:	O(1)
    bool isConvex(vector<vector<int>> &points) {
        int n = points.size();
        if (n <= 2) return false;
        if (n == 3) return true;
        int d = 0;
        for (int i = 3; i < n; i++) {
            int x23 = points[i - 2][0] - points[i - 1][0];
            int yi3 = points[i][1] - points[i - 1][1];
            int xi3 = points[i][0] - points[i - 1][0];
            int y23 = points[i - 2][1] - points[i - 1][1];
            int x13 = points[0][0] - points[i - 1][0];
            int y13 = points[0][1] - points[i - 1][1];
            int x12 = points[0][0] - points[i - 2][0];
            int y12 = points[0][1] - points[i - 2][1];
            int d1 = x12 * y23 - x23 * y12;
            int d2 = x23 * yi3 - xi3 * y23;
            int d3 = x13 * yi3 - xi3 * y13;
            d = d1;
            if (!((d1 <= 0 && d2 >= 0 && d3 >= 0) ||
                  (d1 >= 0 && d2 <= 0 && d3 <= 0)))
                return false;
        }
        int x23 = points[n - 1][0] - points[0][0];
        int yi3 = points[1][1] - points[0][1];
        int xi3 = points[1][0] - points[0][0];
        int y23 = points[n - 1][1] - points[0][1];
        int x13 = points[n - 2][0] - points[0][0];
        int y13 = points[n - 2][1] - points[0][1];
        int d2 = x23 * yi3 - xi3 * y23;
        int d3 = x13 * yi3 - xi3 * y13;
        if (!((d <= 0 && d2 >= 0 && d3 >= 0) ||
              (d >= 0 && d2 <= 0 && d3 <= 0)))
            return false;
        return true;
    }
};


//int main() {
////    vector<vector<int>> a({{0, 0}, {1, 0}, {1, 1}, {0, 1}});
//    vector<vector<int>> a({{-2, 2}, {-1, 2}, {0, 2}, {1, 2}, {2, 2}, {2, 1}, {2, 0}, {2, -1}, {2, -2}, {1, -2}, {0, -2}, {-1, -2}, {-2, -2}, {-2, -1}, {-2, 0}, {-2, 1}});
//    Solution_469 sol;
//    bool res = sol.isConvex(a);
//    cout << res << endl;
//}