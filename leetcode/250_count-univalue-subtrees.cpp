//Given a binary tree, count the number of uni-value subtrees.
//
//A Uni-value subtree means all nodes of the subtree have the same value.
//
//For example:
//Given binary tree,
//              5
//             / \
//            1   5
//           / \   \
//          5   5   5
//return 4.

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
class Solution_250 {
public:
    // PostOrder, Recursive (My own)
    // Time:	O(n)
    // Space:	O(1)
    int countUnivalSubtrees(TreeNode* root) {
        int result = 0;
        if (!root) return result;
        univalSubtrees(root, result);
        return result;
    }

    bool univalSubtrees(TreeNode* node, int& result) {
        if(!node->left && !node->right) {
            result++;
            return true;
        }

        bool res = true;
        if (node->left)
            res &= univalSubtrees(node->left, result) && node->val == node->left->val;
        if (node->right)
            res &= univalSubtrees(node->right, result) && node->val == node->right->val;
        if (res) result++;
        return res;
    }
};