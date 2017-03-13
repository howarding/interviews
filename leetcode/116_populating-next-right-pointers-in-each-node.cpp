//Given a binary tree
//
//    struct TreeLinkNode {
//        TreeLinkNode *left;
//        TreeLinkNode *right;
//        TreeLinkNode *next;
//    }
//    Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//
//Initially, all next pointers are set to NULL.
//
//Note:
//
//    You may only use constant extra space.
//    You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
//For example,
//    Given the following binary tree,
//         1
//       /  \
//      2    3
//     / \  / \
//    4  5  6  7
//After calling your function, the tree should look like:
//         1 -> NULL
//       /  \
//      2 -> 3 -> NULL
//     / \  / \
//    4->5->6->7 -> NULL

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
class Solution_116 {
public:
    // Iterative    faster
    // Exp: https://discuss.leetcode.com/topic/2202/a-simple-accepted-solution
    // Time:    O(n)
    // Space:   O(1)
    void connect1(TreeLinkNode *root) {
        TreeLinkNode *pre = nullptr;
        while (root) {
            TreeLinkNode *start = root;
            while (pre) {
                if (root != pre->left)
                    root->next = pre->left;
                pre->left->next = pre->right;
                root = pre->right;
                pre = pre->next;
            }
            pre = start;
            root = pre->left;
        }
    }


    // DFS
    // Exp: https://discuss.leetcode.com/topic/12241/my-recursive-solution-java
    // Time:    O(n)
    // Space:   O(1)
    void connect(TreeLinkNode *root) {
        if (!root || !root->left) return;
        root->left->next = root->right;
        if (root->next)
            root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
    }
};