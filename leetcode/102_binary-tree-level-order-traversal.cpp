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
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution_102 {
public:
    //Level Order
    // Time:	O(n)
    // Space:	O(1)
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if (root) que.push(root);
        while (!que.empty()) {
            int num = que.size();
            vector<int> level;
            while (num-- > 0) {
                TreeNode *p = que.front();
                level.push_back(p->val);
                que.pop();
                if (p->left) que.push(p->left);
                if (p->right) que.push(p->right);
            }
            result.push_back(level);
        }
        return result;
    }

    // 只输出从root到该节点path sum为偶数的节点
    // Time:	O(n)
    // Space:	O(1)
    vector<vector<int>> levelOrder_fu_bb(TreeNode *root) {
        vector<vector<int>> result;
        queue<pair<TreeNode*, int>> que;
        if (root) que.push({root, root->val % 2});
        while (!que.empty()) {
            int num = que.size();
            vector<int> level;
            while (num-- > 0) {
                auto& node = que.front();
                if (node.second == 0) level.push_back(node.first->val);
                que.pop();
                if (node.first->left)
                    que.push({node.first->left, (node.second + node.first->left->val) % 2});
                if (node.first->right)
                    que.push({node.first->right, (node.second + node.first->right->val) % 2});
            }
            result.push_back(level);
        }
        return result;
    }

    // Follow Up 2: 把从root 到node的path sum 改为node 的k - 1个parent 和node的sum.
    // A: 把原来的bool改成一个size为k的list，不断地pop_front 和push_back当前节点奇偶性。按level order输出node，同时满足sum为偶数
    // 条件; 用count记录从root到node遇到的奇数node的个数，当且仅当count为偶数的时候，sum就是偶数.
};