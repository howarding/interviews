//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//You may not alter the values in the nodes, only nodes itself may be changed.
//
//Only constant memory is allowed.
//
//For example,
//Given this linked list: 1->2->3->4->5
//
//For k = 2, you should return: 2->1->4->3->5
//
//For k = 3, you should return: 3->2->1->4->5

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
class Solution_025 {
public:
    // Best
    // MY OWN: Iterative
    // Reverse k nodes batch by batch
    // Time:	O(n)    2 PASS
    // Space:	O(1)
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1) return head;
        auto* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *start = head, *end = dummy, *p = dummy;
        int i = 0;
        while(end) {
            // Not reached k nodes yet.
            if (i++ < k)
                end = end->next;
            // Got k nodes in a batch
            else {
                ListNode* tmp = end->next;
                // Reverse the k nodes
                reverse(start, end);
                p->next = start;
                start = end->next = tmp;
                p = end;
                i = 0;
            }
        }
        return dummy->next;
    }

    void reverse(ListNode* &start, ListNode* &end) {
        ListNode* pre = nullptr;
        ListNode* p = start;
        ListNode* stop = end->next;
        while (p != stop) {
            ListNode* tmp = p->next;
            p->next = pre;
            pre = p;
            p = tmp;
        }
        swap(start, end);
    }

    // Reverse group by group
    // Time:	O(n)
    // Space:	O(1)
    ListNode *reverseKGroup1(ListNode *head, int k) {
        int count = 0;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        while (head) {
            head = head->next;
            count++;
        }
        int n = count / k;
        head = dummy->next;
        ListNode *pre = nullptr, *group_pre = dummy, *end;
        for (int i = 0; i < n; i++) {
            end = head;
            for (int j = 0; j < k; j++) {
                ListNode *tmp = head->next;
                head->next = pre;
                pre = head;
                head = tmp;
            }
            group_pre->next = pre;
            end->next = head;
            group_pre = end;
        }
        return dummy->next;
    }
};