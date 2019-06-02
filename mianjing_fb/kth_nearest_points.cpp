//input：一个n个点的列表list和k，选出list 中离原点最近的k个点
//讨论了直接sort, quickselect, heap各种做法的idea和时间复杂度之后，用heap的做法写这个题目
//    Follow up是当K的值非常大，应该怎么做。

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution_knp {
public:
    // max_heap
    // LC 215: Kth Largest Element in an Array
    // Exp: https://leetcode.com/problems/k-closest-points-to-origin/discuss/221532/C%2B%2B-STL-quickselect-priority_queue-and-multiset
    // Time:    O(n * log(k))
    // Space:   O(k)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        priority_queue<vector<int>, vector<vector<int>>, cmp> max_heap;
        for (const vector<int>& point: points) {
            max_heap.push(point);
            if (max_heap.size() > K)
                max_heap.pop();
        }
        while (!max_heap.empty()) {
            result.push_back(max_heap.top());
            max_heap.pop();
        }
        return result;
    }

    struct cmp {
        bool operator()(vector<int>& a, vector<int>& b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        }
    };
};