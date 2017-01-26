//Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
//
//For example,
//Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
//
//    Window position                Max
//    ---------------               -----
//    [1  3  -1] -3  5  3  6  7       3
//    1 [3  -1  -3] 5  3  6  7       3
//    1  3 [-1  -3  5] 3  6  7       5
//    1  3  -1 [-3  5  3] 6  7       5
//    1  3  -1  -3 [5  3  6] 7       6
//    1  3  -1  -3  5 [3  6  7]      7
//Therefore, return the max sliding window as [3,3,5,5,6,7].
//
//Note:
//    You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.
//
//Follow up:
//Could you solve it in linear time?
//
//Hint:
//
//    1. How about using a data structure such as deque (double-ended queue)?
//    2. The queue size need not be the same as the window’s size.
//    3. Remove redundant elements and the queue should store only elements that need to be considered.

#include <iostream>
#include <vector>

using namespace std;

class Solution_239 {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {

    }
};