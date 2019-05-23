//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
//For example,
//    Given [100, 4, 200, 1, 3, 2],
//    The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
//
//Your algorithm should run in O(n) complexity.

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

class Solution_128 {
public:
    // BEST: unordered_set
    // Exp: https://discuss.leetcode.com/topic/15383/simple-o-n-with-explanation-just-walk-each-streak/41
    // Time:	O(n)
    // Space:	O(n)
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> numbers;
        for (const int& num: nums) numbers.insert(num);
        int result = 0;
        for (int num: numbers) {
            if (numbers.find(num-1) == numbers.end()) {
                int n = num + 1;
                while (numbers.find(n) != numbers.end()) n++;
                result = max(result, n - num);
            }
        }
        return result;
    }


    // SET is sorted
    // Time:	O(n)
    // Space:	O(n)
    int longestConsecutive2(vector<int> &nums) {
        set<int> numbers;
        if (nums.empty()) return 0;
        for (const int& num: nums) numbers.insert(num);
        int result = 0, length = 0;
        for (int num: numbers) {
            length++;
            if (numbers.find(num+1) == numbers.end()) {
                result = max(result, length);
                length = 0;
            }
        }
        return result;
    }
};