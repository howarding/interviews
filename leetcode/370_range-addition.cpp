//Assume you have an array of length n initialized with all 0's and are given k update operations.
//
//Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
//
//Return the modified array after all k operations were executed.
//
//Example:
//
//    Given:
//
//length = 5,
//    updates = [
//[1,  3,  2],
//[2,  4,  3],
//[0,  2, -2]
//]
//
//Output:
//
//[-2, 0, 3, 5, 3]
//Explanation:
//
//    Initial state:
//[ 0, 0, 0, 0, 0 ]
//
//After applying operation [1, 3, 2]:
//[ 0, 2, 2, 2, 0 ]
//
//After applying operation [2, 4, 3]:
//[ 0, 2, 5, 5, 3 ]
//
//After applying operation [0, 2, -2]:
//[-2, 0, 3, 5, 3 ]
//Hint:
//
//    Thinking of using advanced data structures? You are thinking it too complicated.
//For each update operation, do you really need to update all elements between i and j?
//Update only the first and end element is sufficient.
//The optimal time complexity is O(k + n) and uses O(1) extra space.

#include <iostream>
#include <vector>

using namespace std;

class Solution_370 {
public:
    // Exp: https://discuss.leetcode.com/topic/49691/java-o-k-n-time-complexity-solution
    // Time:	O(n+k)
    // Space:	O(1)
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        vector<int> result(length, 0);
        if (updates.empty()) return result;
        for (const auto &ele : updates) {
            int start = ele[0];
            int end = ele[1];
            int val = ele[2];
            result[start] += val;
            if (end < length - 1)
                result[end + 1] -= val;
        }
        for (int i = 1; i < length; i++)
            result[i] += result[i - 1];
        return result;
    }
};