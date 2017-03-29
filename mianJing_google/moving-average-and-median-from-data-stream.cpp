//有个input int stream, 要求写一个函数返回最后10个数的平均值
//先问了当数字比较小的时候的，比如说average of last 30 numbers, 当数字数量少于30的时候和大于30的时候，要写出generic 的解法
//follow up 1: Moving Median from Data Stream
//    这个有window size的不能用大小堆，window移动的时候，如何从heap中删除元素。要用QuickSelect
//    follow up 2: 如果数字很多怎么办 - 答：维护一个moving sum，并用list包含窗口里所有的数字
//    follow up 3: 如果相当的多，而且窗口的range很大，大到任何数据结构都装不下，要求in-place
//    答：把所有的数字分成很多组，记录每组的平均值存在一个bucket数组里，每次更新的时候用数组里的值代替实际值，最终结果会是一个估值. 假设一个bucket里边有100个数，我只存他们的平均值。来一个新数字就一加一减，加的是新数字的值，减的是bucket平均值。减到第一百个数的时候切换到下一个bucket均值，同时记录新的bucket均值，循环往复

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

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

    int getMedian() {
        // Quick Select
    }


};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */