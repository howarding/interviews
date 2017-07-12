//Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
//
//An example is the root-to-leaf path 1->2->3 which represents the number 123.
//
//Find the total sum of all root-to-leaf numbers.
//
//For example,
//
//    1
//   / \
//  2   3
//The root-to-leaf path 1->2 represents the number 12.
//The root-to-leaf path 1->3 represents the number 13.
//
//Return the sum = 12 + 13 = 25.

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
class Solution_129 {
public:
    // DFS (My own)
    // Time:	O(n)
    // Space:	O(1)
    int sumNumbers(TreeNode* root) {
        return pathSum(root, 0);
    }

    int pathSum(TreeNode* node, int total) {
        if (!node) return 0;
        total = total * 10 + node->val;
        if (!node->left && !node->right) return total;
        return pathSum(node->left, total) + pathSum(node->right, total);
    }
};