//Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.
//
//Example 1:
//Input:
//      1
//     / \
//    0   2
//
//    L = 1
//    R = 2
//
//    Output:
//    1
//     \
//      2
//Example 2:
//    Input:
//      3
//     / \
//    0   4
//     \
//      2
//     /
//    1
//
//    L = 1
//    R = 3
//
//    Output:
//        3
//       /
//      2
//     /
//    1

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
class Solution_669 {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return root;
        if (root->val <= R && root->val >= L) {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;
        }
        if (root->val < L) return trimBST(root->right, L, R);
        return trimBST(root->left, L, R);
    }
};