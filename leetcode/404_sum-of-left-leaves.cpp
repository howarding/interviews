//Find the sum of all left leaves in a given binary tree.
//
//Example:
//
//      3
//     / \
//    9  20
//      /  \
//     15   7
//
//    There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

#include <iostream>

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
    // DFS
    // Exp: https://discuss.leetcode.com/topic/60409/3-line-recursive-c-solution-no-need-to-explain
    // Time:	O(n)
    // Space:	O(1)
    int sumOfLeftLeaves(TreeNode *root) {
        return helper(root, 0);
    }

    int helper(TreeNode *node, int isLeft) {
        if (!node) return 0;
        if (!node->left && !node->right)
            return isLeft * node->val;
        return helper(node->left, 1) + helper(node->right, 0);
    }
};