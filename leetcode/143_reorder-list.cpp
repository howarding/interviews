//Given a singly linked list L: L0?L1?…?Ln-1?Ln,
//reorder it to: L0?Ln?L1?Ln-1?L2?Ln-2?…
//
//You must do this in-place without altering the nodes' values.
//
//For example,
//Given {1,2,3,4}, reorder it to {1,4,2,3}.

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
class Solution_143 {
public:
    // Exp: https://discuss.leetcode.com/topic/7425/a-concise-o-n-time-o-1-in-place-solution
    // Time:	O(n)
    // Space:	O(1)
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *mid(dummy), *end(dummy);
        while (end->next) {
            mid = mid->next;
            end = end->next;
            if (end->next) end = end->next;
        }

        ListNode* head2 = mid->next;
        mid->next = nullptr;

        ListNode* pre = nullptr;
        while (head2) {
            ListNode* tmp = head2->next;
            head2->next = pre;
            pre = head2;
            head2 = tmp;
        }

        ListNode* start = head;
        while (end) {
            ListNode *tmp1 = start->next, *tmp2 = end->next;
            start->next = end;
            start = end->next = tmp1;
            end = tmp2;
        }
    }
};