//Given a binary tree, return all root-to-leaf paths.
//
//For example, given the following binary tree:
//
//       1
//     /   \
//    2     3
//     \
//      5
//All root-to-leaf paths are:
//
//    ["1->2->5", "1->3"]

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
class Solution_257 {
public:
    // Exp: https://discuss.leetcode.com/topic/21447/c-simple-4ms-recursive-solution
    // DFS
    // Time:	O(n)
    // Space:	O(n)
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> result;
        if (!root) return result;
        string path;
        dfs(root, path, result);
        return result;
    }

    void dfs(TreeNode *node, string path, vector<string> &result) {
        path.append((path.empty() ? "" : "->") + to_string(node->val));
        if (!node->left && !node->right) {
            result.push_back(path);
            return;
        }
        if (node->left)
            dfs(node->left, path, result);
        if (node->right)
            dfs(node->right, path, result);
    }
};