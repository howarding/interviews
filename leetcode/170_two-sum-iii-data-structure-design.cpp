//Design and implement a TwoSum class. It should support the following operations: add and find.
//
//add - Add the number to an internal data structure.
//find - Find if there exists any pair of numbers which sum is equal to the value.
//
//Example 1:
//
//add(1); add(3); add(5);
//find(4) -> true
//find(7) -> false
//Example 2:
//
//add(3); add(1); add(2);
//find(3) -> true
//find(6) -> false

#include <iostream>
#include <set>
#include <map>

using namespace std;

class TwoSum {

    // 1. BEST: More add, less find
    // Time:    O(n)
    // Space:   O(n)
    map<int, int> nums;
public:

    // Add the number to an internal data structure.
    // Time:    O(1)
    // Space:   O(n)
    void add(int number) {
        nums[number]++;
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    // Time:    O(n)
    // Space:   O(1)
    bool find(int value) {
        for (auto& i : nums) {
            int num = i.first;
            int remain = value - num;
            if (nums.find(remain) != nums.end())
                if (remain != num || nums[num] > 1)
                    return true;
        }
        return false;
    }

    // 2. Less add, more find
    // Time:    O(n)
    // Space:   O(n)
private:
    set<int> sums;
    set<int> numbers;
public:

    /** Add the number to an internal data structure. */
    // Time:    O(n)
    // Space:   O(n)
    void add2(int number) {
        for (int num: numbers) {
            sums.insert(number + num);
        }
        numbers.insert(number);
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    // Time:    O(1)
    // Space:   O(1)
    bool find2(int value) {
        return sums.find(value) != sums.end();
    }
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);