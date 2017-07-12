//Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    // PreOrder (My own)
    // Exp: https://discuss.leetcode.com/topic/8141/share-my-o-1-space-and-o-n-time-java-code
    // Time:	O(n)
    // Space:	O(n)
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        int count = 0;
        ListNode* node = head;
        while (node) {
            count++;
            node =node->next;
        }
        node = head;
        return inOrder(node, 0, count-1);
    }

    TreeNode* inOrder(ListNode* &node, int start, int end) {
        if (start > end) return nullptr;
        int mid = (start + end) / 2;
        TreeNode* left = inOrder(node, start, mid - 1);
        TreeNode* result = new TreeNode(node->val);
        result->left = left;
        node = node->next;
        result->right = inOrder(node, mid + 1, end);
        return result;
    }
};