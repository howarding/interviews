//Given a binary tree, find its maximum depth.
//
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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
class Solution_104 {
public:
    // Exp: DFS
    // Time:	O(h)
    // Space:	O(1)
    int maxDepth(TreeNode *root) {
        return helper(root, 0);
    }

    int helper(TreeNode *node, int count) {
        if (!node) return count;
        return max(helper(node->left, count + 1), helper(node->right, count + 1));
    }

};