//Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
//Note:
//    You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
//
//Follow up:
//    What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
//
//Hint:
//
//    1. Try to utilize the property of a BST.
//    2. What if you could modify the BST node's structure?
//    3. The optimal runtime complexity is O(height of BST).

#include <iostream>
#include <vector>
#include <stack>

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
class Solution {
public:
    // Exp: https://discuss.leetcode.com/topic/17810/3-ways-implemented-in-java-binary-search-in-order-iterative-recursive
    // in-order recursive
    // Time:	O(n)
    // Space:	O(1)
    int kthSmallest(TreeNode *root, int k) {
        int count = k, val = 0;
        helper(root, count, val);
        return val;
    }

    void helper(TreeNode *node, int &count, int &val) {
        if (!node) return;
        helper(node->left, count, val);
        if (--count == 0) val = node->val;
        helper(node->right, count, val);
    }


    // in-order iterative, stack
    // Time:	O(n)
    // Space:	O(1)
    int kthSmallest_1(TreeNode *root, int k) {
        stack<TreeNode *> stk;
        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top();
                stk.pop();
                if (k-- == 1) return root->val;
                root = root->right;
            }
        }
        return -1;
    }


};