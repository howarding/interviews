//You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
//
//The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.
//
//Example 1:
//    Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
//    Output: [-1,3,-1]
//    Explanation:
//    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
//    For number 1 in the first array, the next greater number for it in the second array is 3.
//    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
//Example 2:
//    Input: nums1 = [2,4], nums2 = [1,2,3,4].
//    Output: [3,-1]
//    Explanation:
//    For number 2 in the first array, the next greater number for it in the second array is 3.
//    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
//Note:
//    1. All elements in nums1 and nums2 are unique.
//    2. The length of both nums1 and nums2 would not exceed 1000.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution_496 {
public:
    // Stack + Hashmap
    // Exp: https://leetcode.com/problems/next-greater-element-i/solution/
    // Time:	O(n)
    // Space:	O(n)
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> stk;
        unordered_map<int, int> dict;
        vector<int> result;
        for (int num : nums) {
            while (!stk.empty() && num > stk.top()) {
                dict[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }
        while (!stk.empty()) {
            dict[stk.top()] = -1;
            stk.pop();
        }
        for (int num : findNums)
            result.push_back(dict[num]);
        return result;
    }



    // Hashmap
    // Exp: https://leetcode.com/problems/next-greater-element-i/solution/
    // Time:	O(mn)
    // Space:	O(n)
    vector<int> nextGreaterElement1(vector<int>& findNums, vector<int>& nums) {
        vector<int> result(findNums.size(), 0);
        unordered_map<int, int> dict;
        for (int i = 0; i < nums.size(); i++)
            dict[nums[i]] = i;
        int j;
        for (int i = 0; i < findNums.size(); i++) {
            for (j = dict[findNums[i]]; j < nums.size(); j++)
                if (findNums[i] < nums[j]) {
                    result[i] = nums[j];
                    break;
                }
            if (j == nums.size()) result[i] = -1;
        }
        return result;
    }
};