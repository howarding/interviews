//Given a collection of intervals, merge all overlapping intervals.
//
//For example,
//    Given [1,3],[2,6],[8,10],[15,18],
//return [1,6],[8,10],[15,18].

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
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        if (intervals.empty()) return result;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) { return a.start < b.start; });
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (result.back().end >= intervals[i].start)
                result.back().end = max(result.back().end, intervals[i].end);
            else
                result.push_back(intervals[i]);
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