//Design a Phone Directory which supports the following operations:
//
//    1. get: Provide a number which is not assigned to anyone.
//    2. check: Check if a number is available or not.
//    3. release: Recycle or release a number.
//
//Example:
//
//    // Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
//    PhoneDirectory directory = new PhoneDirectory(3);
//
//    // It can return any available phone number. Here we assume it returns 0.
//    directory.get();
//
//    // Assume it returns 1.
//    directory.get();
//
//    // The number 2 is available, so return true.
//    directory.check(2);
//
//    // It returns 2, the only number that is left.
//    directory.get();
//
//    // The number 2 is no longer available, so return false.
//    directory.check(2);
//
//    // Release number 2 back to the pool.
//    directory.release(2);
//
//    // Number 2 is available again, return true.
//    directory.check(2);

#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

class PhoneDirectory {
public:
    // Exp: https://discuss.leetcode.com/topic/53094/java-ac-solution-using-queue-and-set
    // Time:	O(1)
    // Space:	O(n)
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        max = maxNumbers;
        for (int i = 0; i < max; i++)
            available.push(i);
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (available.empty()) return -1;
        int result = available.front();
        available.pop();
        used.insert(result);
        return result;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        if (number >= max || number < 0)
            return false;
        return used.find(number) == used.end();
    }

    /** Recycle or release a number. */
    void release(int number) {
        if (used.find(number) != used.end()) {
            used.erase(number);
            available.push(number);
        }
    }

private:
    unordered_set<int> used;
    queue<int> available;
    int max;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */