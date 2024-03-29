//You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start
// and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval
// newInterval = [start, end] that represents the start and end of another interval.
//
//Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still
// does not have any overlapping intervals (merge overlapping intervals if necessary).
//
//Return intervals after the insertion.
//
//
//
//Example 1:
//
//Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
//Output: [[1,5],[6,9]]
//Example 2:
//
//Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
//Output: [[1,2],[3,10],[12,16]]
//Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
//
//
//Constraints:
//
//0 <= intervals.length <= 104
//intervals[i].length == 2
//0 <= starti <= endi <= 105
//intervals is sorted by starti in ascending order.
//newInterval.length == 2
//0 <= start <= end <= 105

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
class Solution_057 {
public:
    // Exp: https://discuss.leetcode.com/topic/12899/very-short-and-easy-to-understand-c-solution/4
    // Time:	O(n)
    // Space:	O(n)
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        const vector<vector<int>>::size_type n = intervals.size();
        int i = 0;
        while (i < n && intervals[i].back() < newInterval.front()) {
            result.push_back(intervals[i++]);
        }
        newInterval.front() = i == n ? newInterval.front() : min(newInterval.front(), intervals[i].front());
        while (i < n && intervals[i].front() <= newInterval.back())
            i++;
        newInterval.back() = i == 0 ? newInterval.back() : max(newInterval.back(), intervals[i - 1].back());
        result.push_back(newInterval);
        while (i < n)
            result.push_back(intervals[i++]);
        return result;
    }
};