//Given an array of integers, every element appears twice except for one. Find that single one.
//
//Note:
//    Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution_136 {
public:
    // XOR
    // Exp: https://discuss.leetcode.com/topic/1916/my-o-n-solution-using-xor
    // Time:	O(n)
    // Space:	O(1)
    int singleNumber(vector<int> &nums) {
        int result = 0;
        for (int num : nums)
            result ^= num;
        return result;
    }


    // Hash Table
    // Time:	O(n)
    // Space:	O(n)
    int singleNumber1(vector<int> &nums) {
        unordered_set<int> numbers;
        for (int num : nums)
            if (numbers.find(num) == numbers.end())
                numbers.insert(num);
            else
                numbers.erase(num);
        return *numbers.begin();
    }
};