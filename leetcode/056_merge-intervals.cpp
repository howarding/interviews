//Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array
// of the non-overlapping intervals that cover all the intervals in the input.
//
//Example 1:
//
//Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
//Output: [[1,6],[8,10],[15,18]]
//Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
//Example 2:
//
//Input: intervals = [[1,4],[4,5]]
//Output: [[1,5]]
//Explanation: Intervals [1,4] and [4,5] are considered overlapping.

#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution_056 {
public:
    // Exp: https://discuss.leetcode.com/topic/20263/c-10-line-solution-easing-understanding
    // Time:	O(n*log(n))
    // Space:	O(n)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.empty()) return result;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) { return a.front() < b.front(); });
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (result.back()[1] >= intervals[i].front()) {
                result.back()[1] = max(result.back()[1], intervals[i].back());
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};


//int main() {
//    Solution_056 sol;
//    vector<Interval> intervals(
//        {
//            Interval(8, 10),
//            Interval(2, 6),
//            Interval(15, 18),
//            Interval(1, 3)
//        }
//    );
//    vector<Interval> result = sol.merge(intervals);
//    for (int i = 0; i < result.size(); i++) {
//        cout << result[i].start << "\t" << result[i].end << endl;
//    }
//}