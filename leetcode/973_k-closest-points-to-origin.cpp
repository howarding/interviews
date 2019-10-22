//We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
//
//(Here, the distance between two points on a plane is the Euclidean distance.)
//
//You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)
//
//
//
//Example 1:
//
//    Input: points = [[1,3],[-2,2]], K = 1
//    Output: [[-2,2]]
//    Explanation:
//    The distance between (1, 3) and the origin is sqrt(10).
//    The distance between (-2, 2) and the origin is sqrt(8).
//    Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
//    We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
//
//Example 2:
//
//    Input: points = [[3,3],[5,-1],[-2,4]], K = 2
//    Output: [[3,3],[-2,4]]
//    (The answer [[-2,4],[3,3]] would also be accepted.)
//
//
//Note:
//
//    1. 1 <= K <= points.length <= 10000
//    2. -10000 < points[i][0] < 10000
//    3. -10000 < points[i][1] < 10000

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution_973 {
public:
    // max_heap
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

    // Quick Select
    // Time:
    //      best/avg:   O(n)
    //      worst:      O(n^2)
    // Space:   O(n)
    vector<vector<int>> kClosest1(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        quick_select(points, 0, points.size() - 1, K);
        for (int i = 0; i < K; i++) result.push_back(points[i]);
        return result;
    }

    void quick_select(vector<vector<int>>& points, int left, int right, int K) {
        int i = partition(points, left, right);
        int len = i - left + 1;
        if (len == K) return;
        if (len > K) quick_select(points, left, i - 1, K);
        else quick_select(points, i + 1, right, K - len);
    }

    int partition(vector<vector<int>>& points, int left, int right) {
        int pivot = dis(points[left]);
        int start = left++;
        while (left < right) {
            if (dis(points[left]) > pivot && dis(points[right]) < pivot)
                swap(points[left++], points[right--]);
            if (dis(points[left]) <= pivot) left++;
            if (dis(points[right]) >= pivot) right--;
        }
        swap(points[start], points[right]);
        return right;
    }

    int dis(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
};


int main() {
    Solution_973 sol;
    vector<vector<int>> points{{1, 3}, {-2, 2}};
    int K = 1;
    vector<vector<int>> result = sol.kClosest1(points, K);
    for (const vector<int>& point: result) {
        cout << point[0] << "\t" << point[1] << endl;
    }
}