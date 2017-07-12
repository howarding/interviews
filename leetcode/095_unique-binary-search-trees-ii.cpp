//Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
//
//For example,
//Given n = 3, your program should return all 5 unique BST's shown below.
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3

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
class Solution_095 {
public:
    // Backtracking (My own)
    // Time:	O(2^n)
    // Space:	O(2^n)
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) return vector<TreeNode*>();
        return generateSubTrees(1, n);
    }

    vector<TreeNode*> generateSubTrees(int left_val, int right_val) {
        vector<TreeNode*> result;
        if (left_val == right_val) {
            result.push_back(new TreeNode(left_val));
            return result;
        }
        for (TreeNode* right : generateSubTrees(left_val + 1, right_val)) {
            TreeNode* root = new TreeNode(left_val);
            root->right = right;
            result.push_back(root);
        }
        for (int i = left_val + 1; i < right_val; i++)
            for (TreeNode* left : generateSubTrees(left_val, i - 1))
                for (TreeNode* right : generateSubTrees(i + 1, right_val)) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
        for (TreeNode* left : generateSubTrees(left_val, right_val - 1)) {
            TreeNode* root = new TreeNode(right_val);
            root->left = left;
            result.push_back(root);
        }
        return result;
    }
};