//Given a stream of numbers, how to calculate average, standard deviation, median?

#include <iostream>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

//  Space: O(n)
class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int, vector<int>, less<int>> max_heap;
    double avg, sqr_avg;    // for avg and std
    int count;              // for avg and std
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    //  Time: O(log(n))
    void addNum(int num) {
        if (min_heap.empty()) {
            min_heap.push(num);
            return;
        }
        if (min_heap.size() == max_heap.size()) {
            int ele = max_heap.top();
            if (num < ele) {
                min_heap.push(ele);
                max_heap.pop();
                max_heap.push(num);
            } else
                min_heap.push(num);
        } else {
            int ele = min_heap.top();
            if (num > ele) {
                max_heap.push(ele);
                min_heap.pop();
                min_heap.push(num);
            } else
                max_heap.push(num);
        }


        avg = avg / (count + 1) * count + num * 1.0 / (count + 1);
        sqr_avg = sqr_avg / (count + 1) * count + num * num * 1.0 / (count + 1);
        count++;
    }

    //  Time: O(1)
    double findMedian() {
        return min_heap.size() == max_heap.size()
               ? (max_heap.top() + min_heap.top()) / 2.0
               : min_heap.top();
    }


    //  Time: O(1)
    double findAverage() {
        return avg;
    }


    //  Time: O(1)
    double findStd() {
        return sqrt(avg * avg - sqr_avg);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

//int main()
//{
//    cout << setprecision(1) << fixed;
//    int n, a;
//    cin >> n;
//    MedianFinder obj;
//    for(int i = 1; i<=n; i++)
//    {
//        cin >> a;
//        obj.addNum(a);
//        cout << obj.findMedian() << endl;
//    }
//}