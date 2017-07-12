//Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
//
//For example:
//Given the below binary tree and sum = 22,
//              5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1
//return
//    [
//        [5,4,11,2],
//        [5,8,4,5]
//    ]

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
class Solution_113 {
public:
    // Backtracking (My own)
    // Time:	O(n)
    // Space:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if (!root) return result;
        vector<int> path;
        helper(root, sum, path, result);
        return result;
    }

    void helper(TreeNode* node, int sum, vector<int>& path, vector<vector<int>>& result) {
        sum -= node->val;
        path.push_back(node->val);
        if (!node->left && !node->right && !sum) result.push_back(path);
        if (node->left) helper(node->left, sum, path, result);
        if (node->right) helper(node->right, sum, path, result);
        path.pop_back();
    }
};