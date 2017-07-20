//Invert a binary tree.
//
//         4
//       /   \
//      2     7
//     / \   / \
//    1   3 6   9
//to
//         4
//       /   \
//      7     2
//     / \   / \
//    9   6 3   1
//Trivia:
//This problem was inspired by this original tweet by Max Howell:
//Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.

#include <iostream>
#include <stack>
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
class Solution_226 {
public:
    // Recursive (My own)
    // Time:	O(n)
    // Space:	O(1)
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }


    // Iterative, stack (My own)
    // Time:	O(n)
    // Space:	O(n)
    TreeNode* invertTree1(TreeNode* root) {
        if (!root) return root;
        stack<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode* node = nodes.top();
            nodes.pop();
            swap(node->left, node->right);
            if (node->left) nodes.push(node->left);
            if (node->right) nodes.push(node->right);
        }
        return root;
    }



    // BFS, queue (My own)
    // Time:	O(n)
    // Space:	O(n)
    TreeNode* invertTree2(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
            swap(node->left, node->right);
        }
        return root;
    }
};