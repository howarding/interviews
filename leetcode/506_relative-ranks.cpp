//Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
//
//Example 1:
//    Input: [5, 4, 3, 2, 1]
//    Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
//    Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal".
//    For the left two athletes, you just need to output their relative ranks according to their scores.
//Note:
//    1. N is a positive integer and won't exceed 10,000.
//    2. All the scores of athletes are guaranteed to be unique.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_506 {
public:
    // Exp: 1 vector & 1 map
    // Time:	O(nlogn)
    // Space:	O(n)
    vector<string> findRelativeRanks(vector<int> &nums) {
        vector<string> result;
        if (nums.empty()) return result;
        vector<int> cpy = nums;
        sort(cpy.begin(), cpy.end(), cmp);
        unordered_map<int, string> rank;
        for (int i = 0; i < cpy.size(); i++)
            switch (i) {
                case 0 :
                    rank[cpy[i]] = "Gold Medal";
                    break;
                case 1 :
                    rank[cpy[i]] = "Silver Medal";
                    break;
                case 2 :
                    rank[cpy[i]] = "Bronze Medal";
                    break;
                default:
                    rank[cpy[i]] = to_string(i + 1);
                    break;
            }
        for (int num: nums)
            result.push_back(rank[num]);
        return result;
    }

    static bool cmp(int a, int b) {
        return a > b;
    }


    // Exp: https://discuss.leetcode.com/topic/77876/easy-java-solution-sorting
    // Time:	O(nlog(n))  faster
    // Space:	O(n)
    vector<string> findRelativeRanks_1(vector<int> &nums) {
        vector<string> result(nums.size());
        if (nums.empty()) return result;
        vector<vector<int>> rank;
        for (int i = 0; i < nums.size(); i++)
            rank.push_back({i, nums[i]});
        sort(rank.begin(), rank.end(), cmp2);
        for (int i = 0; i < nums.size(); i++)
            switch (i) {
                case 0 :
                    result[rank[i][0]] = "Gold Medal";
                    break;
                case 1 :
                    result[rank[i][0]] = "Silver Medal";
                    break;
                case 2 :
                    result[rank[i][0]] = "Bronze Medal";
                    break;
                default:
                    result[rank[i][0]] = to_string(i + 1);
                    break;
            }
        return result;
    }

    static bool cmp2(vector<int> &a, vector<int> &b) {
        return a[1] > b[1];
    }
};