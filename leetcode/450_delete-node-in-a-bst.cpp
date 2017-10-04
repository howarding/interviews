//Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
//
//Basically, the deletion can be divided into two stages:
//
//    1. Search for a node to remove.
//    2. If the node is found, delete the node.
//Note: Time complexity should be O(height of tree).
//
//Example:
//
//    root = [5,3,6,2,4,null,7]
//    key = 3
//
//        5
//       / \
//      3   6
//     / \   \
//    2   4   7
//
//    Given key to delete is 3. So we find the node with value 3 and delete it.
//
//    One valid answer is [5,4,6,2,null,null,7], shown in the following BST.
//
//        5
//       / \
//      4   6
//     /     \
//    2       7
//
//    Another valid answer is [5,2,6,null,4,null,7].
//
//        5
//       / \
//      2   6
//       \   \
//        4   7

#include <iostream>
#include <vector>

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
    // Recursive
    // Exp: https://discuss.leetcode.com/topic/65792/recursive-easy-to-understand-java-solution
    // Time:	O(log(n))
    // Space:	O(1)
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val < key) root->right = deleteNode(root->right, key);
        else if (root->val > key) root->left = deleteNode(root->left, key);
        else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            TreeNode* node = root->right;
            while (node->left) node = node->left;
            node->left = root->left;
            return root->right;
        }
        return root;
    }


    // Iterative
    // Exp: https://discuss.leetcode.com/topic/67962/iterative-solution-in-java-o-h-time-and-o-1-space
    // Time:	O(log(n))
    // Space:	O(1)
    TreeNode* deleteNode1(TreeNode* root, int key) {
        if (!root) return root;
        TreeNode *parent = nullptr, *node = root;
        while (node && node->val != key) {
            parent = node;
            if (node->val > key) node = node->left;
            else node = node->right;
        }
        if (!parent) return deleteRootNode(node);
        if (parent->left == node) parent->left = deleteRootNode(node);
        else parent->right = deleteRootNode(node);
        return root;
    }

    TreeNode* deleteRootNode(TreeNode* node) {
        if (!node) return node;
        if (!node->left) return node->right;
        if (!node->right) return node->left;
        TreeNode* tmp = node->right;
        while (tmp->left) tmp = tmp->left;
        tmp->left = node->left;
        return node->right;
    }
};