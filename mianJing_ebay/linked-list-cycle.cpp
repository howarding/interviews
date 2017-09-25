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


    // 2 Pointers
    // Time:	O(n)
    // Space:	O(1)
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        ListNode *slow(head), *fast(head);
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode* entry(head);
                while (slow != entry) {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return nullptr;
    }
};