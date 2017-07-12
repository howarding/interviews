//Given two binary trees, write a function to check if they are equal or not.
//
//Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

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
class Solution_100 {
public:
    // DFS, faster
    // Exp: https://discuss.leetcode.com/topic/4737/five-line-java-solution-with-recursion
    // Time:	O(n)
    // Space:	O(1)
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) return p == q;
        return (p->val == q->val) ? isSameTree(p->left, q->left) && isSameTree(p->right, q->right) : false;
    }



    // DFS (My own)
    // Time:	O(n)
    // Space:	O(n)
    bool isSameTree1(TreeNode* p, TreeNode* q) {
        vector<int> preOrder_p, preOrder_q;
        preOrder(p, preOrder_p);
        preOrder(q, preOrder_q);
        if (preOrder_p.size() != preOrder_q.size()) return false;
        for (int i = 0; i < preOrder_p.size(); i++)
            if (preOrder_p[i] != preOrder_q[i]) return false;
        return true;
    }

    void preOrder(TreeNode* root, vector<int>& result) {
        if (!root) {
            result.push_back(0);
            result.push_back(0);
            return;
        }
        result.push_back(1);
        result.push_back(root->val);
        preOrder(root->left, result);
        preOrder(root->right, result);
    }
};