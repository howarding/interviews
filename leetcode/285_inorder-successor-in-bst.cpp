//Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
//
//Note: If the given node has no in-order successor in the tree, return null.

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
    // Iterative
    // Exp: https://discuss.leetcode.com/topic/25698/java-python-solution-o-h-time-and-o-1-space-iterative
    // Time:	O(n)
    // Space:	O(1)
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        TreeNode *suc = NULL;
        while (root) {
            if (root->val > p->val) {
                suc = root;
                root = root->left;
            } else
                root = root->right;
        }
        return suc;
    }
};