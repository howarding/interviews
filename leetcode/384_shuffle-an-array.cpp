//Shuffle a set of numbers without duplicates.
//
//Example:
//
//    // Init an array with set 1, 2, and 3.
//    int[] nums = {1,2,3};
//    Solution solution = new Solution(nums);
//
//    // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
//    solution.shuffle();
//
//    // Resets the array back to its original configuration [1,2,3].
//    solution.reset();
//
//    // Returns the random shuffling of array [1,2,3].
//    solution.shuffle();

#include <iostream>
#include <vector>

using namespace std;

class Solution_384 {
    vector<int> numbers;
public:
    Solution_384(vector<int> nums) {
        numbers = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return numbers;
    }

    // Fisher–Yates shuffle Algorithm
    // Exp: http://www.geeksforgeeks.org/shuffle-a-given-array/
    // Time:	O(n)
    // Space:	O(1)
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result(numbers);
        for (int i = result.size() - 1; i > 0; i--)
            swap(result[i], result[rand() % (i + 1)]);
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */