//Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
//
//For example,
//Given [[0, 30],[5, 10],[15, 20]],
//return false.

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
class Solution_252 {
public:
    // Exp: https://discuss.leetcode.com/topic/20936/easy-c-solution-with-explanations
    // Time:	O(nlog(n))
    // Space:	O(1)
    bool canAttendMeetings(vector<Interval> &intervals) {
        if (intervals.size() == 0) return true;
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 0; i < intervals.size() - 1; i++)
            if (intervals[i].end > intervals[i + 1].start)
                return false;
        return true;
    }

    static bool cmp(Interval a, Interval b) {
        return a.start < b.start;
    }
};