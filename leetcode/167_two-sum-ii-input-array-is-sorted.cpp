//Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
//
//The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
//
//You may assume that each input would have exactly one solution.
//
//Input: numbers={2, 7, 11, 15}, target=9
//Output: index1=1, index2=2

#include <iostream>
#include <vector>

using namespace std;

class Solution_167 {
public:
    // Exp: https://leetcode.com/articles/two-sum-ii-input-array-sorted/
    // Time:	O(n)
    // Space:	O(1)
    vector<int> twoSum(vector<int> &numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (target == sum)
                return {left + 1, right + 1};
            if (target < sum)
                right--;
            else
                left++;
        }
        return {-1, -1};
    }
};