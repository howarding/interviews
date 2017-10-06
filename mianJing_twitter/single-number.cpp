//Given an array of integers, every element appears twice except for one. Find that single one.
//
//Note:
//    Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution_sn {
public:
    // xor, BEST
    // Time:	O(n)
    // Space:	O(1)
    int singleNumber(vector<int> &nums) {
        int result = 0;
        for (int num : nums)
            result ^= num;
        return result;
    }


    // HashSet
    // Time:	O(n)
    // Space:	O(n)
    int singleNumber1(vector<int> &nums) {
        unordered_set<int> singles;
        for (int num : nums) {
            if (singles.find(num) != singles.end())
                singles.erase(num);
            else singles.insert(num);
        }
        return *singles.begin();
    }


    // multiple odd count integers
    // HashSet
    // Time:	O(n)
    // Space:	O(n)
    vector<int> singleNumbers(vector<int> &nums) {
        unordered_set<int> singles;
        for (int num : nums) {
            if (singles.find(num) != singles.end())
                singles.erase(num);
            else singles.insert(num);
        }
        return vector<int>(singles.begin(), singles.end());
    }
};