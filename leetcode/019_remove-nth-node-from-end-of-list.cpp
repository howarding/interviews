//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//
//   Given linked list: 1->2->3->4->5, and n = 2.
//
//   After removing the second node from the end, the linked list becomes 1->2->3->5.
//Note:
//Given n will always be valid.
//Try to do this in one pass.

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
class Solution_019 {
public:
    // Exp: my own
    // Time:	O(n)
    // Space:	O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !n) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* q = dummy;
        int num = 0;
        for (ListNode* p = head; p; p = p->next)
            if (num++ >= n)
                q = q->next;
        q->next = q->next->next;
        return dummy->next;
    }
};