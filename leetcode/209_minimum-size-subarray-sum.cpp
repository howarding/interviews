//Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
//
//For example, given the array [2,3,1,2,4,3] and s = 7,
//the subarray [4,3] has the minimal length under the problem constraint.
//
//click to show more practice.
//
//More practice:
//If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

#include <iostream>
#include <vector>

using namespace std;

class Solution_209 {
public:
    // 2 Pointers
    // Exp: https://discuss.leetcode.com/topic/18583/accepted-clean-java-o-n-solution-two-pointers
    // Time:	O(n)
    // Space:	O(1)
    int minSubArrayLen(int s, vector<int> &nums) {
        int total = 0, start = 0, result = nums.size() + 1;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
            while (total >= s) {
                result = min(result, i - start + 1);
                total -= nums[start++];
            }
        }
        return result > nums.size() ? 0 : result;
    }


    // Binary Search
    // Exp: https://discuss.leetcode.com/topic/13749/two-ac-solutions-in-java-with-time-complexity-of-n-and-nlogn-with-explanation
    // Time:	O(n * log(n))
    // Space:	O(n)
    int minSubArrayLen_1(int s, vector<int> &nums) {
        vector<int> sums(nums.size() + 1, 0);
        for (int i = 1; i < sums.size(); i++)
            sums[i] += sums[i - 1] + nums[i - 1];

        int result = INT_MAX;
        for (int i = 0; i < sums.size() - 1; i++) {
            int left = i, right = sums.size() - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                int diff = sums[mid] - sums[i];
                if (diff == s) {
                    left = mid;
                    break;
                }
                if (diff > s) right = mid - 1;
                else left = mid + 1;
            }
            if (left < sums.size())
                result = min(result, left - i);
        }
        return result == INT_MAX ? 0 : result;
    }
};


//int main() {
//    vector<int> nums({1, 2, 3, 4, 5});
//    int s = 11;
//    Solution_209 sol;
//    cout << sol.minSubArrayLen_1(s, nums) << endl;
//}