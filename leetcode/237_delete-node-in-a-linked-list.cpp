//Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
//
//Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution_237 {
public:
    // copy next node
    // Exp: https://discuss.leetcode.com/topic/18752/1-3-lines-c-java-python-c-c-javascript-ruby/15
    // Time:	O(1)
    // Space:	O(1)
    void deleteNode(ListNode *node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};