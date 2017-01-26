//Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
//
//Note:
//    Given target value is a floating point.
//    You are guaranteed to have only one unique value in the BST that is closest to the target.

#include <iostream>
#include <cmath>

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
class Solution_270 {
public:
    // My own method: iterative
    // Time:	O(n)
    // Space:	O(1)
    int closestValue(TreeNode *root, double target) {
        TreeNode *cur = root;
        while (root) {
            if (abs(cur->val - target) > abs(root->val - target))
                cur = root;
            root = root->val > target ? root->left : root->right;
        }
        return cur->val;
    }
};