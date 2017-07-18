//Given a complete binary tree, count the number of nodes.
//
//Definition of a complete binary tree from Wikipedia:
//In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

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
class Solution_222 {
public:
    // Iterative
    // Exp: https://discuss.leetcode.com/topic/15533/concise-java-solutions-o-log-n-2
    // Time:	O(log(n)^2)
    // Space:	O(1)
    int countNodes(TreeNode* root) {
        int result = 0, height = treeHeight(root);
        while (root) {
            if (treeHeight(root->right) == height - 1) {
                result += 1 << height;
                root = root->right;
            } else {
                result += 1 << (height - 1);
                root = root->left;
            }
            height--;
        }
        return result;
    }

    int treeHeight(TreeNode* node) {
        return node ? 1 + treeHeight(node->left) : -1;
    }



    // Recursive
    // Exp: https://discuss.leetcode.com/topic/15515/easy-short-c-recursive-solution
    // Time:	O(log(n)^2)
    // Space:	O(1)
    int countNodes1(TreeNode* root) {
        int result(0), height_left(0), height_right(0);
        TreeNode *left(root), *right(root);
        while (left) {
            height_left++;
            left = left->left;
        }
        while (right) {
            height_right++;
            right = right->right;
        }
        if (height_left == height_right) return (1 << height_left) - 1;
        return 1 + countNodes1(root->left) + countNodes1(root->right);
    }
};