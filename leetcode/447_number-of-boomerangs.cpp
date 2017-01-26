//Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
//
//Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).
//
//Example:
//    Input:
//    [[0,0],[1,0],[2,0]]
//
//    Output:
//    2
//
//    Explanation:
//    The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_447 {
public:
    // Exp: https://discuss.leetcode.com/topic/66587/clean-java-solution-o-n-2-166ms
    // Time:	O(n^2)
    // Space:	O(n)
    int numberOfBoomerangs(vector<pair<int, int>> &points) {
        int result = 0;
        for (auto &point : points) {
            unordered_map<int, int> distance_count;
            for (auto &other : points)
                distance_count[getDistance(point, other)]++;
            for (auto &ele : distance_count)
                result += ele.second * (ele.second - 1);
        }
        return result;
    }

    int getDistance(pair<int, int> &point1, pair<int, int> &point2) {
        int x = point1.first - point2.first;
        int y = point1.second - point2.second;
        return x * x + y * y;
    }
};