//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution_108 {
public:
    // PreOrder (My own)
    // Time:	O(n)
    // Space:	O(n)
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        TreeNode* result = helper(nums, 0, nums.size());
        return result;
    }

    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left == right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* result = new TreeNode(nums[mid]);
        result->left = helper(nums, left, mid);
        result->right = helper(nums, mid + 1, right);
        return result;
    }



    // Vector Iterator
    // Time:	O(n)
    // Space:	O(n)
    TreeNode* sortedArrayToBST1(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        TreeNode* result;
        vector<int>::iterator front = nums.begin(), back = nums.end();
        dfs(result, front, back);
        return result;
    }

    void dfs(TreeNode* &p, vector<int>::iterator front, vector<int>::iterator back){
        if(front == back) return;
        vector<int>::iterator mid = front + (back - front) / 2;
        p = new TreeNode(*mid);
        dfs(p->left, front, mid);
        dfs(p->right, mid + 1, back);
    }


};