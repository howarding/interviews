//Design and implement a TwoSum class. It should support the following operations: add and find.
//
//add - Add the number to an internal data structure.
//find - Find if there exists any pair of numbers which sum is equal to the value.
//
//For example,
//    add(1); add(3); add(5);
//find(4) -> true
//find(7) -> false

#include <iostream>
#include <set>
#include <map>

using namespace std;

class TwoSum {
    map<int, int> nums;
public:

    // Add the number to an internal data structure.
    void add(int number) {
        nums[number]++;
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        for (auto &i : nums) {
            int num = i.first;
            int remain = value - num;
            if (nums.find(remain) != nums.end())
                if (remain != num || nums[num] > 1)
                    return true;
        }
        return false;
    }
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);