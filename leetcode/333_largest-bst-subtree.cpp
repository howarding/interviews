//Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.
//
//Note:
//A subtree must include all of its descendants.
//Here's an example:
//        10
//       / \
//      5  15
//     / \   \
//    1   8   7
//The Largest BST Subtree in this case is the highlighted one.
//The return value is the subtree's size, which is 3.
//Follow up:
//Can you figure out ways to solve it with O(n) time complexity?

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
class Solution_333 {
public:
    // Recursion (My own)
    // Time:	O(n)
    // Space:	O(1)
    int largestBSTSubtree(TreeNode* root) {
        int result = 0, low = 0, high = 0;
        if (!root) return result;
        bstSize(root, low, high, result);
        return result;
    }

    int bstSize(TreeNode* node, int& low, int& high, int& result) {
        if (!node) return 0;
        bool valid = true;
        int left = bstSize(node->left, low, high, result);
        int low_bound = left == 0 ? node->val : low;
        if (left == -1 || (left > 0 && node->val <= high)) valid = false;
        int right = bstSize(node->right, low, high, result);
        int up_bound = right == 0 ? node->val : high;
        if (right == -1 || (right > 0 && node->val >= low)) valid = false;
        low = low_bound;
        high = up_bound;
        int total = valid ? left + right + 1 : -1;
        result = max(result, total);
        return total;
    }
};