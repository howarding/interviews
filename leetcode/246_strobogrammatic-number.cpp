//A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
//
//Write a function to determine if a number is strobogrammatic. The number is represented as a string.
//
//For example, the numbers "69", "88", and "818" are all strobogrammatic.

#include <iostream>
#include <map>

using namespace std;

class Solution_246 {
public:
    // Exp: https://discuss.leetcode.com/topic/20809/0ms-c-solution
    // Time:	O(n)
    // Space:	O(1)
    bool isStrobogrammatic(string num) {
        map<char, char> num_map{{'1', '1'},
                                {'6', '9'},
                                {'9', '6'},
                                {'8', '8'},
                                {'0', '0'}};
        for (int i = 0; i < (num.size() + 1) / 2; i++)
            if (num_map.find(num[i]) == num_map.end() || num_map[num[i]] != num[num.size() - 1 - i])
                return false;
        return true;
    }
};