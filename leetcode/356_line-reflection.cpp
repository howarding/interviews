//Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.
//
//Example 1:
//Given points = [[1,1],[-1,1]], return true.
//
//Example 2:
//Given points = [[1,1],[-1,-1]], return false.
//
//Follow up:
//Could you do better than O(n2)?
//
//Hint:
//
//    1. Find the smallest and largest x-value for all points.
//    2. If there is a line then it should be at y = (minX + maxX) / 2.
//    3. For each point, make sure that it has a reflected point in the opposite side.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution_356 {
public:
    // Exp: https://discuss.leetcode.com/topic/48172/simple-java-hashset-solution
    // Time:	O(n)
    // Space:	O(n)
    bool isReflected(vector<pair<int, int>> &points) {
        int max_x = INT_MIN, min_x = INT_MAX;
        unordered_map<int, unordered_set<int>> y_xs;
        for (auto &&point : points) {
            max_x = max(max_x, point.first);
            min_x = min(min_x, point.first);
            y_xs[point.second].insert(point.first);
        }
        int sum_x = min_x + max_x;
        for (auto &&point : points)
            if (y_xs[point.second].find(sum_x - point.first) == y_xs[point.second].end())
                return false;
        return true;
    }
};