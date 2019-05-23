//Given a sorted integer array without duplicates, return the summary of its ranges.
//
//For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution_228 {
public:
    // Sim to LC163: Missing Ranges
    // Exp: https://discuss.leetcode.com/topic/17117/10-line-c-easy-understand/4
    // Time:	O(n)
    // Space:	O(1)
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) return result;
        int start = nums[0], end = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1] + 1) end++;
            else {
                result.push_back(getRange(start, end));
                start = end = nums[i];
            }
        }
        result.push_back(getRange(start, end));
        return result;
    }

    string getRange(int start, int end) {
        return start == end ? to_string(end) : to_string(start) + "->" + to_string(end);
    }
};