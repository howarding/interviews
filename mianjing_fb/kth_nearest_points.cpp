//input：一个n个点的列表list和k，选出list 中离远点最近的k个点
//讨论了直接sort, quickselect, heap各种做法的idea和时间复杂度之后，用heap的做法写这个题目
//    Follow up是当K的值非常大，应该怎么做。

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Point {
    int x, y;

    Point(int a, int b) : x(a), y(b) {};
};

class Solution_knp {
public:
    // max_heap
    // LC 215: Kth Largest Element in an Array
    // Exp: http://siyang2notleetcode.blogspot.com/2015/02/k-nearest-points-to-origin.html
    // Time:    O(n * log(k))
    // Space:   O(k)
    vector<Point> kNearestPoints(vector<Point> points, int k) {
        priority_queue<Point, vector<Point>, cmp> max_heap;
        for (auto &point : points) {
            if (max_heap.size() < k)
                max_heap.push(point);
            else {
                Point top = max_heap.top();
                int dis1 = top.x * top.x + top.y * top.y;
                int dis2 = point.x * point.x + point.y * point.y;
                //如果大于等于max，说明该数至少比k个数大，舍去之。
                //如果小于max，说明该数这个max至少比k个数大，poll()掉这个max，push进该数。
                //最后剩在heap里就是最小的k个了。
                if (dis1 > dis2) {
                    max_heap.push(point);
                    max_heap.pop();
                }
            }
        }
        vector<Point> result;
        while (!max_heap.empty()) {
            Point top = max_heap.top();
            max_heap.pop();
            result.push_back(top);
        }
        reverse(result.begin(), result.end());
        return result;
    }

    struct cmp {
        bool operator()(Point a, Point b) {
            return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
        }
    };
};