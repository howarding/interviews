#include <iostream>
#include <stack>

using namespace std;


// BEST
// Time:	O(1)
// Space:	O(n)
class MinStack_1 {
    stack<long> offsets;
    long min_num;
public:
    /** initialize your data structure here. */
    MinStack_1() {
    }

    void push(int x) {
        if (offsets.empty()) {
            min_num = x;
            offsets.push(0L);
        } else {
            offsets.push(x - min_num);
            if (x < min_num)
                min_num = x;
        }
    }

    void pop() {
        if (offsets.top() < 0)
            min_num -= offsets.top();
        offsets.pop();
    }

    int top() {
        long offset = offsets.top();
        return offset > 0 ? offset + min_num : min_num;
    }

    int getMin() {
        return min_num;
    }
};