//Sort a linked list in O(n log n) time using constant space complexity.

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
class Solution_148 {
public:
    // MergeSort
    // Exp: http://www.geeksforgeeks.org/merge-sort-for-linked-list/
    // Exp: https://discuss.leetcode.com/topic/18100/java-merge-sort-solution
    // Time:	O(nlog(n))
    // Space:	O(1)
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow(head), *fast(head->next);
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* node2(sortList(slow->next));
        slow->next = nullptr;
        ListNode* node1(sortList(head));
        ListNode* result(merge(node1, node2));
        return result;
    }

    ListNode* merge(ListNode* node1, ListNode* node2) {
        ListNode* dummy = new ListNode(-1), *p(dummy);
        while (node1 && node2) {
            if (node1->val < node2->val) {
                p = p->next = node1;
                node1 = node1->next;
            } else {
                p = p->next = node2;
                node2 = node2->next;
            }
        }
        p->next = node1 ? node1 : node2;
        return dummy->next;
    }
};