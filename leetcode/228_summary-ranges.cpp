//Given a sorted integer array without duplicates, return the summary of its ranges.
//
//For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution_228 {
public:
    // Exp: https://discuss.leetcode.com/topic/17117/10-line-c-easy-understand/4
    // Time:	O(n)
    // Space:	O(1)
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> result;
        if (nums.empty()) return result;
        int n = nums.size();
        int i = 1;
        int start = nums[0];
        while (i < n) {
            if (nums[i] > nums[i - 1] + 1) {
                string ele =
                    nums[i - 1] == start ?
                    to_string(start) :
                    to_string(start) + "->" + to_string(nums[i - 1]);
                result.push_back(ele);
                start = nums[i];
            }
            i++;
        }
        string ele = nums[n - 1] == start ? to_string(start) : to_string(start) + "->" + to_string(nums[n - 1]);
        result.push_back(ele);
        return result;
    }
};