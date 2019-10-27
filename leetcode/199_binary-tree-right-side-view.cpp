//Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
//
//For example:
//Given the following binary tree,
//   1            <---
// /   \
//2     3         <---
// \     \
//  5     4       <---
//You should return [1, 3, 4].

#include <iostream>
#include <vector>
#include <queue>

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
    // BFS
    // Time:	O(n)
    // Space:	O(1)
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            int count = nodes.size();
            while (count) {
                TreeNode* node = nodes.front();
                nodes.pop();
                if (count-- == 1) result.push_back(node->val);
                if (node->left) nodes.push(node->left);
                if (node->right) nodes.push(node->right);
            }
        }
        return result;
    }



    // DFS, PreOrder (reverse)
    // Exp: https://discuss.leetcode.com/topic/11768/my-simple-accepted-solution-java
    // Time:	O(n)
    // Space:	O(1)
    vector<int> rightSideView1(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        helper(root, 0, result);
        return result;
    }

    void helper(TreeNode* node, int depth, vector<int>& result) {
        if (depth == result.size())
            result.push_back(node->val);

        if (node->right) helper(node->right, depth+1, result);
        if (node->left) helper(node->left, depth+1, result);
    }
};