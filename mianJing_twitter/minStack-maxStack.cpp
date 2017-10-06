//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//    push(x) -- Push element x onto stack.
//    pop() -- Removes the element on top of the stack.
//    top() -- Get the top element.
//    getMin() -- Retrieve the minimum element in the stack.
//Example:
//    MinStack minStack = new MinStack();
//    minStack.push(-2);
//    minStack.push(0);
//    minStack.push(-3);
//    minStack.getMin();   --> Returns -3.
//    minStack.pop();
//    minStack.top();      --> Returns 0.
//    minStack.getMin();   --> Returns -2.

#include <iostream>
#include <stack>

using namespace std;

// 1 stack
// Time:	O(1)
// Space:	O(n)
class MinStack {
    stack<long> offsets;
    long min_num;
public:
    /** initialize your data structure here. */
    MinStack() {
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


// 2 stacks
// Time:	O(1)
// Space:	O(n)
class MinStack1 {
    stack<int> nums, mins;
public:
    /** initialize your data structure here. */
    MinStack1() {

    }

    void push(int x) {
        nums.push(x);
        mins.push(mins.empty() ? x : min(mins.top(), x));
    }

    void pop() {
        nums.pop();
        mins.pop();
    }

    int top() {
        return nums.top();
    }

    int getMin() {
        return mins.top();
    }
};



class MaxStack {
    stack<long> offsets;
    long max_num;
public:
    /** initialize your data structure here. */
    MaxStack() {
    }

    void push(int x) {
        if (offsets.empty()) {
            max_num = x;
            offsets.push(0L);
        } else {
            offsets.push(x - max_num);
            if (x > max_num)
                max_num = x;
        }
    }

    void pop() {
        if (offsets.top() > 0)
            max_num -= offsets.top();
        offsets.pop();
    }

    int top() {
        long offset = offsets.top();
        return offset < 0 ? offset + max_num : max_num;
    }

    int getMin() {
        return max_num;
    }
};