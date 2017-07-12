//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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
class Solution_111 {
public:
    // DFS / PostOrder (My own)
    // Time:	O(n)
    // Space:	O(1)
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        return root->left ? root->right ? min(minDepth(root->left), minDepth(root->right)) + 1 : minDepth(root->left) + 1 : minDepth(root->right) + 1;
    }
};