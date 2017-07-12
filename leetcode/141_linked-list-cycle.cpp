//Given a linked list, determine if it has a cycle in it.
//
//Follow up:
//Can you solve it without using extra space?

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
class Solution {
public:
    // 2 Pointers
    // Exp: https://leetcode.com/articles/linked-list-cycle/
    // Time:	O(n)
    // Space:	O(1)
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode *node1 = head, *node2 = head;
        while (node2) {
            node1 = node1->next;
            node2 = node2->next;
            if (node2) node2 = node2->next;
            if (node1 == node2) return true;
        }
        return false;
    }
};