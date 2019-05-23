//Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.
//
//For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution_163 {
public:
    // Exp: https://discuss.leetcode.com/topic/16119/simply-0ms-c-solution
    // Time:	O(n)
    // Space:	O(1)
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        vector<string> result;
        if (nums.empty()) {
            result.push_back(getRange(lower, upper));
            return result;
        }
        int i = 0;
        while (i < nums.size()) {
            if (lower < nums[i])
                result.push_back(getRange(lower, nums[i] - 1));
            if (nums[i] == INT_MAX)
                return result;
            lower = nums[i++] + 1;
        }
        if (lower <= upper) result.push_back(getRange(lower, upper));
        return result;
    }

    string getRange(int start, int end) {
        return start == end ? to_string(start) : to_string(start) + "->" + to_string(end);
    }
};