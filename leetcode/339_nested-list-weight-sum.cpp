//Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
//
//Each element is either an integer, or a list -- whose elements may also be integers or other lists.
//
//Example 1:
//Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at depth 1)
//
//Example 2:
//Given the list [1,[4,[6]]], return 27. (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27)

#include <iostream>
#include <vector>
#include <queue>

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
class Solution_339 {
public:
    // BFS (My own)
    // Time:	O(n)
    // Space:	O(n)
    int depthSum(vector<NestedInteger>& nestedList) {
        if (nestedList.empty()) return 0;
        int result(0), level(0);
        queue<const NestedInteger*> que;
        for (auto& obj : nestedList) que.push(&obj);
        while (!que.empty()) {
            int size = que.size();
            level++;
            while (size-- > 0) {
                const NestedInteger* node = que.front();
                que.pop();
                if (node->isInteger()) result += level * node->getInteger();
                else
                    for (auto& obj : node->getList()) que.push(&obj);
            }
        }
        return result;
    }




    // Preorder
    // Time:	O(n)
    // Space:	O(1)
    int depthSum1(vector<NestedInteger>& nestedList) {
        return subSum(nestedList, 1);
    }

    int subSum(const vector<NestedInteger>& nestedList, int level) {
        int result = 0;
        for (auto& obj : nestedList)
            result += obj.isInteger() ? obj.getInteger() * level : subSum(obj.getList(), level + 1);
        return result;
    }
};