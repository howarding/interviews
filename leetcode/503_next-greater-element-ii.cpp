//Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.
//
//Example 1:
//    Input: [1,2,1]
//    Output: [2,-1,2]
//    Explanation: The first 1's next greater number is 2;
//    The number 2 can't find next greater number;
//    The second 1's next greater number needs to search circularly, which is also 2.
//Note: The length of given array won't exceed 10000.

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution_503 {
public:
    // Stack
    // Exp: https://discuss.leetcode.com/topic/77923/java-10-lines-and-c-12-lines-linear-time-complexity-o-n-with-explanation
    // Time:	O(n)
    // Space:	O(n)
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        if (nums.size() <= 1) return result;
        stack<int> stk;
        for (int i = 0; i < n * 2; i++) {
            int ind = i % n;
            while (!stk.empty() && nums[stk.top()] < nums[ind]) {
                result[stk.top()] = nums[ind];
                stk.pop();
            }
            stk.push(ind);
        }
        return result;
    }



    // Time:	O(mn)
    // Space:	O(n)
    vector<int> nextGreaterElements1(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        if (nums.size() <= 1) return result;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (nums[(i+j) % n] > nums[i]) {
                    result[i] = nums[(i+j) % n];
                    break;
                }
        return result;
    }

};