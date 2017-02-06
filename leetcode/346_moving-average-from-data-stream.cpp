//Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
//
//For example,
//    MovingAverage m = new MovingAverage(3);
//    m.next(1) = 1
//    m.next(10) = (1 + 10) / 2
//    m.next(3) = (1 + 10 + 3) / 3
//    m.next(5) = (10 + 3 + 5) / 3

#include <iostream>
#include <queue>

using namespace std;

// Exp: https://discuss.leetcode.com/topic/44101/c-easy-solution-using-queue
// Time:	O(1)
// Space:	O(1)
class MovingAverage {
    queue<int> nums;
    int window = 0;
    double avg = 0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        window = size;
    }

    double next(int val) {
        int count = nums.size();
        nums.push(val);
        if (count < window) {
            count++;
            avg = (count - 1) * 1.0 / count * avg + val * 1.0 / count;
        } else {
            int head = nums.front();
            nums.pop();
            avg += (val - head) * 1.0 / count;
        }
        return avg;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */