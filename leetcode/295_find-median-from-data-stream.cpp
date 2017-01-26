//Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
//
//Examples:
//[2,3,4] , the median is 3
//
//[2,3], the median is (2 + 3) / 2 = 2.5
//
//Design a data structure that supports the following two operations:
//
//    void addNum(int num) - Add a integer number from the data stream to the data structure.
//    double findMedian() - Return the median of all elements so far.
//For example:
//
//    addNum(1)
//    addNum(2)
//    findMedian() -> 1.5
//    addNum(3)
//    findMedian() -> 2

#include <iostream>
#include <queue>

using namespace std;

// Exp: https://discuss.leetcode.com/topic/27521/short-simple-java-c-python-o-log-n-o-1
// Time:	O(log(n)) for addNum()
//          O(1) for findMedian()
// Space:	O(n)
class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int, vector<int>, less<int>> max_heap;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

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
    }

    double findMedian() {
        return min_heap.size() == max_heap.size() ? (max_heap.top() + min_heap.top()) / 2.0 : min_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */