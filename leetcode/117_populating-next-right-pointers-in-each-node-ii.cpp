//Follow up for problem "Populating Next Right Pointers in Each Node".
//
//What if the given tree could be any binary tree? Would your previous solution still work?
//
//Note:
//
//    You may only use constant extra space.
//For example,
//    Given the following binary tree,
//         1
//       /  \
//      2    3
//     / \    \
//    4   5    7
//After calling your function, the tree should look like:
//         1 -> NULL
//       /  \
//      2 -> 3 -> NULL
//     / \    \
//    4-> 5 -> 7 -> NULL

#include <iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;

    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution_117 {
public:
    // Iterative    faster
    // Exp: https://discuss.leetcode.com/topic/1106/o-1-space-o-n-complexity-iterative-solution
    // Time:    O(n)
    // Space:   O(1)
    void connect(TreeLinkNode *root) {
        TreeLinkNode *lower = nullptr, *pre = nullptr;
        while (root) {
            if (root->left) {
                if (pre)
                    pre->next = root->left;
                pre = root->left;
                if (!lower)
                    lower = root->left;
            }
            if (root->right) {
                if (pre)
                    pre->next = root->right;
                pre = root->right;
                if (!lower)
                    lower = root->right;
            }
            if (root->next)
                root = root->next;
            else {
                root = lower;
                lower = pre = nullptr;
            }
        }
    }


    // DFS
    // Time:    O(n)
    // Space:   O(1)
    void connect1(TreeLinkNode *root) {
        if (!root) return;
        helper(root, root->left ? root->left : root->right);
    }

    void helper(TreeLinkNode *node, TreeLinkNode *lower_start) {
        while (node && !node->left && !node->right) node = node->next;
        if (!node) return;
        if (node->left && node->right)
            node->left->next = node->right;
        TreeLinkNode *left = node->right ? node->right : node->left;
        if (!lower_start) lower_start = node->left ? node->left : node->right;
        TreeLinkNode *next = node->next;
        while (next && !next->left && !next->right) next = next->next;
        if (next) {
            left->next = next->left ? next->left : next->right;
            helper(next, lower_start);
        } else
            helper(lower_start, lower_start->left ? lower_start->left : lower_start->right);
    }
};