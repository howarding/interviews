//Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
//
//The update(i, val) function modifies nums by updating the element at index i to val.
//Example:
//    Given nums = [1, 3, 5]
//
//    sumRange(0, 2) -> 9
//    update(1, 2)
//    sumRange(0, 2) -> 8
//Note:
//    1. The array is only modifiable by the update function.
//    2. You may assume the number of calls to update and sumRange function is distributed evenly.

#include <iostream>
#include <vector>

using namespace std;

struct stNode {
    int low, high, sum;
    stNode *left, *right;
    stNode(int low, int high): low(low), high(high), sum(0), left(nullptr), right(nullptr) {}
};


// Segment Tree (My own)
// Time:
//        NumArray:   O(n)
//        update:     O(log(n))
//        sumRange:   O(log(n))
// Space:	O(n)
class NumArray {
    stNode *root;
    stNode* build(vector<int>& nums, int i, int j) {
        auto node = new stNode(i, j);
        if (i == j - 1)
            node->sum = nums[i];
        else {
            int mid = (node->low + node->high) >> 1;
            node->left = build(nums, i, mid);
            node->right = build(nums, mid, j);
            node->sum = node->left->sum + node->right->sum;
        }
        return node;
    }

    int updateSum(stNode* node, int i, int val) {
        if (i < node->low || i > node->high) return -1;
        if (node->low == node->high - 1)
            return node->sum = val;
        int mid = (node->low + node->high) >> 1;
        return node->sum = (i < mid ?
                           updateSum(node->left, i, val) + node->right->sum :
                           node->left->sum + updateSum(node->right, i, val));
    }

    int getSum(stNode* node, int i, int j) {
        if (i == node->low && j == node->high) return node->sum;
        int mid = (node->low + node->high) >> 1;
        if (i >= mid) return getSum(node->right, i, j);
        if (j <= mid) return getSum(node->left, i, j);
        return getSum(node->left, i, mid) + getSum(node->right, mid, j);
    }

public:
    NumArray(vector<int> nums) {
        if (nums.empty()) return;
        root = build(nums, 0, nums.size());
    }

    void update(int i, int val) {
        updateSum(root, i, val);
    }

    int sumRange(int i, int j) {
        return getSum(root, i ,j+1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */



//int main() {
//    vector<int> nums({9, -8});
//    NumArray obj(nums);
//    obj.update(0, 3);
//    obj.sumRange(1, 1);
//    obj.sumRange(0, 1);
//    obj.update(1, -3);
//    obj.sumRange(0, 1);
//}