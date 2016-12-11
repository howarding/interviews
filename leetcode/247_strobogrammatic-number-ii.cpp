//A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
//
//Find all strobogrammatic numbers that are of length = n.
//
//    For example,
//Given n = 2, return ["11","69","88","96"].
//
//Hint:
//
//    1. Try to use recursion and notice that it should recurse with n - 2 instead of n - 1.

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution_247 {
public:
    // Exp: https://discuss.leetcode.com/topic/20753/ac-clean-java-solution
    // Time:	O(n)
    // Space:	O(n)
    vector<string> findStrobogrammatic(int n) {
        map<char, char> num_map{{'1', '1'},
                                {'6', '9'},
                                {'9', '6'},
                                {'8', '8'},
                                {'0', '0'}};
        return helper(n, n, num_map);
    }

    vector<string> helper(int n, int m, map<char, char> &num_map) {
        if (m == 0) return {""};
        if (m == 1) return {"1", "0", "8"};
        vector<string> strings = helper(n, m - 2, num_map);
        vector<string> result;
        for (auto &s : strings)
            for (auto &&pair : num_map)
                if (m != n || pair.first != '0')
                    result.push_back(pair.first + s + pair.second);
        return result;
    }
};