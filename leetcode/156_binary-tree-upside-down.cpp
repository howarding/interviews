//Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.
//
//For example:
//Given a binary tree {1,2,3,4,5},
//    1
//   / \
//  2   3
// / \
//4   5
//return the root of the binary tree [4,5,2,#,#,3,1].
//   4
//  / \
// 5   2
//    / \
//   3   1
//confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

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
class Solution_156 {
public:
    // Recursive (My own)
    // Time:	O(n)
    // Space:	O(n)
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root) return nullptr;
        return rootNode(root);
    }

    TreeNode* rootNode(TreeNode* node) {
        if (!node->left) return node;
        TreeNode* root(rootNode(node->left));
        node->left->left = node->right;
        node->left->right = node;
        node->left = node->right = nullptr;
        return root;
    }

    // Iterative
    // Exp: https://discuss.leetcode.com/topic/40924/java-recursive-o-logn-space-and-iterative-solutions-o-1-space-with-explanation-and-figure
    // Time:	O(n)
    // Space:	O(1)
    TreeNode* upsideDownBinaryTree1(TreeNode* root){
        if (!root) return nullptr;
        TreeNode *node(nullptr), *left(root), *right(nullptr);
        while (left) {
            TreeNode* tmp(left->left);
            left->left = right;
            right = left->right;
            left->right = node;
            node = left;
            left = tmp;
        }
        return node;
    };
};


//int main() {
//    Solution_156 sol;
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    sol.upsideDownBinaryTree(root);
//}