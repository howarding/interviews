//Given a list of non negative integers, arrange them such that they form the largest number.
//
//For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
//
//Note: The result may be very large, so you need to return a string instead of an integer.

#include <iostream>
#include <vector>

using namespace std;

class Solution_179 {
public:
    // Sort w/ right COMPARATOR!!!
    // Exp: https://discuss.leetcode.com/topic/7286/a-simple-c-solution
    // Time:	O(nlog(n))
    // Space:	O(n)
    string largestNumber(vector<int>& nums) {
        string result;
        if (nums.empty()) return result;
        vector<string> array;
        for (int num: nums)
            array.push_back(to_string(num));
        sort(array.begin(), array.end(), compare);
        for (string& num : array)
            result.append(num);
        while(result[0] == '0' && result.size() > 1)
            result.erase(0,1);
        return result;
    }

    static bool compare(string& a, string& b) {
        return a + b > b + a;
    }

};