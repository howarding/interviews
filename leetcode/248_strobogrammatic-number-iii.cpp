//A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
//
//Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.
//
//Example:
//
//Input: low = "50", high = "100"
//Output: 3
//Explanation: 69, 88, and 96 are three strobogrammatic numbers.
//Note:
//Because the range might be a large number, the low and high numbers are represented as string.

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution_248 {
public:
    // Recursion
    // Exp: https://leetcode.com/problems/strobogrammatic-number-iii/discuss/67378/Concise-Java-Solution
    // Time:	O(n)
    // Space:	O(1)
    int strobogrammaticInRange(string low, string high) {
        unordered_map<char, char> dict{{'1', '1'},
                                       {'6', '9'},
                                       {'9', '6'},
                                       {'8', '8'},
                                       {'0', '0'}};
        int result = 0;
        if (low.empty() || high.empty() || low.size() > high.size())
            return result;
        for (int n = low.size(); n <= high.size(); n++) {
            vector<char> path(n);
            result += helper(dict, n, path, 0, n - 1, low, high);
        }
        return result;
    }

    int helper(unordered_map<char, char>& dict, int n, vector<char>& path, int left, int right, string& low, string& high) {
        if (left > right) {
            string num(path.begin(), path.end());
            if ((num.size() == low.size() && num < low) || (num.size() == high.size() && num > high))
                return 0;
            return 1;
        }

        int result = 0;
        for (auto&& pair: dict) {
            path[left] = pair.first;
            path[right] = pair.second;
            if (left == right && pair.first != pair.second)
                continue;
            if (path.size() > 1 && path[0] == '0')
                continue;
            result += helper(dict, n, path, left+1, right-1, low, high);
        }
        return result;
    }
};