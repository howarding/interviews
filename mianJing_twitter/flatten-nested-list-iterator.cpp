//Given a nested list of integers, implement an iterator to flatten it.
//
//Each element is either an integer, or a list -- whose elements may also be integers or other lists.
//
//Example 1:
//Given the list [[1,1],2,[1,1]],
//
//By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
//
//Example 2:
//Given the list [1,[4,[6]]],
//
//By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class NestedInteger {
public:
// Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
// Exp: https://discuss.leetcode.com/topic/42042/simple-java-solution-using-a-stack-with-explanation/18
// Time:
// Space:
class NestedIterator {
    stack<NestedInteger> sta;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--)
            sta.push(nestedList[i]);
    }

    int next() {
        auto val = sta.top().getInteger();
        sta.pop();
        return val;
    }

    bool hasNext() {
        // Iterative PreOrder
        while (!sta.empty()) {
            auto ele = sta.top();
            if (ele.isInteger())
                return true;
            sta.pop();
            for (int i = ele.getList().size() - 1; i >= 0; i--)
                if (ele.getList()[i].isInteger() || ele.getList()[i].getList().size())
                    sta.push(ele.getList()[i]);
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */